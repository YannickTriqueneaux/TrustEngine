


namespace TrustEngine{ namespace Serialization{

    /**
    * A page is the main object returned by InstanceSerializer::serialize()
    * contains an array of Values
    * @param FORMAT is the page serialization format
    */
    template<typename FORMAT>
    class Page{
    public:
        typedef Value<FORMAT>* ContentType;

        Page();
        /**
        *   print the page content into the given ostream instance
        * @param streamResult where put the content
        * @return false if the print fail by a parsing error
        */
        bool print(std::ostream & streamResult) const ;

        void setContent(ContentType newContent){
            content = newContent;
        };
        ContentType getContent(){
            return content;
        }
    private:
        ContentType content = nullptr;
    };

};};//TENS