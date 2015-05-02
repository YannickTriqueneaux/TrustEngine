_BEGIN_TE_SYSTEM_NAMESPACE

namespace StringHelper{

    std::wstring stringToWString(std::string const & str)
    {
        typedef std::codecvt_utf8<wchar_t> convert_type;
        std::wstring_convert<convert_type, wchar_t> converterX;

        return std::move(converterX.from_bytes(str));
    }

    std::string wstringToString(std::wstring const & wstr)
    {
        typedef std::codecvt_utf8<wchar_t> convert_type;
        std::wstring_convert<convert_type, wchar_t> converterX;

        return std::move(converterX.to_bytes(wstr));
    }

};

_END_TE_SYSTEM_NAMESPACE