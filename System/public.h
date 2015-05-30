// stdafx.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets qui sont utilisés fréquemment,
// et sont rarement modifiés
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