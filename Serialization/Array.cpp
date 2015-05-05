namespace TrustEngine{ namespace Serialization{

    using TrustEngine::System::StringHelper::Tab;

    template<typename FORMAT>
    Array<FORMAT>::Array(std::string const & arrayname, int indentrange) 
        :indentRange(indentrange),
        name(arrayname){}

    template<typename FORMAT>
    Array<FORMAT>::~Array(){
        std::for_each(elements.begin(), elements.end(), [](ContentType::value_type const & elmt){
            delete elmt;
        });
    }


    template<>
    bool Array<Formats::JSON>::print(std::ostream & streamResult) const {
        if (!name.empty()){
            streamResult << '"' << name << '"' << ": ";
        }
        streamResult << "[" << std::endl;
        streamResult << Tab::_put(indentRange + 1);

        ContentType::size_type cpt = 0;
        std::for_each(elements.begin(), elements.end(), [&](ContentType::value_type const & ite){
            ite->print(streamResult);
            if (cpt++ < elements.size()){
                streamResult << ',' << std::endl;
                streamResult << Tab::_put(indentRange + 1);
            }
        });

        streamResult << Tab::_put(indentRange) << ']';
        return true;
    }

};};//TENS