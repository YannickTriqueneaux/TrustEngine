namespace TrustEngine{ namespace Reflexion{


class StringDescriptor : public StringizableDescriptor{
    static std::string const descriptorName;
	friend class DescriptorRegistry;
	StringDescriptor(){}
public:
	typedef StringDescriptor SelfType;
    typedef std::string InstanceType;
    static std::string const & getDescriptorName(){
		return descriptorName;
    }
    virtual std::string const & getName() const {
        return getDescriptorName();
    }
    static std::string const & getInstanceTypeName(){
        static std::string const instanceTypeName(_stringize(std::string));
		return instanceTypeName;
    }
    virtual std::string const & getInstanceTypename() const {
        return getInstanceTypeName();
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

    inline virtual bool isStringizable() const {
        return false;
    };


    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};


};};//TENS