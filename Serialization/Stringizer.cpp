#include "private.h"

namespace TrustEngine{
    namespace Serialization{

        using Reflexion::Instance;

        bool Stringizer::instanceToString(std::ostream & streamResult, Instance const & instance){
            if (!instance.isEmpty()
                && instance.getType()->isStringizable()){
                static_cast<Reflexion::StringizableDescriptor const*>(instance.getType())->stringize(streamResult, instance);
            }
            return false;
        }

    };
};//TENS