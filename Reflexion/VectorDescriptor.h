_BEGIN_TE_REFLEXION_NAMESPACE

class VectorDescriptorBase : public Descriptor{
public:
};

template<typename T>
class VectorDescriptor : public VectorDescriptorBase{
    static std::string const descriptorName;

    typedef std::vector<T>			InstanceType;
	typedef T					ValueType;
	typedef VectorDescriptor<T> SelfType;

	friend class DescriptorRegistry;
	static Descriptor const * valueDescriptor;
	VectorDescriptor(){}
public:
    static std::string const & getDescriptorName(){
		return descriptorName;
	}
    static std::string const & getInstanceTypeName(){
        static std::string const instanceTypeName(std::string("Vector<").append(DescriptorHelper<T>::DescriptorType::getInstanceTypeName()).append(">"));
		return instanceTypeName;
	}
	static Descriptor const * getDescriptorInstance(){
		static Descriptor const * descriptor;
		if(descriptor){
			return descriptor;
		}
		descriptor = DescriptorRegistry::getDescriptor(getDescriptorName());
		if(descriptor != nullptr){
			return descriptor;
		}
		Descriptor * newDescriptor = DescriptorRegistry::createDescriptor<SelfType>();
		descriptor = newDescriptor;
		return descriptor;
	}
};

template<typename T>
Descriptor const * VectorDescriptor<T>::valueDescriptor = getDescriptorOf<T>();

template<typename T>
std::string const VectorDescriptor<T>::descriptorName = ("VectorDescriptor<" + DescriptorHelper<T>::DescriptorType::getInstanceTypeName()).append(">");


_END_TE_REFLEXION_NAMESPACE