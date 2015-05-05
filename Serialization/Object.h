namespace TrustEngine{ namespace Serialization{

    template<typename FORMAT>
    class Object : public Element<FORMAT>{
    public:
        typedef std::map<std::string, Element<FORMAT> const *> ContentType;


        Object(std::string const & objectname, int indentrange);
        virtual ~Object();

        virtual bool print(std::ostream & streamResult) const ;

        ContentType members;
        int getIndent() const;
    private:
        int indentRange = 0;
        std::string name;
    };
};};//TENS