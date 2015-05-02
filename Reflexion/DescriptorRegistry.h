namespace TrustEngine{ namespace Reflexion{

class DescriptorRegistry{
    typedef std::map<std::string, Descriptor*> DescriptorListType;
	static DescriptorRegistry & getInstance();
	DescriptorRegistry();

	DescriptorRegistry(DescriptorRegistry && other){
	}

	void swap(DescriptorRegistry &other){
		std::swap(descriptors,other.descriptors);
	}
	DescriptorRegistry &operator=(DescriptorRegistry && other){
		swap(other);
		return *this;
	}

public:
	DescriptorListType descriptors;
    static Descriptor * getDescriptor(std::string const & descriptorName);

    template<typename DescriptorType>
    static Descriptor * createDescriptor() {
        std::string descriptorName = DescriptorType::getDescriptorName();
        DescriptorRegistry & registry = getInstance();
        assert(registry.descriptors.find(descriptorName) == registry.descriptors.end());
        auto pair = registry.descriptors.insert(std::make_pair<std::string, Descriptor*>(std::move(descriptorName), new DescriptorType()));
        return pair.first->second;
    }

	static void printDescriptorList();
};


};};//TENS