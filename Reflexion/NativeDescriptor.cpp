namespace TrustEngine{ namespace Reflexion{


std::string const NativeDescriptor<bool>::_descriptorName = _stringize(NativeDescriptor<bool>);
std::string const NativeDescriptor<int>::_descriptorName = _stringize(NativeDescriptor<int>);
std::string const NativeDescriptor<short>::_descriptorName = _stringize(NativeDescriptor<short>);
std::string const NativeDescriptor<long>::_descriptorName = _stringize(NativeDescriptor<long>);
std::string const NativeDescriptor<float>::_descriptorName = _stringize(NativeDescriptor<float>);
std::string const NativeDescriptor<double>::_descriptorName = _stringize(NativeDescriptor<double>);
std::string const NativeDescriptor<unsigned int>::_descriptorName = _stringize(NativeDescriptor<unsigned int>);


void NativeDescriptor<bool>::stringize(std::ostream & streamResult, Instance const & instance) const{
    assert(instance.isEmpty() && "StringDescriptor::stringize - the given instance is empty");
    streamResult << reinterpret_cast<bool*>(instance.get());
}
void NativeDescriptor<int>::stringize(std::ostream & streamResult, Instance const & instance) const{
    assert(instance.isEmpty() && "StringDescriptor::stringize - the given instance is empty");
    streamResult << reinterpret_cast<int*>(instance.get());
}
void NativeDescriptor<short>::stringize(std::ostream & streamResult, Instance const & instance) const{
    assert(instance.isEmpty() && "StringDescriptor::stringize - the given instance is empty");
    streamResult << reinterpret_cast<short*>(instance.get());
}
void NativeDescriptor<long>::stringize(std::ostream & streamResult, Instance const & instance) const{
    assert(instance.isEmpty() && "StringDescriptor::stringize - the given instance is empty");
    streamResult << reinterpret_cast<long*>(instance.get());
}
void NativeDescriptor<float>::stringize(std::ostream & streamResult, Instance const & instance) const{
    assert(instance.isEmpty() && "StringDescriptor::stringize - the given instance is empty");
    streamResult << reinterpret_cast<float*>(instance.get());
}
void NativeDescriptor<double>::stringize(std::ostream & streamResult, Instance const & instance) const{
    assert(instance.isEmpty() && "StringDescriptor::stringize - the given instance is empty");
    streamResult << reinterpret_cast<double*>(instance.get());
}
void NativeDescriptor<unsigned int>::stringize(std::ostream & streamResult, Instance const & instance) const{
    assert(instance.isEmpty() && "StringDescriptor::stringize - the given instance is empty");
    streamResult << reinterpret_cast<unsigned int*>(instance.get());
}

};};//TENS