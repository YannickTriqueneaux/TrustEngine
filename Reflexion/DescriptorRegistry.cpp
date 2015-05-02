DescriptorRegistry::DescriptorRegistry(){
}
DescriptorRegistry & DescriptorRegistry::getInstance(){
	static DescriptorRegistry instance;
	return instance;
}


Descriptor * DescriptorRegistry::getDescriptor(std::string const & descriptorName){
	DescriptorRegistry & registry = getInstance();
	auto found = registry.descriptors.find(descriptorName);
	if(found == registry.descriptors.end()){
		return nullptr;
	}else{
		return found->second;
	}
}

void DescriptorRegistry::printDescriptorList(){
	DescriptorRegistry & registry = getInstance();
    std::for_each(registry.descriptors.begin(), registry.descriptors.end(), [](DescriptorListType::value_type const & ite){
        std::cout << ite.first << std::endl;
	});
}