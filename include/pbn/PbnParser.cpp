#include "PbnParser.h"
#include "tokens/EmptyLine.h"
#include "tokens/EscapedLine.h"
#include "tokens/TextLine.h"
#include "Commentary.h"
#include "Tag.h"
#include "utils/strings.h"

#include <memory>
#include <iostream>

/**
 * This Parser is probably to be replaced with a generated one, something like boost::spirit or Flex-Bison
 */

using namespace std;
using namespace tokens;

constexpr string_view whiteSpaceCharacters = " \t\n\v\f\r";
constexpr char stringDelimiter = '\"';


void PbnParser::parseToken(PbnFile &file, string &line, istream &inputStream, bool startedOnNewLine) {

    auto firstNonWsCharPosition = line.find_first_not_of(whiteSpaceCharacters);

    // Empty line
    if (firstNonWsCharPosition == string::npos) {
        file.appendToken(make_shared<tokens::EmptyLine>());
        line = "";
        return;
    }
    // Escaped line
    else if (line[0] == tokens::escapeCharacter) {
        file.appendToken(tokens::EscapedLine::create(line));
        line = "";
        return;
    }
    char firstValidCharacter = line[firstNonWsCharPosition];
    if (firstValidCharacter == '[') {

        parseTag(file, line, inputStream, startedOnNewLine);
        line = line;

    } else if (firstValidCharacter == ';') {
        file.appendToken(make_shared<Commentary>(CommentaryFormat::Semicolon,
                                                      true,
                                                      line.substr(firstValidCharacter)));
        line = "";
    } else if (firstValidCharacter == '{') {
        auto remainder = parseMultilineComment(file, line, inputStream, startedOnNewLine);
        line = remainder;
    } else {
        file.appendToken(make_shared<TextLine>(line));
        line = "";
    }

}

vector<string> PbnParser::getTableValues(string &line, istream &inputStream) {

    vector<string> values;
    if(line.empty() && !getline(inputStream, line)) {
            return values;
    }
    while(! (line.starts_with('[') || line.empty() || line.starts_with(';')) ) {

        split(line, values);
        if (!getline(inputStream, line)) break;
    }

    return values;
}

void PbnParser::parseTag(PbnFile &file, string &line, istream &inputStream, bool /* startedOnNewLine */ ) {

    // simplified, not all import version are supported, most of them are not used
    regex regex1(R";((\s*\[\s*(\w+)\s*"(.*)"\s*\]\s*));");
    smatch matches;

    if(!std::regex_search(line, matches, regex1)) {
        throw runtime_error("Invalid tag: " + line);
    }

    string tagString = matches[1];
    string tagName = matches[2];
    string tagContent = matches[3];


    line.erase(0, tagString.length());
    auto tag = file.tokens.back();

    if(tagFactory.isTableTag(tagName)) {
        vector<string> tableValues = getTableValues(line, inputStream);
        file.appendToken(tagFactory.createTableTag(tagName, tagContent, move(tableValues)));
    }
    else {
        file.appendToken(tagFactory.createTag(tagName, tagContent));
    }

    if(line.find_first_not_of(whiteSpaceCharacters) == string::npos) line = "";

}

string PbnParser::parseMultilineComment(PbnFile &file, string &line, istream &inputStream, bool startedOnNewLine) {
    auto start = line.find('{');
    string line2 = line.substr(start);
    string content;
    while (line2.find('}') == string::npos) {
        content += line2 + "\n";
        if (!getline(inputStream, line2)) throw runtime_error("Unclosed commentary bracket");
    }
    auto end = line2.find("}");
    content += line2.substr(0, end);

    line2.erase(0, end);

    file.appendToken(make_shared<Commentary>(CommentaryFormat::Brace, startedOnNewLine, content));

    if (line2.find_first_not_of(whiteSpaceCharacters) != string::npos) {
        return line2;
    }

    return "";
}

PbnFile PbnParser::parse(istream &inputStream) {
    PbnFile file;

    // A line based parser manually written parser is employed as most of the time it will suffice
    // An idea to add in the future is a more robust parser, for example a flex powered one

    string line;
    while (std::getline(inputStream, line)) {
        this->parseToken(file, line, inputStream, false);
        while(!line.empty()) {
            this->parseToken(file, line, inputStream, false);
        }
    }

    return file;
}


