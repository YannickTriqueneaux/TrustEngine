


namespace TrustEngine{ namespace Serialization{

    /**
    * A page is the main object returned by Serializer::serialize()
    * Represents the two main '{' and '}'
    * and contains an array of Values
    * @param FORMAT is the page serialization format
    */
    template<typename FORMAT>
    class Page{
    public:
        Page();
        /**
        *   print the page content into the given ostream instance
        * @param streamResult where put the content
        * @return false if the print fail by a parsing error
        */
        bool print(std::ostream & streamResult);

    private:
        Array<FORMAT> content;
    };

};};//TENS