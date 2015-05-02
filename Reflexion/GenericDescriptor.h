

template<typename Type>
class GenericDescriptor : public Descriptor{
    static std::string const descriptorName;
	friend class DescriptorRegistry;
	GenericDescriptor():parentClassDescriptor(nullptr){}
    static std::string const & getDescriptorName(){
		return descriptorName;
	}
	Descriptor const * parentClassDescriptor;
    std::vector<Descriptor const*> inferDescriptors;
public:
    static std::string const & getInstanceTypeName(){
		return Type::getClassName();
	}
	static bool isTemplateClass(){
		return Type::isTemplateClass;
	}
	typedef GenericDescriptor<Type> SelfType;
	typedef Type InstanceType;
	static Descriptor const * getDescriptorInstance(){
		return Type::getClassDescriptor();
	}
	virtual void setParentClassDescriptor(Descriptor const * parentClassDescriptor){
		this->parentClassDescriptor = parentClassDescriptor;
	}

	template<typename InferType>
	inline void addInferType();

	virtual Descriptor const * getParentClassDescriptor(){
		return parentClassDescriptor;
	}
};


template<typename Type>
std::string const GenericDescriptor<Type>::descriptorName = std::string("GenericDescriptor<").append(GenericDescriptor<Type>::getInstanceTypeName()).append(">");

template<typename Type>
template<typename InferType>
void GenericDescriptor<Type>::addInferType(){
    Descriptor const * inferDescriptor = DescriptorHelper<InferType>::DescriptorType::getDescriptorInstance();
    if (inferDescriptor){
        inferDescriptors << inferDescriptor;
    }
}
