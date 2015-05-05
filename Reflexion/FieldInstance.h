namespace TrustEngine{ namespace Reflexion{


    class FieldInstance{
    public:
        FieldInstance(Instance const & parentInstance, Field const & field);

        /**
        * Find the  specified field inside the current instance and move this one to the found.
        * @param field: field to find.
        * @return false if not found, else true.
        */
        bool moveToChild(Field const & field);

        /**
        * @return the current Field.
        */
        Field const & getField() const ;

        /**
        * @return the current Instance.
        */
        Instance const & getInstance() const ;

        /**
        * @return true if givens FieldInstances are in the same instance
        */
        friend bool operator == (FieldInstance const & first, FieldInstance const & second);
        /**
        * @return true if givens FieldInstances aren't in the same instance
        */
        friend bool operator != (FieldInstance const & first, FieldInstance const & second);
    private:
        Instance fieldInstance;
        Field const * field = nullptr;
    };

    

};};//TENS