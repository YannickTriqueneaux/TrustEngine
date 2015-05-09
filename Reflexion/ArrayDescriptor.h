

namespace TrustEngine{ namespace Reflexion{

    class ArrayDescriptor : public Descriptor{
    public:
        virtual bool isAnArray() const { 
            return true;
        }
        virtual std::vector<Instance> getInstancesOfElements(Instance const & arrayInstance) const = 0;
    };
};};//TENS