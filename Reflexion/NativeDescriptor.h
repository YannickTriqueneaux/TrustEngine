namespace TrustEngine{ namespace Reflexion{

template<typename Type>
class NativeDescriptor : public Descriptor{
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
	typedef NativeDescriptor<bool> SelfType;
	typedef int InstanceType;
    static std::string const & getDescriptorName(){
		return descriptorName;
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
	typedef NativeDescriptor<int> SelfType;
	typedef int InstanceType;
    static std::string const & getDescriptorName(){
		return descriptorName;
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
    static std::string const & getInstanceTypeName(){
        static std::string const instanceTypeName(_stringize(short));
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
    static std::string const & getInstanceTypeName(){
        static std::string const instanceTypeName(_stringize(long));
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
    static std::string const & getInstanceTypeName(){
        static std::string const instanceTypeName(_stringize(float));
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
    static std::string const & getInstanceTypeName(){
        static std::string const instanceTypeName(_stringize(double));
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
    static std::string const & getInstanceTypeName(){
        static std::string const instanceTypeName(_stringize(unsigned int));
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


};};//TENS