#ifndef SERIALIZATION_PUBLIC
#define SERIALIZATION_PUBLIC


#define _BEGIN_TE_SERIALIZATION_NAMESPACE namespace TrustEngine{ namespace Serialization{
#define _END_TE_SERIALIZATION_NAMESPACE };};//TENS

//dependencies
#include "..\Reflexion\public.h"

//include
#include "InstanceStringizer.h"


template<typename FORMAT>
class Value;

#include "Formats.h"
#include "Object.h"
#include "Array.h"
#include "Page.h"
#include "Value.h"


//supported formats
//Formats::JSON



#endif