

namespace TrustEngine{ namespace Reflexion{
    class StringizableDescriptor : public Descriptor{
    public:
        virtual bool isStringizable() const {
            return true;
        };


        virtual void stringize(std::ostream & streamResult, Instance const & instance) const = 0;
    };
};};//TENS