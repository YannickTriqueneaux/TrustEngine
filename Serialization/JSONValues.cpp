namespace TrustEngine{ namespace Serialization{
    
    using Formats::JSON; 
    using Reflexion::Instance;

    template<>
    bool ArrayValue< JSON >::print(std::ostream & streamResult)  const {
        return content.print(streamResult);
    }

    template<>
    bool ObjectValue< JSON >::print(std::ostream & streamResult) const {
        return content.print(streamResult);
    }

    template<>
    bool BooleanValue< JSON >::print(std::ostream & streamResult) const {
        if (content){
            streamResult << "true";
        }
        else{
            streamResult << "false";
        }
        return true;
    }

    template<>
    bool NullValue< JSON >::print(std::ostream & streamResult) const {
        streamResult << "null";
        return true;
    }


    template<>
    bool StringValue<JSON>::print(std::ostream & streamResult) const {
        streamResult << '"';
        Stringizer::instanceToString(streamResult, content);
        streamResult << '"';
        return true;
    }
};};//TENS