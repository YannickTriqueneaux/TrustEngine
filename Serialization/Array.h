namespace TrustEngine{ namespace Serialization{


    template<typename FORMAT>
    class Array : public Element<FORMAT>{
    public:
        typedef std::vector<Element<FORMAT> const *> ContentType;


        Array(std::string const & arrayname, int indentrange);
        ~Array();

        virtual bool print(std::ostream & streamResult)  const ;


        ContentType elements;
        int getIndent() const ;
    private:
        int indentRange = 0;
        std::string name;
    };
    
};};//TENS