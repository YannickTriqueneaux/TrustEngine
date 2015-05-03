#include "private.h"

namespace TrustEngine{
    namespace Serialization{

        using Reflexion::Instance;

        bool InstanceStringizer::instanceToString(std::ostream & streamResult, Instance const & instance){
            if (!instance.isEmpty()
                && instance.getType()->isStringizable()){
                streamResult << instance.getType()->stringize(instance);
            }
            return false;
        }

    };
};//TENS