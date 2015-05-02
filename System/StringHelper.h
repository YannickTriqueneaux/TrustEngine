#ifndef STRING_HELPER
#define STRING_HELPER

namespace TrustEngine{ namespace System{

namespace StringHelper{

    std::wstring stringToWString(std::string const & str);
    std::string wstringToString(std::wstring const & wstr);

};

};};//TENS 

#endif//STRING_HELPER