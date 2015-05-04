

namespace TrustEngine{ namespace Reflexion{
    class StringizableDescriptor : public Descriptor{
    public:
        virtual bool isStringizable() const {
            return true;
        };
        virtual bool isABoolean() const {
            return false;
        }
        virtual bool isANumber() const {
            return false;
        }
        bool isAString() const {
            return false;
        }


        virtual void stringize(std::ostream & streamResult, Instance const & instance) const = 0;
    };
};};//TENS