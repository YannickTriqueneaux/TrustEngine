namespace TrustEngine{ namespace Reflexion{


Field::Field(int pOffset, Descriptor const * descriptor) : offset(pOffset), descriptor(descriptor){

}
Instance & Field::getInstance(Instance const & parent) const {
    Instance instance(reinterpret_cast<void *>((unsigned int*)parent.get() + offset), descriptor);
    return std::move(instance);
}


};};//TENS