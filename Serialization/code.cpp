
#include "private.h"


//sources
#include "Value.cpp"
#include "Stringizable.cpp"
#include "Object.cpp"
#include "Array.cpp"
#include "Page.cpp"

#include "InstanceParser.cpp"
#include "InstanceSerializer.cpp"

namespace TrustEngine{ namespace Serialization{
    namespace PreCompiling{
        Page < Formats::JSON > jsonpage;
    };
};};//TENS