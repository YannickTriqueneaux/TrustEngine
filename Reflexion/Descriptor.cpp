namespace TrustEngine{ namespace Reflexion{

Descriptor::Descriptor(){
}

Field const * Descriptor::getField(std::string const & fieldName) const {
    auto found = fields.find(fieldName);
    if (found == fields.end()){//maybe in inherit class
        auto parentDesc = getParentClassDescriptor();
        if (parentDesc){
            return parentDesc->getField(fieldName);
        }
        return nullptr;
    }
    return &found->second;
}
bool Descriptor::containsField(Field const & field) const {
    return !!getField(field.getName());
}
bool Descriptor::containsField(std::string const & fieldname) const {
    return !!getField(fieldname);
}

};};//TENS