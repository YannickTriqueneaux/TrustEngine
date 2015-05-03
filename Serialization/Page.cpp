

namespace TrustEngine{ namespace Serialization{
    
    using Formats::JSON;

    template<typename FORMAT>
    Page<FORMAT>::Page() :content(1){}

    bool Page<JSON>::print(std::ostream & streamResult){
        streamResult << '{' << std::endl;
        if (content.print(streamResult)){
            streamResult << '}';
            return true;
        }
        return false;
    }


};};//TENS