_BEGIN_TE_REFLEXION_NAMESPACE

class Instance{
public:
	Instance();
	Instance(void * instance, Descriptor const * descriptor);
	template<typename T>
	inline Instance(T * instance);

	void * get() const ;
	Descriptor const * getType() const ;
private:
	void * instance;
	Descriptor const * descriptor;
};

template<typename T>
inline Instance::Instance(T * instance) : instance((void*)instance), descriptor(getDescriptorOf<T>()){
}

_END_TE_REFLEXION_NAMESPACE