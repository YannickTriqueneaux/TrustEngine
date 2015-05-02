#ifndef STRING_HELPER
#define STRING_HELPER

BEGIN_TE_SYSTEM_NAMESPACE

namespace StringHelper{

    std::wstring stringToWString(std::string const & str);
    std::string wstringToString(std::wstring const & wstr);

};

END_TE_SYSTEM_NAMESPACE 

#endif//STRING_HELPER