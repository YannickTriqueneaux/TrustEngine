namespace TrustEngine{ namespace Serialization{
    using Formats::JSON;
    using namespace Reflexion;


    template<typename FORMAT>
    bool fillPage(Page<FORMAT> & page, Instance const & instance){
        Element<FORMAT> * value = nullptr;
        bool succeed = getElementFormInstance(value, instance, nullptr, 1);
        page.content = value;
        return succeed;
    }

    template<typename FORMAT>
    bool getElementFormInstance(Element<FORMAT> *& valueResult, Instance const & instance, Field const * field, int indent){
        auto instanceDesc = instance.getType();
        auto & instancelabel = field ? field->getName() : instanceDesc->getInstanceTypename();

        if (instance.isEmpty()){
            Stringizable< FORMAT > * nullElement = new Stringizable < FORMAT >(instancelabel, indent);
            nullElement->value = new NullValue < FORMAT >;
            valueResult = nullElement;
            return true;
        }
        if (instanceDesc->isAnArray()){
            Array<FORMAT> * arrayElement = new Array<FORMAT>(instancelabel, indent);
            auto succeed = fillArray<FORMAT>(*arrayElement, instance);
            arrayElement = arrayElement;
            return succeed;
        }
        else if (instanceDesc->isAGeneric()){
            Object<FORMAT> * objectvalue = new Object < FORMAT >(instancelabel, indent);
            auto succeed = fillObject<FORMAT>(*objectvalue, instance);
            valueResult = objectvalue;
            return succeed;
        }
        else if (instanceDesc->isStringizable()){
            Stringizable<FORMAT> * strElement = new Stringizable < FORMAT >(instancelabel, indent);
            valueResult = strElement;
            StringizableDescriptor const * strDesc = static_cast<StringizableDescriptor const*>(instanceDesc);
            if (strDesc->isAString()){
                StringValue<FORMAT> * stringValue = new StringValue < FORMAT > ;
                stringValue->content = instance;
                strElement->value = stringValue;
                return true;
            }
            else if (strDesc->isANumber()){
                NumberValue<FORMAT> * numberValue = new NumberValue < FORMAT > ;
                numberValue->content = instance;
                strElement->value = numberValue;
                return true;
            }
            else if (strDesc->isABoolean()){
                BooleanValue<FORMAT> * boolValue = new BooleanValue < FORMAT > ;
                boolValue->content = instance;
                strElement->value = boolValue;
                return true;
            }
        }
        return false;
    }

    template<typename FORMAT>
    bool fillObject(Object<FORMAT> & objectvalue, Instance const & instance){
        bool succeed = true;
        auto & map = objectvalue.members;
        auto descriptor = instance.getType();
        std::vector<Field const *> fields = std::move(descriptor->getFields(true));

        
        std::for_each(fields.begin(), fields.end(), [&](std::vector<Field const*>::value_type const & field){
            FieldInstance fieldInstance(instance,*field);
            auto & instanceResult = fieldInstance.getInstance();
            if (instanceResult.isEmpty()){
                succeed = false;
                return;
            }
            else{
                Element<FORMAT> * element = nullptr;
                succeed = getElementFormInstance(element, instanceResult, field, objectvalue.getIndent() + 1) && succeed;
                if (element){
                    map.emplace(field->getName(), element);
                }
            }

        });
        
        return succeed;
    }

    template<typename FORMAT>
    bool fillArray(Array<FORMAT> & arrayvalue, Instance const & instance){        
        auto & array = arrayvalue.elements;

        return true;
    }


    template<>
    bool InstanceParser<JSON>::parse(){
        return fillPage<JSON>(page, instance);
    }

};};//TENS