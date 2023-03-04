#include "Tag.h"

const string &Tag::getTagname() const {
    return this->tagname;
}

const string &Tag::getContent() const {
    return this->content;
}

string Tag::typeName() const {
    return "Tag";
}

string Tag::toString() const {
    return "[" + this->tagname + " \"" +  this->content + "\"]";
}
