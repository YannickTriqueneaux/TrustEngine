namespace TrustEngine{
    namespace Serialization{
        using TrustEngine::System::StringHelper::Tab;

        template<typename FORMAT>
        Stringizable<FORMAT>::Stringizable(std::string const & objectname, int indentrange) :
            indentRange(indentrange),
            name(objectname)
        {}

        template<>
        bool Stringizable<Formats::JSON>::print(std::ostream & streamResult) const {
            if (!name.empty()){
                streamResult << '"' << name << '"' << ": ";
            }
            streamResult << value->print(streamResult);
            return true;
        }
    };
};//TENS