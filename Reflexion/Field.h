
_BEGIN_TE_REFLEXION_NAMESPACE

class Instance;
class Descriptor;
class Field{
public:
    Field(int pOffset, Descriptor const * descriptor);

    Instance & getInstance(Instance const & parent) const;
private:
    Descriptor const * descriptor;
    unsigned int offset;
};

_END_TE_REFLEXION_NAMESPACE