

namespace TrustEngine{ namespace Reflexion{

    class ArrayDescriptor : public Descriptor{
    public:
        virtual bool isAnArray()const { 
            return true;
        }
    };
};};//TENS