namespace TrustEngine{ namespace Serialization{
    using Formats::JSON;


    template<typename FORMAT>
    bool fillPage(Page<FORMAT> & page, Instance const & instance){
        if (instance.isEmpty()){
            page.setContent(new NullValue<FORMAT>());
            return true;
        }
        auto instanceDesc = instance.getType();
        if (instanceDesc->isAnArray()){

        }
        else if (instanceDesc->isAGeneric()){
            ObjectValue<FORMAT> * objectvalue = new ObjectValue<FORMAT>();
            objectvalue->content = new Object<FORMAT>(instanceDesc->getInstanceTypename(), 1);
            page.setContent(objectvalue);
            return fillObject<FORMAT>(*objectvalue, instance);
        }
        else if (instanceDesc->isStringizable()){
            /*ObjectValue<FORMAT> * objectvalue = new ObjectValue<FORMAT>();
            objectvalue->content = new Object<FORMAT>(instanceDesc->getInstanceTypename(), 1);
            page.setContent(objectvalue);
            return fillObject<FORMAT>(*objectvalue, instance);*/
        }

    }

    template<typename FORMAT>
    bool fillObject(ObjectValue<FORMAT> & objectvalue, Instance const & instance){
        auto map = objectvalue.content->getContent();

        
        
        return true;
    }


    template<>
    bool InstanceParser<JSON>::parse(){
        return fillPage<JSON>(page, instance);
    }

};};//TENS