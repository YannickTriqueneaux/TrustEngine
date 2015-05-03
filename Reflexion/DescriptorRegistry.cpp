namespace TrustEngine{ namespace Reflexion{


DescriptorRegistry::DescriptorRegistry(){
}
DescriptorRegistry & DescriptorRegistry::_getInstance(){
	static DescriptorRegistry instance;
	return instance;
}


Descriptor * DescriptorRegistry::_getDescriptor(std::string const & descriptorName){
	DescriptorRegistry & registry = _getInstance();
	auto found = registry.descriptors.find(descriptorName);
	if(found == registry.descriptors.end()){
		return nullptr;
	}else{
		return found->second;
	}
}

void DescriptorRegistry::_printDescriptorList(){
	DescriptorRegistry & registry = _getInstance();
    std::for_each(registry.descriptors.begin(), registry.descriptors.end(), [](DescriptorListType::value_type const & ite){
        std::cout << ite.first << std::endl;
	});
}

};};//TENS