namespace TrustEngine{ namespace Serialization{

    using TrustEngine::System::StringHelper::Tab;

    template<typename FORMAT>
    Array<FORMAT>::Array(int indentrange) :indentRange(indentrange){}

    template<>
    bool Array<Formats::JSON>::print(std::ostream & streamResult){
        streamResult << '[';
        streamResult << Tab::put(indentRange);
        return true;
    }


};};//TENS