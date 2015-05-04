namespace TrustEngine{ namespace Serialization{


    template<typename FORMAT>
    class Array : public Element<FORMAT>{
    public:
        typedef std::vector<Value<FORMAT> const *> ContentType;


        Array(std::string const & arrayname, int indentrange);

        virtual bool print(std::ostream & streamResult)  const ;


        ContentType elements;
    private:
        int indentRange = 0;
        std::string name;
    };
    
};};//TENS