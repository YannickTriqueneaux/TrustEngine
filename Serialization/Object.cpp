namespace TrustEngine{ namespace Serialization{
    using TrustEngine::System::StringHelper::Tab;

    template<typename FORMAT>
    Object<FORMAT>::Object(int indentrange) :indentRange(indentrange){}

    template<>
    bool Object<Formats::JSON>::print(std::ostream & streamResult){
        streamResult << '[';
        streamResult << Tab::put(indentRange);
        return true;
    }
};};//TENS