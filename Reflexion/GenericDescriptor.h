namespace TrustEngine{ namespace Reflexion{

template<typename Type>
class GenericDescriptor : public Descriptor{
    static std::string const _descriptorName;
	friend class DescriptorRegistry;
	GenericDescriptor():parentClassDescriptor(nullptr){}
    static std::string const & _getDescriptorName(){
		return _descriptorName;
	}
	Descriptor const * parentClassDescriptor;
    std::vector<Descriptor const*> inferDescriptors;
public:
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const & _getInstanceTypeName(){
        return Type::_getClassName();
    }
    virtual std::string const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	static bool _isTemplateClass(){
		return Type::_isTemplateClass;
	}
	typedef GenericDescriptor<Type> SelfType;
	typedef Type InstanceType;
	static Descriptor const * _getDescriptorInstance(){
        return Type::_getClassDescriptor();
	}
	virtual void setParentClassDescriptor(Descriptor const * parentClassDescriptor){
		this->parentClassDescriptor = parentClassDescriptor;
	}

	template<typename InferType>
	inline void addInferType();

	virtual Descriptor const * getParentClassDescriptor() const {
		return parentClassDescriptor;
	}
    virtual bool isAGeneric() const {
        return true;
    }
};


template<typename Type>
std::string const GenericDescriptor<Type>::_descriptorName = std::string("GenericDescriptor<").append(GenericDescriptor<Type>::_getInstanceTypeName()).append(">");

template<typename Type>
template<typename InferType>
void GenericDescriptor<Type>::addInferType(){
    using namespace TrustEngine::System::StringHelper;
    Descriptor const * inferDescriptor = DescriptorHelper<InferType>::DescriptorType::_getDescriptorInstance();
    if (inferDescriptor){
        inferDescriptors << inferDescriptor;
    }
}


};};//TENS
