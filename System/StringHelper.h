#ifndef STRING_HELPER
#define STRING_HELPER

namespace StringHelper{

    std::wstring stringToWString(std::string const & str);
    std::string wstringToString(std::wstring const & wstr);

};

#endif//STRING_HELPER