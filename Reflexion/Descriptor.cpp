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
std::vector<Field const *> Descriptor::getFields(bool withParentFields) const {
    std::vector<Field const *> result;
    auto parentDesc = getParentClassDescriptor();
    if (withParentFields && parentDesc){
        result = std::move(parentDesc->getFields(withParentFields));
    }
    std::for_each(fields.begin(), fields.end(), [&](FieldsMapType::value_type const & pair){
        result.push_back(&(pair.second));
    });
    return std::move(result);
}


bool Descriptor::containsField(Field const & field) const {
    return !!getField(field.getName());
}
bool Descriptor::containsField(std::string const & fieldname) const {
    return !!getField(fieldname);
}


Descriptor const * Descriptor::_getDescriptorInstance(){ 
    assert(0); return nullptr; 
}

void Descriptor::setParentClassDescriptor(Descriptor const * parentClassDescriptor){ 
    assert(0); 
}
std::string const & Descriptor::getName() const {
    assert(0);
    return System::StringHelper::EmptyString;
}
std::string const & Descriptor::getInstanceTypename() const {
    assert(0);
    return System::StringHelper::EmptyString;
}

Descriptor const * Descriptor::getParentClassDescriptor() const { 
    return nullptr; 
}

bool Descriptor::isStringizable() const { 
    return false; 
};

bool Descriptor::isAnArray() const{
    return false;
}

bool Descriptor::isAGeneric() const{
    return false;
}
bool Descriptor::isAContainer() const {
    return false;
}


};};//TENS