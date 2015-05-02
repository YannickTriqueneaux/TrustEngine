namespace TrustEngine{ namespace Reflexion{

class PairDescriptorBase : public Descriptor{
public:
};

template<typename FirstType, typename SecondType>
class PairDescriptor : public PairDescriptorBase{
	typedef FirstType FistValueType;
	typedef SecondType SecondValueType;
	typedef PairDescriptor<FirstType, SecondType > SelfType;


	friend class DescriptorRegistry;

	static Descriptor const * firstDescriptor;
	static Descriptor const * secondDescriptor;
public:
	PairDescriptor(){}
    static std::string const & getDescriptorName(){
        static std::string const descriptorName(std::string("PairDescriptor<")
			.append(DescriptorHelper<FistValueType>::DescriptorType::getInstanceTypeName()).append(",")
			.append(DescriptorHelper<SecondValueType>::DescriptorType::getInstanceTypeName()).append(">"));
		 return descriptorName;
	}
    static std::string const & getInstanceTypeName(){
        static std::string const instanceTypeName(std::string("Pair<").append(DescriptorHelper<FistValueType>::DescriptorType::getInstanceTypeName()).append(",")
			.append(DescriptorHelper<SecondValueType>::DescriptorType::getInstanceTypeName()).append(">"));
		return instanceTypeName;
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
		firstDescriptor = getDescriptorOf<FistValueType>();
		secondDescriptor = getDescriptorOf<SecondValueType>();
		descriptor = newDescriptor;
		return descriptor;
	}
};

template<typename FistValueType, typename SecondValueType>
Descriptor const * PairDescriptor<FistValueType, SecondValueType>::firstDescriptor = nullptr;
template<typename FistValueType, typename SecondValueType>
Descriptor const * PairDescriptor<FistValueType, SecondValueType>::secondDescriptor = nullptr;


};};//TENS