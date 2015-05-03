namespace TrustEngine{ namespace Serialization{

    template<typename FORMAT>
    class Object{
    public:
        Object(std::string const & objectname, int indentrange);

        bool print(std::ostream & streamResult) const ;
    private:
        int indentRange = 0;
        std::string name;
        typedef std::map<std::string, Value<FORMAT> const *> ContentType;
        ContentType content;
    };
};};//TENS