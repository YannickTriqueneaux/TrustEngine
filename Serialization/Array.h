namespace TrustEngine{ namespace Serialization{


    template<typename FORMAT>
    class Array{
    public:
        Array(std::string const & arrayname, int indentrange);

        bool print(std::ostream & streamResult)  const ;
    private:
        int indentRange = 0;
        std::string name;
        typedef std::vector<Value<FORMAT> const *> ContentType;
        ContentType content;
    };
    
};};//TENS