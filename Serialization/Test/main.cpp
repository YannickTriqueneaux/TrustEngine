
#include "..\public.h"


namespace MyNameSpace{

    class ParentClass{
        REFLECTED_CLASS
    public:
        ParentClass(){
            std::cout << "ParentInstance(" << simpleint << ") create" ;
        }
        ParentClass(ParentClass const & other){
            std::cout << "ParentInstance(" << simpleint << ") copy";
        }
        ParentClass(ParentClass && other){
            std::swap(simpleint, other.simpleint);
            std::cout << "ParentInstance(" << simpleint << ") move";
        }
        ParentClass & operator=(ParentClass const & other){
            std::cout << "ParentInstance(" << simpleint << ") assign";
            return *this;
        }
        virtual ~ParentClass(){
            std::cout << "ParentInstance(" << simpleint << ") destroy";
            simpleint = -1;
        }
        int simpleint = 0;;
    };
    class SuperClass{
        REFLECTED_CLASS
    public:
        SuperClass(){}
        SuperClass(int val) : intvalue(val){}
        int intvalue = 5;
        float floatvalue = 56.0f;
        int * valuePtr = nullptr;
        std::string stringvalue;
        std::vector<int> vectorint;
        std::vector<ParentClass> vectorObject;
        std::vector<std::vector<ParentClass>> vector2Object;
        std::vector<std::vector<std::string>> vectorstring;
        std::map<std::string, std::map<int, ParentClass>> supermapfield;
        std::pair<int, int> superpair;
    };
    //
    class ChildClass : public ParentClass {
        REFLECTED_SUPER_CLASS(ParentClass)
    public:
        int secondValue;
        std::string superstring;
    };
    //
    template<typename T>
    class TempClass : public ChildClass {
        REFLECTED_SUPER_TEMPLATE_CLASS(ChildClass)
    public:
        TempClass(){}
        T value;
        TEMPLATE_CLASS_BEGIN(MyNameSpace::TempClass, T)
            DEFINE_FIELD(value);
        DEFINE_CLASS_END
    };

    class TemplChild : public TempClass < int > {
        REFLECTED_SUPER_CLASS(TempClass<int>)
    public:
        TemplChild(){}
        std::string souris;
    };


    struct ComposedObject{
        REFLECTED_CLASS
    public:
        ComposedObject(){}

        TemplChild templatedInt;
    };

};

DEFINE_CLASS_BEGIN(MyNameSpace::SuperClass)
DEFINE_FIELD(intvalue);
DEFINE_FIELD(floatvalue);
DEFINE_FIELD(stringvalue);
DEFINE_FIELD(vectorint);
DEFINE_FIELD(vectorObject);
DEFINE_FIELD(vector2Object);
DEFINE_FIELD(vectorstring);
DEFINE_FIELD(supermapfield);
DEFINE_FIELD(superpair);
DEFINE_CLASS_END

DEFINE_CLASS_BEGIN(MyNameSpace::ParentClass)
DEFINE_FIELD(simpleint);
DEFINE_CLASS_END
//
DEFINE_CLASS_BEGIN(MyNameSpace::ChildClass)
DEFINE_FIELD(secondValue);
DEFINE_FIELD(superstring);
DEFINE_CLASS_END

DEFINE_CLASS_BEGIN(MyNameSpace::TemplChild)
DEFINE_FIELD(souris);
DEFINE_CLASS_END

DEFINE_CLASS_BEGIN(MyNameSpace::ComposedObject)
DEFINE_FIELD(templatedInt);
DEFINE_CLASS_END


using namespace MyNameSpace;
using namespace TrustEngine::System;
using namespace TrustEngine::Reflexion;
using namespace TrustEngine::Serialization;



void main(){
    ComposedObject parent;
    Instance instance(&parent);
    InstanceSerializer<Formats::JSON> serializer(instance);
    std::stringstream stream;
    serializer.serialize(stream);
    std::cout << std::endl << std::endl;
    std::cout << stream.str();///problem with string !!go test that !

    Input::_waitKey();
}