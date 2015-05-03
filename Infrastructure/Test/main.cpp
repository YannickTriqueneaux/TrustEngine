
#include "..\Infrastructure\public.h"


namespace MyNameSpace{

	class ParentClass{
		REFLECTED_CLASS
	public:
		int intvalue;
	};
};

DEFINE_CLASS_BEGIN(MyNameSpace::ParentClass)
	DEFINE_FIELD(intvalue);
DEFINE_CLASS_END

void main(){
    using namespace MyNameSpace;
    using namespace TrustEngine::Reflexion;
    using TrustEngine::System::Guid;

	ParentClass test;
	auto descriptor = test.getDescriptor();

    DescriptorRegistry::_printDescriptorList();

    Guid::_generate();
}