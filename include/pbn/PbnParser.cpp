#include "PbnParser.h"
#include "tokens/EmptyLine.h"
#include "tokens/EscapedLine.h"
#include "tokens/TextLine.h"
#include "Commentary.h"
#include "Tag.h"
#include "utils/strings.h"

#include <memory>
#include <iostream>
#include <optional>

/**
 * This Parser is probably to be replaced with a generated one, something like boost::spirit or Flex-Bison
 */

using namespace tokens;

constexpr std::string_view whiteSpaceCharacters = " \t\n\v\f\r";
constexpr char stringDelimiter = '\"';

std::shared_ptr<SemanticPbnToken> PbnParser::parseToken(std::string &line, std::istream &inputStream, bool startedOnNewLine)
{

    auto firstNonWsCharPosition = line.find_first_not_of(whiteSpaceCharacters);

    // Empty line
    if (firstNonWsCharPosition == std::string::npos)
    {
        line = "";
        return std::make_shared<tokens::EmptyLine>();
    }
    // Escaped line
    if (line[0] == tokens::escapeCharacter)
    {
        auto token = tokens::EscapedLine::create(line);
        line = "";
        return token;
    }
    char firstValidCharacter = line[firstNonWsCharPosition];
    if (firstValidCharacter == '[')
    {
        auto tag = parseTag(line, inputStream, startedOnNewLine);
        line = line;
        return tag;
    }
    else if (firstValidCharacter == ';')
    {
        auto token = std::make_shared<Commentary>(CommentaryFormat::Singleline,
                                                  true,
                                                  line.substr(firstNonWsCharPosition));
        line = "";
        return token;
    }
    else if (firstValidCharacter == '{')
    {
        return parseMultilineComment(line, inputStream, startedOnNewLine);
    }
    else
    {
        auto token = std::make_shared<TextLine>(line);
        line = "";
        return token;
    }
}

std::vector<std::string> PbnParser::getTableValues(std::string &line, std::istream &inputStream)
{

    std::vector<std::string> values;
    if (line.empty() && !getline(inputStream, line))
    {
        return values;
    }
    while (!(line.starts_with('[') || line.empty() || line.starts_with(';')))
    {

        split(line, values);
        if (!getline(inputStream, line))
            break;
    }

    return values;
}

std::shared_ptr<tokens::Tag> PbnParser::parseTag(std::string &line, std::istream &inputStream, bool /* startedOnNewLine */)
{

    // simplified, not all import version are supported, most of them are not used
    std::regex regex1(R";((\s*\[\s*(\w+)\s*"(.*)"\s*\]\s*));");
    std::smatch matches;

    if (!std::regex_search(line, matches, regex1))
    {
        throw std::runtime_error("Invalid tag: " + line);
    }

    std::string tagString = matches[1];
    std::string tagName = matches[2];
    std::string tagContent = matches[3];

    line.erase(0, tagString.length());

    std::shared_ptr<tokens::Tag> tag;

    if (tagFactory.isTableTag(tagName))
    {
        std::vector<std::string> tableValues = getTableValues(line, inputStream);
        tag = tagFactory.createTableTag(tagName, tagContent, std::move(tableValues));
    }
    else
    {
        tag = tagFactory.createTag(tagName, tagContent);
    }

    if (line.find_first_not_of(whiteSpaceCharacters) == std::string::npos)
        line = "";

    return tag;
}

std::shared_ptr<Commentary> PbnParser::parseMultilineComment(std::string &line, std::istream &inputStream, bool startedOnNewLine)
{
    auto start = line.find('{');
    line = line.substr(start);
    std::string content;
    while (line.find('}') == std::string::npos)
    {
        content += line + "\n";
        if (!getline(inputStream, line))
            throw std::runtime_error("Unclosed commentary bracket");
    }
    auto end = line.find("}");
    content += line.substr(0, end);

    line.erase(0, end);

    auto token = make_shared<Commentary>(CommentaryFormat::Multiline, startedOnNewLine, content);

    if (line.find_first_not_of(whiteSpaceCharacters) == std::string::npos)
        line = "";

    return token;
}

PbnFile PbnParser::parse(std::istream &inputStream)
{
    PbnFile file;

    // A line based parser manually written parser is employed as most of the time it will suffice
    // An idea to add in the future is a more robust parser, for example a flex powered one

    std::string line;
    while (std::getline(inputStream, line))
    {
        file.appendToken(this->parseToken(line, inputStream, false));
        while (!line.empty())
        {
            file.appendToken(this->parseToken(line, inputStream, false));
        }
    }

    return file;
}
