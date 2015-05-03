namespace TrustEngine{ namespace Reflexion{

std::string const StringDescriptor::instanceTypeName = "std::string";

std::string const StringDescriptor::descriptorName = _stringize(StringDescriptor);


void StringDescriptor::stringize(std::ostream & streamResult, Instance const & instance) const{
    assert(instance.isEmpty() && "StringDescriptor::stringize - the given instance is empty");
    streamResult << reinterpret_cast<std::string*>(instance.get());
}

};};//TENS