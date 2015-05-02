#ifndef STRING_HELPER
#define STRING_HELPER

_BEGIN_TE_SYSTEM_NAMESPACE

namespace StringHelper{

    std::wstring stringToWString(std::string const & str);
    std::string wstringToString(std::wstring const & wstr);

};

_END_TE_SYSTEM_NAMESPACE 

#endif//STRING_HELPER