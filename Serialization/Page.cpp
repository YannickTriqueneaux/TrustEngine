

namespace TrustEngine{ namespace Serialization{
    
    using Formats::JSON;

    template<typename FORMAT>
    Page<FORMAT>::Page(){}

    bool Page<JSON>::print(std::ostream & streamResult) const {
        assert(content && "Page::print empty page");
        streamResult << '{' << std::endl;
        auto succeed = content->print(streamResult);
        streamResult << std::endl << '}' << std::endl;
        return succeed;
    }


};};//TENS