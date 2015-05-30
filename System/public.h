// stdafx.h�: fichier Include pour les fichiers Include syst�me standard,
// ou les fichiers Include sp�cifiques aux projets qui sont utilis�s fr�quemment,
// et sont rarement modifi�s
//

#ifndef SYSTEM_PUBLIC
#define SYSTEM_PUBLIC



#define _BEGIN_TE_SYSTEM_NAMESPACE namespace TrustEngine{ namespace System{
#define _END_TE_SYSTEM_NAMESPACE };};//TENS


#if defined WIN32
    #include "WindowsPublic.h"
#elif defined __LINUX__
    #include "LinuxPublic.h"
#endif // __LINUX__




#pragma warning( disable : 4530)

//common includes
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <assert.h>


//System Lib includes

#include "Macro.h"
#include "Meta.h"
#include "VectorHelper.h"
#include "MapHelper.h"
#include "StringHelper.h"
//#include "Guid.h"
#include "Input.h"



#endif