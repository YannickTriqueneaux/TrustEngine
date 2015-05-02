namespace TrustEngine{ namespace Reflexion{


    FieldInstance::FieldInstance(Instance const & parentInstance, Field const & field) : field(&field),
        fieldInstance(field.getInstance(parentInstance)){
    }

    bool FieldInstance::moveToChild(Field const & pfield){
        Instance newInstance = pfield.getInstance(fieldInstance);
        if (newInstance.isEmpty()){
            return false;
        }
        fieldInstance = newInstance;
        field = &pfield;
        return true;
    }

    Field const & FieldInstance::getField() const {
        return *field;
    }

    Instance const & FieldInstance::getInstance() const {
        return fieldInstance;
    }

    bool operator == (FieldInstance const & first, FieldInstance const & second){
        return first.fieldInstance == second.fieldInstance &&
            first.field == second.field;
    }
    bool operator != (FieldInstance const & first, FieldInstance const & second) {
        return !(first == second);
    }


};};//TENS