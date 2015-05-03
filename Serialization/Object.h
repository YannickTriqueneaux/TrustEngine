namespace TrustEngine{ namespace Serialization{

    template<typename FORMAT>
    class Object{
    public:
        Object(int indentrange);

        bool print(std::ostream & streamResult);
    private:
        int indentRange = 0;
        std::map<std::string,Value<FORMAT>> content;
    };
};};//TENS