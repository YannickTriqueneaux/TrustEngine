
class NO_PARENT_CLASS{
public:
	static Descriptor const * getClassDescriptor(){return nullptr;}
};


#define REFLECTED_CLASS\
	public:\
	virtual Descriptor const * getDescriptor() const; \
	static Descriptor const * getClassDescriptor(); \
	static const bool isTemplateClass = false;\
	static std::string const & getClassName();\
	private:\
	typedef NO_PARENT_CLASS R_ParentClass;



#define REFLECTED_SUPER_CLASS(ParentClass)\
	public:\
	virtual Descriptor const * getDescriptor() const;\
	static Descriptor const * getClassDescriptor();\
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
	Descriptor const * ClassName::getDescriptor() const{\
		return ClassName::getClassDescriptor();\
	}\
	std::string const & ClassName::getClassName(){\
		static const std::string instanceTypeName(stringize(ClassName));\
		return instanceTypeName;\
	}\
	Descriptor const * ClassName::getClassDescriptor(){\
		static Descriptor const * descriptor = nullptr;\
		if(descriptor){\
			return descriptor;\
										}\
		descriptor = DescriptorRegistry::getDescriptor(stringize(ClassName));\
		if(descriptor != nullptr){\
			return descriptor;\
										}\
		ClassName * memory = nullptr;\
		Descriptor * newDescriptor = DescriptorRegistry::createDescriptor<GenericDescriptor<ClassName>>();\
		newDescriptor->setParentClassDescriptor(R_ParentClass::getClassDescriptor());


#define DEFINE_FIELD(fieldname)\
	Field const * field_##fieldname =  newDescriptor->addField(stringize(fieldname),&memory->fieldname)

#define DEFINE_CLASS_END\
	descriptor = newDescriptor;\
	return descriptor;\
	}

#define TEMPLATE_CLASS_BEGIN(ClassName,InferType)\
private:\
	typedef InferType _InferType; \
	static const int inferTypeNumber = 1;\
	static const bool isTemplateClass = true;\
	friend class GenericDescriptor < ClassName<InferType> > ;\
public:\
	static std::string const & getClassName(){\
		static std::string const templateClassName = std::string(stringize(ClassName)).append("<").append(DescriptorHelper<InferType>::DescriptorType::getInstanceTypeName()).append(">");\
		return templateClassName;\
	}\
	Descriptor const * getDescriptor() const{\
		return ClassName<InferType>::getClassDescriptor();\
	}\
	static Descriptor const * getClassDescriptor(){\
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
