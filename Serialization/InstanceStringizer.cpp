#include "private.h"

namespace TrustEngine{
    namespace Serialization{

        using Reflexion::Instance;

        bool InstanceStringizer::instanceToString(std::ostream & streamResult, Instance const & instance){
            if (!instance.isEmpty()
                && instance.getType()->isStringizable()){
                instance.getType()->stringize(streamResult, instance);
            }
            return false;
        }

    };
};//TENS