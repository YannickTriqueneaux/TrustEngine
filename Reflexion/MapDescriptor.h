namespace TrustEngine{ namespace Reflexion{


class MapDescriptorBase : public ArrayDescriptor{
public:
};

template<typename FirstType,typename SecondType>
class MapDescriptor : public MapDescriptorBase{
    static std::string const descriptorName;

    typedef std::map<FirstType, SecondType > InstanceType;
    typedef std::pair<FirstType, SecondType>	ValueType;
	typedef MapDescriptor<FirstType, SecondType > SelfType;

	typedef FirstType FistValueType;
	typedef SecondType SecondValueType;

	friend class DescriptorRegistry;

	static Descriptor const * pairDescriptor;
	MapDescriptor(){}
public:
    static std::string const & getDescriptorName(){
        static std::string const descriptorName(std::string("MapDescriptor<")
			.append(DescriptorHelper<FistValueType>::DescriptorType::getInstanceTypeName()).append(",")
			.append(DescriptorHelper<SecondValueType>::DescriptorType::getInstanceTypeName()).append(">"));
		return descriptorName;
    }
    virtual std::string const & getName() const {
        return getDescriptorName();
    }
    static std::string const & getInstanceTypeName(){
        static std::string const instanceTypeName(std::string("Map<").append(DescriptorHelper<FistValueType>::DescriptorType::getInstanceTypeName()).append(",")
			.append(DescriptorHelper<SecondValueType>::DescriptorType::getInstanceTypeName()).append(">"));
		return instanceTypeName;
    }
    virtual std::string const & getInstanceTypename() const {
        return getInstanceTypeName();
    }
	static Descriptor const * getDescriptorInstance(){
		static Descriptor const * descriptor;
		if (descriptor){
			return descriptor;
		}
		descriptor = DescriptorRegistry::getDescriptor(getDescriptorName());
		if (descriptor != nullptr){
			return descriptor;
		}
		Descriptor * newDescriptor = DescriptorRegistry::createDescriptor<SelfType>(); 
		pairDescriptor = getDescriptorOf<ValueType>();
		descriptor = newDescriptor;
		return descriptor;
	}
};

template<typename FistValueType, typename SecondValueType>
Descriptor const * MapDescriptor<FistValueType, SecondValueType>::pairDescriptor = nullptr;


};};//TENS