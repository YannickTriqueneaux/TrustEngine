namespace TrustEngine{ namespace Reflexion{

class VectorDescriptorBase : public ArrayDescriptor{
public:
};

template<typename T>
class VectorDescriptor : public VectorDescriptorBase{
    static std::string const _descriptorName;

    typedef std::vector<T>			InstanceType;
	typedef T					ValueType;
	typedef VectorDescriptor<T> SelfType;

	friend class DescriptorRegistry;
	static Descriptor const * _valueDescriptor;
	VectorDescriptor(){}
public:
    static std::string const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(std::string("Vector<").append(DescriptorHelper<T>::DescriptorType::_getInstanceTypeName()).append(">"));
		return _instanceTypeName;
	}
	static Descriptor const * _getDescriptorInstance(){
		static Descriptor const * descriptor;
		if(descriptor){
			return descriptor;
		}
		descriptor = DescriptorRegistry::_getDescriptor(_getDescriptorName());
		if(descriptor != nullptr){
			return descriptor;
		}
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		descriptor = newDescriptor;
		return descriptor;
	}
};

template<typename T>
Descriptor const * VectorDescriptor<T>::_valueDescriptor = getDescriptorOf<T>();

template<typename T>
std::string const VectorDescriptor<T>::_descriptorName = ("VectorDescriptor<" + DescriptorHelper<T>::DescriptorType::_getInstanceTypeName()).append(">");


};};//TENS