
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
	ParentClass test;
	auto descriptor = test.getDescriptor();

	DescriptorRegistry::printDescriptorList();

    Guid::generate();
}