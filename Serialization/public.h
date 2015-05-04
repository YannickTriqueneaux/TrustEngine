#ifndef SERIALIZATION_PUBLIC
#define SERIALIZATION_PUBLIC


#define _BEGIN_TE_SERIALIZATION_NAMESPACE namespace TrustEngine{ namespace Serialization{
#define _END_TE_SERIALIZATION_NAMESPACE };};//TENS

//dependencies
#include "..\Reflexion\public.h"

template<typename FORMAT>
class Value;

//includes
#include "Formats.h"
#include "Element.h"
#include "Stringizable.h"
#include "Object.h"
#include "Array.h"
#include "Page.h"
#include "Value.h"

#include "InstanceParser.h"
#include "InstanceSerializer.h"


//supported formats
//Formats::JSON



#endif