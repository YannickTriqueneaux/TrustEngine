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

	static Descriptor const * _pairDescriptor;
	MapDescriptor(){}
public:
    static std::string const & _getDescriptorName(){
        static std::string const descriptorName(std::string("MapDescriptor<")
			.append(DescriptorHelper<FistValueType>::DescriptorType::_getInstanceTypeName()).append(",")
			.append(DescriptorHelper<SecondValueType>::DescriptorType::_getInstanceTypeName()).append(">"));
		return descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(std::string("Map<").append(DescriptorHelper<FistValueType>::DescriptorType::_getInstanceTypeName()).append(",")
			.append(DescriptorHelper<SecondValueType>::DescriptorType::_getInstanceTypeName()).append(">"));
		return _instanceTypeName;
    }
    virtual std::string const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	static Descriptor const * _getDescriptorInstance(){
		static Descriptor const * _descriptor;
		if (_descriptor){
			return _descriptor;
		}
		_descriptor = DescriptorRegistry::_getDescriptor(_getDescriptorName());
		if (_descriptor != nullptr){
			return _descriptor;
		}
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>(); 
		_pairDescriptor = getDescriptorOf<ValueType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
};

template<typename FistValueType, typename SecondValueType>
Descriptor const * MapDescriptor<FistValueType, SecondValueType>::_pairDescriptor = nullptr;


};};//TENS