BEGIN_TE_REFLEXION_NAMESPACE

class Descriptor{
	friend class DescriptorRegistry;
protected:
	Descriptor();

public:
    template<typename FieldType>
    Field const * addField(std::string const & fieldName, FieldType const * offset){
        assert(fields.find(fieldName) == fields.end());
        Descriptor const * fieldDescriptor = getDescriptorOf<FieldType>();
        assert(fieldDescriptor);
        auto pair = fields.insert(std::make_pair(fieldName, Field(static_cast<int>((unsigned int*)offset - (unsigned int*)0), fieldDescriptor)));
        return &(pair.first->second);
    }

    template<typename FieldType>
    Field const * addDescriptorField(std::string const & fieldName, Descriptor const ** offset){
        assert(fields.find(fieldName) == fields.end());
        Descriptor const * fieldDescriptor = getDescriptorOf<FieldType>();
        assert(fieldDescriptor);
        auto pair = fields.insert(std::make_pair(fieldName, Field(static_cast<int>((unsigned int*)offset - (unsigned int*)0), fieldDescriptor)));
        return &(pair.first->second);
    }


	static Descriptor const * getDescriptorInstance(){assert(0);return nullptr;}
	virtual void setParentClassDescriptor(Descriptor const * parentClassDescriptor){assert(0);}
	virtual Descriptor const * getParentClassDescriptor(){assert(0);return nullptr;}

private:
    std::map<std::string, Field> fields;
};


END_TE_REFLEXION_NAMESPACE