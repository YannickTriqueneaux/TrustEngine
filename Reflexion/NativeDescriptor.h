namespace TrustEngine{ namespace Reflexion{

template<typename Type>
class NativeDescriptor : public StringizableDescriptor{
};
template<>
class NativeDescriptor<bool> : public Descriptor{
    static std::string const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(_stringize(bool));
		return _instanceTypeName;
    }
    virtual std::string const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	typedef NativeDescriptor<bool> SelfType;
	typedef int InstanceType;
    static std::string const & _getDescriptorName(){
		return _descriptorName;
	}
    virtual std::string const & getName() const {
        return _getDescriptorName();
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
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};
template<>
class NativeDescriptor<int> : public Descriptor{
    static std::string const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(_stringize(int));
		return _instanceTypeName;
    }
    virtual std::string const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	typedef NativeDescriptor<int> SelfType;
	typedef int InstanceType;
    static std::string const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
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
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<short> : public Descriptor{
    static std::string const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<short> SelfType;
	typedef int InstanceType;
    static std::string const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(_stringize(short));
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
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<long> : public Descriptor{
    static std::string const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<long> SelfType;
	typedef long InstanceType;
	
    static std::string const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(_stringize(long));
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
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<float> : public Descriptor{
    static std::string const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<float> SelfType;
	typedef float InstanceType;

    static std::string const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(_stringize(float));
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
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<double> : public Descriptor{
    static std::string const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<double> SelfType;
	typedef double InstanceType;

    static std::string const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(_stringize(double));
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
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<unsigned int> : public Descriptor{
    static std::string const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<unsigned int> SelfType;
	typedef unsigned int InstanceType;

    static std::string const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(_stringize(unsigned int));
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
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};


};};//TENS