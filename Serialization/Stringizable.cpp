namespace TrustEngine{
    namespace Serialization{
        using TrustEngine::System::StringHelper::Tab;

        template<typename FORMAT>
        Stringizable<FORMAT>::Stringizable(std::string const & objectname, int indentrange) :
            indentRange(indentrange),
            name(objectname)
        {}
        template<typename FORMAT>
        Stringizable<FORMAT>::~Stringizable(){
            delete value;
        }

        template<>
        bool Stringizable<Formats::JSON>::print(std::ostream & streamResult) const {
            streamResult << Tab::_put(indentRange);
            if (!name.empty()){
                streamResult << '"' << name << '"' << ": ";
            }
            value->print(streamResult);
            return true;
        }
    };
};//TENS