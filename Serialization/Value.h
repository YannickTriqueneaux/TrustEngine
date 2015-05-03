namespace TrustEngine{ namespace Serialization{
    using Reflexion::Instance;

    template<typename FORMAT>
    class Value{
    public:
        virtual bool print(std::ostream & streamResult) const = 0;
    };

    template<typename FORMAT>
    class StringValue : public Value<FORMAT>{
    public:
        StringValue(Instance const & instancevalue);

        virtual bool print(std::ostream & streamResult) const ;
    private:
        Instance content;
    };

    template<typename FORMAT>
    class NumberValue : public Value < FORMAT > {
    public:
        NumberValue(Instance const & instancevalue);

        virtual bool print(std::ostream & streamResult) const ;
    private:
        Instance content;
    };

    template<typename FORMAT>
    class ArrayValue : public Value < FORMAT > {
    public:

        virtual bool print(std::ostream & streamResult) const ;

        Array<FORMAT> content;
    };

    template<typename FORMAT>
    class ObjectValue : public Value < FORMAT > {
    public:
        virtual bool print(std::ostream & streamResult) const ;

        Object<FORMAT> * content;
    };


    template<typename FORMAT>
    class BooleanValue : public Value < FORMAT > {
    public:
        BooleanValue(bool value);

        virtual bool print(std::ostream & streamResult) const ;
    private:
        bool content;
    };

    template<typename FORMAT>
    class NullValue : public Value < FORMAT > {
    public:
        virtual bool print(std::ostream & streamResult) const ;
    };


};};//TENS