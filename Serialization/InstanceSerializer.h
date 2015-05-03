

namespace TrustEngine{ namespace Serialization{
    using Reflexion::Instance;

    template<typename FORMAT>
    class InstanceSerializer{
    public:
        InstanceSerializer(Instance const & instanceToSerialize) :instance(instanceToSerialize){}

        bool serialize(std::ostream & streamResult);
    private:
        Instance instance;
        Page<FORMAT> page;
        bool alreadyParsed = false;
    };

};};//TENS