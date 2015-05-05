namespace TrustEngine{ namespace Serialization{
    using TrustEngine::System::StringHelper::Tab;

    template<typename FORMAT>
    Object<FORMAT>::Object(std::string const & objectname, int indentrange) :
        indentRange(indentrange),
        name(objectname)
    {}
    template<typename FORMAT>
    Object<FORMAT>::~Object(){
        std::for_each(members.begin(), members.end(), [](ContentType::value_type const & pair){
            delete pair.second;
        });
    }
    template<typename FORMAT>
    int Object<FORMAT>::getIndent() const {
        return indentRange;
    }

    template<>
    bool Object<Formats::JSON>::print(std::ostream & streamResult) const {
        if (!name.empty()){
            streamResult << Tab::_put(indentRange) << '"' << name << '"' << ": ";
        }
        streamResult << "{" << std::endl;

        ContentType::size_type cpt = 0;
        std::for_each(members.begin(), members.end(), [&](ContentType::value_type const & ite){
            //streamResult << '"' << ite.first << '"' << ": ";
            ite.second->print(streamResult);
            if (++cpt < members.size()){
                streamResult << ',';
            }
            streamResult << std::endl;
        });

        streamResult << Tab::_put(indentRange) << '}';
        return true;
    }

    
};};//TENS