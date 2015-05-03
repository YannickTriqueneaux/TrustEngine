

namespace TrustEngine{ namespace Serialization{
    
    using Formats::JSON;

    template<typename FORMAT>
    Page<FORMAT>::Page() :content("",1){}

    bool Page<JSON>::print(std::ostream & streamResult) const {
        content.print(streamResult);
        return false;
    }


};};//TENS