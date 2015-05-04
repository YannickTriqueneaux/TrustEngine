namespace TrustEngine{ namespace Serialization{
    using TrustEngine::System::StringHelper::Tab;

    template<typename FORMAT>
    Object<FORMAT>::Object(std::string const & objectname, int indentrange) :
        indentRange(indentrange),
        name(objectname)
    {}

    template<>
    bool Object<Formats::JSON>::print(std::ostream & streamResult) const {
        if (!name.empty()){
            streamResult << '"' << name << '"' << ": ";
        }
        streamResult << "{" << std::endl;
        streamResult << Tab::_put(indentRange + 1 );

        ContentType::size_type cpt = 0;
        std::for_each(members.begin(), members.end(), [&](ContentType::value_type const & ite){
            streamResult << '"' << ite.first << '"' << ": ";
            ite.second->print(streamResult);
            if (cpt++ < members.size()){
                streamResult << ',' << std::endl;
                streamResult << Tab::_put(indentRange + 1);
            }
        });

        streamResult << Tab::_put(indentRange) << '}';
        return true;
    }
};};//TENS