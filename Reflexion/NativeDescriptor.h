namespace TrustEngine{ namespace Reflexion{

template<typename Type>
class NativeDescriptor : public StringizableDescriptor{
};
template<>
class NativeDescriptor<bool> : public Descriptor{
    static std::string const descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
    static std::string const & getInstanceTypeName(){
        static std::string const instanceTypeName(_stringize(bool));
		return instanceTypeName;
    }
    virtual std::string const & getInstanceTypename() const {
        return getInstanceTypeName();
    }
	typedef NativeDescriptor<bool> SelfType;
	typedef int InstanceType;
    static std::string const & getDescriptorName(){
		return descriptorName;
	}
    virtual std::string const & getName() const {
        return getDescriptorName();
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
		descriptor = newDescriptor;
		return descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};
template<>
class NativeDescriptor<int> : public Descriptor{
    static std::string const descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
    static std::string const & getInstanceTypeName(){
        static std::string const instanceTypeName(_stringize(int));
		return instanceTypeName;
    }
    virtual std::string const & getInstanceTypename() const {
        return getInstanceTypeName();
    }
	typedef NativeDescriptor<int> SelfType;
	typedef int InstanceType;
    static std::string const & getDescriptorName(){
		return descriptorName;
    }
    virtual std::string const & getName() const {
        return getDescriptorName();
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
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<short> : public Descriptor{
    static std::string const descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<short> SelfType;
	typedef int InstanceType;
    static std::string const & getDescriptorName(){
		return descriptorName;
    }
    virtual std::string const & getName() const {
        return getDescriptorName();
    }
    static std::string const & getInstanceTypeName(){
        static std::string const instanceTypeName(_stringize(short));
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
		Descriptor * newDescriptor = DescriptorRegistry::createDescriptor<SelfType>();
		descriptor = newDescriptor;
		return descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<long> : public Descriptor{
    static std::string const descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<long> SelfType;
	typedef long InstanceType;
	
    static std::string const & getDescriptorName(){
		return descriptorName;
    }
    virtual std::string const & getName() const {
        return getDescriptorName();
    }
    static std::string const & getInstanceTypeName(){
        static std::string const instanceTypeName(_stringize(long));
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
		Descriptor * newDescriptor = DescriptorRegistry::createDescriptor<SelfType>();
		descriptor = newDescriptor;
		return descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<float> : public Descriptor{
    static std::string const descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<float> SelfType;
	typedef float InstanceType;

    static std::string const & getDescriptorName(){
		return descriptorName;
    }
    virtual std::string const & getName() const {
        return getDescriptorName();
    }
    static std::string const & getInstanceTypeName(){
        static std::string const instanceTypeName(_stringize(float));
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
		Descriptor * newDescriptor = DescriptorRegistry::createDescriptor<SelfType>();
		descriptor = newDescriptor;
		return descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<double> : public Descriptor{
    static std::string const descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<double> SelfType;
	typedef double InstanceType;

    static std::string const & getDescriptorName(){
		return descriptorName;
    }
    virtual std::string const & getName() const {
        return getDescriptorName();
    }
    static std::string const & getInstanceTypeName(){
        static std::string const instanceTypeName(_stringize(double));
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
		Descriptor * newDescriptor = DescriptorRegistry::createDescriptor<SelfType>();
		descriptor = newDescriptor;
		return descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<unsigned int> : public Descriptor{
    static std::string const descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<unsigned int> SelfType;
	typedef unsigned int InstanceType;

    static std::string const & getDescriptorName(){
		return descriptorName;
    }
    virtual std::string const & getName() const {
        return getDescriptorName();
    }
    static std::string const & getInstanceTypeName(){
        static std::string const instanceTypeName(_stringize(unsigned int));
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
		Descriptor * newDescriptor = DescriptorRegistry::createDescriptor<SelfType>();
		descriptor = newDescriptor;
		return descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};


};};//TENS