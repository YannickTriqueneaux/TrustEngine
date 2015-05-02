
class StringDescriptor : public Descriptor{
    static std::string const descriptorName;
    static std::string const instanceTypeName;
	friend class DescriptorRegistry;
	StringDescriptor(){}
public:
	typedef StringDescriptor SelfType;
    typedef std::string InstanceType;
    static std::string const & getDescriptorName(){
		return descriptorName;
	}
    static std::string const & getInstanceTypeName(){
        static std::string const instanceTypeName(stringize(std::string));
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
        descriptor = DescriptorRegistry::createDescriptor<SelfType>();
		return descriptor;
	}
};