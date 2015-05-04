namespace TrustEngine{ namespace Serialization{
    using Formats::JSON;
    
    template<>
    bool InstanceSerializer<JSON>::serialize(std::ostream & streamResult) {
        bool succeed = true;
        if (!alreadyParsed){
            InstanceParser<JSON> instanceParser(page,instance);
            succeed = instanceParser.parse();
        }
        if (succeed){
            alreadyParsed = true;
            return page.print(streamResult);
        }
        return false;
    }


};};//TENS