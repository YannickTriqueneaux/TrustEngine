namespace TrustEngine{ namespace Serialization{
    using Formats::JSON;

    template<>
    bool InstanceParser<JSON>::parse(){
        return normalParse<JSON>(page, instance);
    }

    template<typename FORMAT>
    bool normalParse(Page & page, Instance const & instance){
        
    }

};};//TENS