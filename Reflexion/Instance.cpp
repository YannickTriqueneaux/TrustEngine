namespace TrustEngine{ namespace Reflexion{


Instance::Instance(): instance(nullptr), descriptor(nullptr){}

Instance::Instance(void * instance, Descriptor const * descriptor): instance(instance),descriptor(descriptor){
}



void * Instance::get() const {
	return instance;
}
Descriptor const * Instance::getType() const {
	return descriptor;
}

bool Instance::isEmpty() const{
    return !instance;
}

bool operator==(Instance const & first, Instance const & second) {
    return first.instance == second.instance && first.descriptor == second.descriptor;
}
bool operator!=(Instance const & first, Instance const & second) {
    return !(first == second);
}

};};//TENS
