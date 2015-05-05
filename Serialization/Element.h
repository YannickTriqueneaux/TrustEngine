

namespace TrustEngine{
    namespace Serialization{


        template<typename FORMAT>
        class Element{
        public:
            virtual ~Element(){}
            virtual bool print(std::ostream & streamResult)  const = 0;
        };

    };
};//TENS