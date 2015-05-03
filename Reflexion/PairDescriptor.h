namespace TrustEngine{ namespace Reflexion{

class PairDescriptorBase : public ArrayDescriptor{
public:
    
    virtual bool isAContainer() const{
        return true;
    }
    virtual bool getContentInstances(std::map<std::string, Instance> & contentResult, Instance const & fromInstance) const = 0;
};

template<typename FirstType, typename SecondType>
class PairDescriptor : public PairDescriptorBase{
	typedef FirstType FistValueType;
	typedef SecondType SecondValueType;
	typedef PairDescriptor<FirstType, SecondType > SelfType;


	friend class DescriptorRegistry;

	static Descriptor const * _firstDescriptor;
	static Descriptor const * _secondDescriptor;
public:
	PairDescriptor(){}
    static std::string const & _getDescriptorName(){
        static std::string const _descriptorName(std::string("PairDescriptor<")
			.append(DescriptorHelper<FistValueType>::DescriptorType::_getInstanceTypeName()).append(",")
			.append(DescriptorHelper<SecondValueType>::DescriptorType::_getInstanceTypeName()).append(">"));
		 return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    virtual std::string const & getInstanceTypeName() const {
        return _getInstanceTypeName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(std::string("Pair<").append(DescriptorHelper<FistValueType>::DescriptorType::_getInstanceTypeName()).append(",")
			.append(DescriptorHelper<SecondValueType>::DescriptorType::_getInstanceTypeName()).append(">"));
		return _instanceTypeName;
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
		_firstDescriptor = getDescriptorOf<FistValueType>();
		_secondDescriptor = getDescriptorOf<SecondValueType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual bool getContentInstances(std::map<std::string, Instance> & contentResult, Instance const & fromInstance) const {
        std::pair<FirstType, SecondValueType> & pair = *reinterpret_cast<std::pair<FirstType, SecondValueType>*>(fromInstance.get());
        contentResult.emplace( "key", Instance(&pair.first) );
        contentResult.emplace( "value", Instance(&pair.second) );
        return true;
    }
};

template<typename FistValueType, typename SecondValueType>
Descriptor const * PairDescriptor<FistValueType, SecondValueType>::_firstDescriptor = nullptr;
template<typename FistValueType, typename SecondValueType>
Descriptor const * PairDescriptor<FistValueType, SecondValueType>::_secondDescriptor = nullptr;


};};//TENS