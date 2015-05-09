#ifndef STRING_HELPER
#define STRING_HELPER

namespace TrustEngine{ namespace System{

namespace StringHelper{

    std::wstring stringToWString(std::string const & str);
    std::string wstringToString(std::wstring const & wstr);

    const std::string EmptyString = "";

    struct Tab{
        static std::string _put(int nbTab);
    };

};

};};//TENS 

#endif//STRING_HELPER