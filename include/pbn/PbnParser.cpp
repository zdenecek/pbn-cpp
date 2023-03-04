#include "PbnParser.h"
#include "tokens/EmptyLine.h"
#include "tokens/EscapedLine.h"
#include "tokens/TextLine.h"
#include "Commentary.h"
#include "Tag.h"

#include <memory>
#include <iostream>


using namespace std;
using namespace tokens;

constexpr string_view whiteSpaceCharacters = " \t\n\v\f\r";

void PbnParser::handleLine(PbnFile &file, const string &line, istream &inputStream) {

    auto firstNonWs = line.find_first_not_of(whiteSpaceCharacters);

    // Empty line
    if (firstNonWs == string::npos) {
        file.tokens.push_back(make_shared<tokens::EmptyLine>());
        return;
    }
        // Escaped line
    else if (line[0] == tokens::escapeCharacter) {
        file.tokens.push_back(tokens::EscapedLine::create(line));
        return;
    }
    char firstValidCharacter = line[firstNonWs];
    if (firstValidCharacter == '[') {
        file.tokens.push_back(make_shared<Tag>());
        // TODO
    } else if (firstValidCharacter == ';') {
        file.tokens.push_back(make_shared<Commentary>(CommentaryFormat::Semicolon,
                                                      true,
                                                      line.substr(firstValidCharacter)));
    } else if (firstValidCharacter == '{') {
        parseMultilineComment(file, line, inputStream, true);
    } else {
        file.tokens.push_back(make_shared<TextLine>(line));
    }

}

void PbnParser::parseMultilineComment(PbnFile &file, const string &line, istream &inputStream, bool startedOnNewLine) {
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

    file.tokens.push_back(make_shared<Commentary>(CommentaryFormat::Brace, startedOnNewLine, content));

    if (line2.find_first_not_of(whiteSpaceCharacters) != string::npos) {
        handleLine(file, line2, inputStream);
    }
}

PbnFile PbnParser::parse(istream &inputStream) {
    PbnFile file;

    // A line based parser is employed as most of the time it will suffice

    string line;
    while (std::getline(inputStream, line)) {
        this->handleLine(file, line, inputStream);
    }

    return file;
}


