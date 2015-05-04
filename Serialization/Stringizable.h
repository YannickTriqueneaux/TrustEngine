namespace TrustEngine{
    namespace Serialization{

        template<typename FORMAT>
        class Stringizable : public Element<FORMAT>{
        public:
            typedef Value<FORMAT>* ContentType;


            Stringizable(std::string const & objectname, int indentrange);

            virtual bool print(std::ostream & streamResult) const;

            ContentType value;
        private:
            int indentRange = 0;
            std::string name;
        };
    };
};//TENS