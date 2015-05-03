namespace TrustEngine{ namespace Serialization{

    template<typename FORMAT>
    class Object{
    public:
        typedef std::map<std::string, Value<FORMAT> const *> ContentType;


        Object(std::string const & objectname, int indentrange);

        bool print(std::ostream & streamResult) const ;

        ContentType & getContent(){
            return content;
        };
        int getIndent(){
            return indentRange;
        }

    private:
        int indentRange = 0;
        std::string name;
        ContentType content;
    };
};};//TENS