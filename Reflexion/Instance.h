namespace TrustEngine{ namespace Reflexion{

class Instance{
public:
	Instance();
	Instance(void * instance, Descriptor const * descriptor);
	template<typename T>
	inline Instance(T * instance);

	void * get() const ;
	Descriptor const * getType() const ;
    bool isEmpty() const ;


    /**
    * @return true if given Instances are equivalent
    */
    friend bool operator==(Instance const & first, Instance const & second);
    /**
    * @return true if given Instances are different
    */
    friend bool operator!=(Instance const & first, Instance const & second);
private:
	void * instance;
	Descriptor const * descriptor;
};

template<typename T>
inline Instance::Instance(T * instance) : instance(reinterpret_cast<void*>(instance)), descriptor(getDescriptorOf<T>()){
}

};};//TENS