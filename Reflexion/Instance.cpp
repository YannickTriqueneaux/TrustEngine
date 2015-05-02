namespace TrustEngine{ namespace Reflexion{


Instance::Instance(void * instance, Descriptor const * descriptor): instance(instance),descriptor(descriptor){
}



void * Instance::get() const {
	return instance;
}
Descriptor const * Instance::getType() const {
	return descriptor;
}

};};//TENS
