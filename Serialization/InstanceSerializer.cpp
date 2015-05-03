namespace TrustEngine{ namespace Serialization{
    using Formats::JSON;

    template<typename FORMAT>
    bool normalParse(std::ostream & stream, Page<FORMAT> & page, Instance const & instance){
        return true;
    }

    template<>
    bool InstanceSerializer<JSON>::serialize(std::ostream & streamResult) {
        bool succeed = true;
        if (!alreadyParsed){
            succeed = normalParse<JSON>(streamResult, page, instance);
        }
        if (succeed){
            alreadyParsed = true;
            return page.print(streamResult);
        }
        return false;
    }


};};//TENS