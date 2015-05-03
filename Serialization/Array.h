namespace TrustEngine{ namespace Serialization{


    template<typename FORMAT>
    class Array{
    public:
        Array(int indentrange);

        bool print(std::ostream & streamResult);
    private:
        int indentRange = 0;
        std::vector<Value<FORMAT>> content;
    };
    
};};//TENS