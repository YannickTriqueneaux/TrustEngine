namespace TrustEngine{ namespace Reflexion{

class Field;

class Descriptor{
	friend class DescriptorRegistry;
    friend class Field;
protected:
	Descriptor();

public:
    template<typename FieldType>
    Field const * addField(std::string const & fieldName, FieldType const * offset){
        assert(fields.find(fieldName) == fields.end() && "Descriptor::addField - field already added");
        Descriptor const * fieldDescriptor = getDescriptorOf<FieldType>();
        assert(fieldDescriptor && "Descriptor::addField - unknown field descritor");
        auto & pair = fields.insert(std::make_pair(fieldName, Field())).first;
        pair->second = Field(static_cast<int>((unsigned int*)offset - (unsigned int*)0), *fieldDescriptor, pair->first);
        return &(pair->second);
    }

    template<typename FieldType>
    Field const * addDescriptorField(std::string const & fieldName, Descriptor const * offset){
        assert(descriptorField.find(fieldName) == descriptorField.end());
        Descriptor const * fieldDescriptor = getDescriptorOf<FieldType>();
        assert(fieldDescriptor);
        auto & pair = descriptorField.insert(std::make_pair(fieldName, Field())).first;
        pair->second = Field(static_cast<int>((unsigned int*)offset - (unsigned int*)0), *fieldDescriptor, pair->first);
        return &(pair->second);;
    }

    /**
    * find the Field by the given name
    * @param field name
    * @return nullptr if not found
    */
    Field const * getField(std::string const & fieldName) const ;

    /**
    * @return true if the given Field exist inside the descriptor
    */
    bool containsField(Field const & field) const ;
    bool containsField(std::string const & fieldname) const ;


    
    static Descriptor const * getDescriptorInstance();
    virtual void setParentClassDescriptor(Descriptor const * parentClassDescriptor);
    virtual Descriptor const * getParentClassDescriptor() const ;
    virtual bool isStringizable() const ;
    virtual std::string stringize(Instance const & instance) const ;

private:
    std::map<std::string, Field> fields;
    std::map<std::string, Descriptor const *> descriptorField;
};


};};//TENS