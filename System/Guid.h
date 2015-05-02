

class Guid
{
public:
    static std::string generate(){
        GUID gidReference;
        HRESULT hCreateGuid = ::CoCreateGuid(&gidReference);

        OLECHAR* bstrGuid;
        StringFromCLSID(gidReference, &bstrGuid);

        std::wstring wstrGuid(bstrGuid);

        std::string strGuid = StringHelper::wstringToString(wstrGuid);

        ::CoTaskMemFree(bstrGuid);
        return std::move(strGuid);
    }
};

