namespace TrustEngine{ namespace Serialization{
    
    using Formats::JSON; 
    using Reflexion::Instance;

    template<>
    bool ArrayValue< JSON >::print(std::ostream & streamResult) {
        return content.print(streamResult);
    }

    template<>
    bool ObjectValue< JSON >::print(std::ostream & streamResult) {
        return content.print(streamResult);
    }

    template<>
    bool BooleanValue< JSON >::print(std::ostream & streamResult) {
        if (content){
            streamResult << "true";
        }
        else{
            streamResult << "false";
        }
        return true;
    }

    template<>
    bool NullValue< JSON >::print(std::ostream & streamResult) {
        streamResult << "null";
        return true;
    }


    template<>
    bool StringValue<JSON>::print(std::ostream & streamResult){
        streamResult << '"';
        streamResult << InstanceStringizer::instanceToString(content);
        streamResult << '"';
        return true;
    }
};};//TENS