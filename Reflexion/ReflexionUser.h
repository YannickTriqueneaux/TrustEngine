_BEGIN_TE_REFLEXION_NAMESPACE

class NO_PARENT_CLASS{
public:
    static Descriptor const * getClassDescriptor(){return nullptr;}
};


#define REFLECTED_CLASS\
    public:\
    virtual TrustEngine::Reflexion::Descriptor const * getDescriptor() const; \
    static TrustEngine::Reflexion::Descriptor const * getClassDescriptor(); \
    static const bool isTemplateClass = false;\
    static std::string const & getClassName();\
    private:\
    typedef TrustEngine::Reflexion::NO_PARENT_CLASS R_ParentClass;



#define REFLECTED_SUPER_CLASS(ParentClass)\
    public:\
    virtual TrustEngine::Reflexion::Descriptor const * getDescriptor() const;\
    static TrustEngine::Reflexion::Descriptor const * getClassDescriptor();\
    static const bool isTemplateClass = false;\
    static std::string const & getClassName();\
    private:\
    typedef ParentClass R_ParentClass;

#define REFLECTED_TEMPLATE_CLASS\
    private:\
    typedef NO_PARENT_CLASS R_ParentClass; \

#define REFLECTED_SUPER_TEMPLATE_CLASS(ParentClass)\
    private:\
    typedef ParentClass R_ParentClass; \



#define DEFINE_CLASS_BEGIN(ClassName)\
    TrustEngine::Reflexion::Descriptor const * ClassName::getDescriptor() const{\
        return ClassName::getClassDescriptor();\
    }\
    std::string const & ClassName::getClassName(){\
        static const std::string instanceTypeName(_stringize(ClassName));\
        return instanceTypeName;\
    }\
    TrustEngine::Reflexion::Descriptor const * ClassName::getClassDescriptor(){\
        using namespace TrustEngine::Reflexion;\
        static Descriptor const * descriptor = nullptr;\
        if(descriptor){\
            return descriptor;\
                                        }\
        descriptor = DescriptorRegistry::getDescriptor(_stringize(ClassName));\
        if(descriptor != nullptr){\
            return descriptor;\
                                        }\
        ClassName * memory = nullptr;\
        Descriptor * newDescriptor = DescriptorRegistry::createDescriptor<GenericDescriptor<ClassName>>();\
        newDescriptor->setParentClassDescriptor(R_ParentClass::getClassDescriptor());


#define DEFINE_FIELD(fieldname)\
    TrustEngine::Reflexion::Field const * field_##fieldname =  newDescriptor->addField(_stringize(fieldname),&memory->fieldname)

#define DEFINE_CLASS_END\
    descriptor = newDescriptor;\
    return descriptor;\
    }

#define TEMPLATE_CLASS_BEGIN(ClassName,InferType)\
private:\
    typedef InferType _InferType; \
    static const int inferTypeNumber = 1;\
    static const bool isTemplateClass = true;\
    friend class TrustEngine::Reflexion::GenericDescriptor< ClassName<InferType> > ;\
public:\
    static std::string const & getClassName(){\
        using namespace TrustEngine::Reflexion;\
        static std::string const templateClassName = std::string(_stringize(ClassName)).append("<").append(DescriptorHelper<InferType>::DescriptorType::getInstanceTypeName()).append(">");\
        return templateClassName;\
    }\
    TrustEngine::Reflexion::Descriptor const * getDescriptor() const{\
        return ClassName<InferType>::getClassDescriptor();\
    }\
    static TrustEngine::Reflexion::Descriptor const * getClassDescriptor(){\
        using namespace TrustEngine::Reflexion;\
        static Descriptor const * descriptor = nullptr;\
        if (descriptor){\
            return descriptor;\
        }\
        descriptor = DescriptorRegistry::getDescriptor(getClassName());\
        if (descriptor != nullptr){\
            return descriptor;\
        }\
        ClassName<InferType> * memory = nullptr;\
        GenericDescriptor<ClassName<InferType>> * newDescriptor = (GenericDescriptor<ClassName<InferType>>*)DescriptorRegistry::createDescriptor<GenericDescriptor<ClassName<InferType>>>();\
        newDescriptor->setParentClassDescriptor(R_ParentClass::getClassDescriptor());\
        newDescriptor->addInferType<InferType>();



_END_TE_REFLEXION_NAMESPACE