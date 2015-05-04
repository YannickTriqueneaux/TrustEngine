namespace TrustEngine{ namespace Serialization{

    template<typename FORMAT>
    class Object : public Element<FORMAT>{
    public:
        typedef std::map<std::string, Value<FORMAT> const *> ContentType;


        Object(std::string const & objectname, int indentrange);

        virtual bool print(std::ostream & streamResult) const ;

        ContentType members;
    private:
        int indentRange = 0;
        std::string name;
    };
};};//TENS