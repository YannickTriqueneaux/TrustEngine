namespace TrustEngine{ namespace Reflexion{

class StringBaseDescriptor : public StringizableDescriptor{
public:

    virtual bool isAString() const {
        return true;
    }
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const = 0;
};
class StringDescriptor : public StringBaseDescriptor{
    static std::string const _descriptorName;
	friend class DescriptorRegistry;
	StringDescriptor(){}
public:
	typedef StringDescriptor SelfType;
    typedef std::string InstanceType;
    static std::string const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(_stringize(std::string));
		return _instanceTypeName;
    }
    virtual std::string const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	static Descriptor const * _getDescriptorInstance(){
		static Descriptor const * _descriptor;
		if(_descriptor){
			return _descriptor;
		}
		_descriptor = DescriptorRegistry::_getDescriptor(_getDescriptorName());
		if(_descriptor != nullptr){
			return _descriptor;
		}
        _descriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		return _descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};


};};//TENS