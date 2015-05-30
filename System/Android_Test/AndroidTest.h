#include <jni.h>

#include "Logs.h"
#include <vector>
#include <string>

#define TEST(TestClassName,strName) \
    struct TestClassName##Test{ static int run(); };\
    int TestClassName##registred = AndroidTestMananger::get().registerNewTest(strName,TestClassName##Test::run);\
    int TestClassName##Test::run()

#define FAILURE 0;
#define SUCCESS 1;
#define verify(arg) if(true != arg) {LOGE("Verify ERROR: %s - LINE:(%d)",#arg, __LINE__);return FAILURE;}
#define check(arg) if(SUCCESS != arg) {LOGE("Check ERROR: %s - LINE:(%d)",#arg, __LINE__);return FAILURE;}

template<typename TestFuncType>
struct UnitaryTest{
    UnitaryTest(std::string const & l, TestFuncType f) :label(l), func(f){}
    std::string label;
    TestFuncType func;
};

class AndroidTestMananger{
    AndroidTestMananger(){}
    AndroidTestMananger(AndroidTestMananger const &){}
    AndroidTestMananger & operator=(AndroidTestMananger const &){}
public:
    static AndroidTestMananger & get(){
        static AndroidTestMananger instance;
        return instance;
    }
    typedef int(*TestFunctionType)();
    std::vector<UnitaryTest<TestFunctionType>> testlist;
    int registerNewTest(std::string const & label, int(*func)()){
        testlist.push_back(UnitaryTest<TestFunctionType>(label, func));
        return SUCCESS;
    }
    int executeTests(){
        auto end = testlist.end();
        LOGI("\n\n");
        for (auto ite = testlist.begin(); ite != end; ++ite){
            auto label = ite->label.c_str();
            LOGI("----  Executing test %s ----", label);
            int state = ite->func();
            LOGI("Test %s - Status : %s\n\n", label, !state ? "FAILURE!" : "!SUCCEED");
        }
    }
};
