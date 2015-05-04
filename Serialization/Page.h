


namespace TrustEngine{ namespace Serialization{

    /**
    * A page is the main object returned by InstanceSerializer::serialize()
    * contains an array of Values
    * @param FORMAT is the page serialization format
    */
    template<typename FORMAT>
    class Page{
    public:
        typedef Element<FORMAT>* ContentType;

        Page();
        /**
        *   print the page content into the given ostream instance
        * @param streamResult where put the content
        * @return false if the print fail by a parsing error
        */
        bool print(std::ostream & streamResult) const ;


        ContentType content = nullptr;
    private:
    };

};};//TENS