namespace TrustEngine{ namespace Serialization{

    template<typename FORMAT>
    class InstanceParser{
    public:
        InstanceParser(Page<FORMAT> & pagetofill, Instance const & instancetoparse) :
            instance(instancetoparse),
            page(pagetofill){}

        bool parse();

    private:
        Instance const & instance;
        Page<FORMAT> & page;
    };

};};//TENS