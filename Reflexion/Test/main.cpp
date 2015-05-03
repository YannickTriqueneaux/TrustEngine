
#include "..\Reflexion\public.h"


namespace MyNameSpace{

class ParentClass{
    REFLECTED_CLASS
public:
    int simpleint;
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



void testDescritporGetting(){
    std::string tl(_stringize(heyyyeyed));
    getDescriptorOf<ParentClass>();
    getDescriptorOf<SuperClass>();
    getDescriptorOf<ChildClass>();
    getDescriptorOf<TempClass<SuperClass>>();
    getDescriptorOf<TemplChild>();
    DescriptorRegistry::_printDescriptorList();
}

void testFieldInstanceGetting(){
    ChildClass child;
    Instance childInstance(&child);
    assert(!childInstance.isEmpty());


    auto instancePtr = childInstance.get();
    assert(instancePtr == &child);

    auto instanceDesc = childInstance.getType();
    assert(instanceDesc == getDescriptorOf(child));

    Field const * secondValueField = instanceDesc->getField("secondValue");
    assert(secondValueField);

    assert(instanceDesc->containsField(*secondValueField));

    FieldInstance fieldInstance(childInstance, *secondValueField);

    assert(&child.secondValue == fieldInstance.getInstance().get());
    assert(getDescriptorOf(child.secondValue) == fieldInstance.getInstance().getType());


    assert(instanceDesc->containsField(*secondValueField));

    //inherit class field access
    auto inheritIntValueField = instanceDesc->getField("simpleint");
    assert(inheritIntValueField);

    assert(inheritIntValueField->getName() == "simpleint");

    FieldInstance inheritFieldInstance(childInstance, *inheritIntValueField);


    assert(&child.simpleint == inheritFieldInstance.getInstance().get());
    assert(getDescriptorOf(child.simpleint) == inheritFieldInstance.getInstance().getType());
}




void testFieldInstanceNavigation(){

    //check descriptors
    ComposedObject compObject;

    auto compObjectDesc = compObject.getDescriptor();
    assert(compObjectDesc);

    Instance compObjectInstance(&compObject);
    assert(!compObjectInstance.isEmpty());

    compObjectDesc->containsField("templatedInt");

    auto fieldDesc = getDescriptorOf(compObject.templatedInt);
    assert(fieldDesc);

    assert(fieldDesc->containsField("souris"));

    auto valueField = fieldDesc->getField("value");
    assert(valueField);

    assert(getDescriptorOf(compObject.templatedInt.value) == &valueField->getType());


    //check navigation
    Field const * templateField = compObjectDesc->getField("templatedInt");
    assert(templateField);
    FieldInstance fieldMoverInstance(compObjectInstance, *templateField);

    auto fieldInstance = fieldMoverInstance.getInstance();
    assert(!fieldInstance.isEmpty());

    FieldInstance fiCopy = fieldMoverInstance;
    assert(!fiCopy.getInstance().isEmpty());
    assert(fiCopy == fieldMoverInstance);

    auto superClassField = getDescriptorOf<SuperClass>()->getField("floatvalue");
    assert(superClassField);

    assert(!fieldMoverInstance.moveToChild(*superClassField));//mus fail

    assert(fiCopy == fieldMoverInstance);//normally fieldMoverInstance does not change because moveToChild has failed 

    auto parentClassField = getDescriptorOf<ParentClass>()->getField("simpleint");
    assert(parentClassField);


    assert(fieldMoverInstance.moveToChild(*parentClassField));//must succeed
    assert(fiCopy != fieldMoverInstance);

    assert(!fieldMoverInstance.getInstance().isEmpty());
    assert(fieldMoverInstance.getInstance().get() == &compObject.templatedInt.simpleint);
}


void main(){

    testDescritporGetting();
    Input::_waitKey();


    testFieldInstanceGetting();
    Input::_waitKey();

    testFieldInstanceNavigation();
    Input::_waitKey();
}