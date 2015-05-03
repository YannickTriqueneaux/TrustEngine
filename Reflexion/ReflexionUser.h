namespace TrustEngine{ namespace Reflexion{

class NO_PARENT_CLASS{
public:
    static Descriptor const * _getClassDescriptor(){ return nullptr; }
};


#define REFLECTED_CLASS\
    public:\
    virtual TrustEngine::Reflexion::Descriptor const * getDescriptor() const; \
    static TrustEngine::Reflexion::Descriptor const * _getClassDescriptor(); \
    static const bool _isTemplateClass = false;\
    static std::string const & _getClassName();\
    private:\
    typedef TrustEngine::Reflexion::NO_PARENT_CLASS Reflected_ParentClass;



#define REFLECTED_SUPER_CLASS(ParentClass)\
    public:\
    virtual TrustEngine::Reflexion::Descriptor const * getDescriptor() const;\
    static TrustEngine::Reflexion::Descriptor const * _getClassDescriptor();\
    static const bool _isTemplateClass = false;\
    static std::string const & _getClassName();\
    private:\
    typedef ParentClass Reflected_ParentClass;

#define REFLECTED_TEMPLATE_CLASS\
    private:\
    typedef NO_PARENT_CLASS Reflected_ParentClass; \

#define REFLECTED_SUPER_TEMPLATE_CLASS(ParentClass)\
    private:\
    typedef ParentClass Reflected_ParentClass; \



#define DEFINE_CLASS_BEGIN(ClassName)\
    TrustEngine::Reflexion::Descriptor const * ClassName::getDescriptor() const{\
        return ClassName::_getClassDescriptor();\
    }\
    std::string const & ClassName::_getClassName(){\
        static const std::string _instanceTypeName(_stringize(ClassName));\
        return _instanceTypeName;\
    }\
    TrustEngine::Reflexion::Descriptor const * ClassName::_getClassDescriptor(){\
        using namespace TrustEngine::Reflexion;\
        static Descriptor const * _descriptor = nullptr;\
        if(_descriptor){\
            return _descriptor;\
                                        }\
        _descriptor = DescriptorRegistry::_getDescriptor(_stringize(ClassName));\
        if(_descriptor != nullptr){\
            return _descriptor;\
                                        }\
        ClassName * memory = nullptr;\
        Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<GenericDescriptor<ClassName>>();\
        newDescriptor->setParentClassDescriptor(Reflected_ParentClass::_getClassDescriptor());


#define DEFINE_FIELD(fieldname)\
    TrustEngine::Reflexion::Field const * field_##fieldname =  newDescriptor->addField(_stringize(fieldname),&memory->fieldname)

#define DEFINE_CLASS_END\
    _descriptor = newDescriptor;\
    return _descriptor;\
    }

#define TEMPLATE_CLASS_BEGIN(ClassName,InferType)\
private:\
    typedef InferType _InferType; \
    static const int _inferTypeNumber = 1;\
    static const bool _isTemplateClass = true;\
    friend class TrustEngine::Reflexion::GenericDescriptor< ClassName<InferType> > ;\
public:\
    static std::string const & _getClassName(){\
        using namespace TrustEngine::Reflexion;\
        static std::string const templateClassName = std::string(_stringize(ClassName)).append("<").append(DescriptorHelper<InferType>::DescriptorType::_getInstanceTypeName()).append(">");\
        return templateClassName;\
    }\
    virtual TrustEngine::Reflexion::Descriptor const * getDescriptor() const {\
        return ClassName<InferType>::_getClassDescriptor();\
    }\
    static TrustEngine::Reflexion::Descriptor const * _getClassDescriptor(){\
        using namespace TrustEngine::Reflexion;\
        static Descriptor const * _descriptor = nullptr;\
        if (_descriptor){\
            return _descriptor;\
        }\
        _descriptor = DescriptorRegistry::_getDescriptor(_getClassName());\
        if (_descriptor != nullptr){\
            return _descriptor;\
        }\
        ClassName<InferType> * memory = nullptr;\
        GenericDescriptor<ClassName<InferType>> * newDescriptor = (GenericDescriptor<ClassName<InferType>>*)DescriptorRegistry::_createDescriptor<GenericDescriptor<ClassName<InferType>>>();\
        newDescriptor->setParentClassDescriptor(Reflected_ParentClass::_getClassDescriptor());\
        newDescriptor->addInferType<InferType>();



};};//TENS