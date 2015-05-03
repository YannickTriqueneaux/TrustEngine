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


Descriptor const * Descriptor::getDescriptorInstance(){ 
    assert(0); return nullptr; 
}

void Descriptor::setParentClassDescriptor(Descriptor const * parentClassDescriptor){ 
    assert(0); 
}

Descriptor const * Descriptor::getParentClassDescriptor() const { 
    return nullptr; 
}

bool Descriptor::isStringizable() const { 
    return false; 
};


std::string Descriptor::stringize(Instance const &) const {
    assert(isStringizable() && "This type is not serializable");
    return System::StringHelper::EmptyString;
}


};};//TENS