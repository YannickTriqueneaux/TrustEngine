namespace TrustEngine{ namespace System{

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

    //Tabulation
    const int Tab::_NB_SPACE_BY_TAB = 4;
    std::string Tab::_put(int nbTab){
        std::string result;
        auto nbSpace = nbTab * _NB_SPACE_BY_TAB;
        result.reserve(nbSpace);
        result.resize(nbSpace);
        for (auto i = 0; i < nbSpace; ++i){
            result[i] = ' ';
        }
        return std::move(result);
    }
};

};};//TENS