#ifndef STRING_HELPER
#define STRING_HELPER

namespace TrustEngine{ namespace System{

namespace StringHelper{

    std::wstring stringToWString(std::string const & str);
    std::string wstringToString(std::wstring const & wstr);

    const std::string EmptyString = "";

    struct Tab{
        static const int _NB_SPACE_BY_TAB;
        static std::string _put(int nbTab);
    };

};

};};//TENS 

#endif//STRING_HELPER