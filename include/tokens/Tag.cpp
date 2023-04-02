#include "Tag.h"

const std::string &Tag::getTagname() const {
    return this->tagname;
}

const std::string &Tag::getContent() const {
    return this->content;
}

std::string Tag::typeName() const {
    return "Tag";
}

void Tag::serialize(std::ostream& to) const  {
    to << "[" << this->tagname << " \"" <<  this->content << "\"]";
}

Tag::Tag(const std::string &tagname, const std::string &content) : tagname(tagname), content(content) {}

bool Tag::isTag() const {
    return true;
}

bool Tag::isTableTag() const {
    return false;
}
