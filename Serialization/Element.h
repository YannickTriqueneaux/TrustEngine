

namespace TrustEngine{
    namespace Serialization{


        template<typename FORMAT>
        class Element{
        public:
            virtual bool print(std::ostream & streamResult)  const = 0;
        };

    };
};//TENS