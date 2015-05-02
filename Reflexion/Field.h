
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