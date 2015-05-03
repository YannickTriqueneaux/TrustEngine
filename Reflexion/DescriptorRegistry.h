namespace TrustEngine{ namespace Reflexion{

class DescriptorRegistry{
    typedef std::map<std::string, Descriptor*> DescriptorListType;
	static DescriptorRegistry & _getInstance();
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
    static Descriptor * _getDescriptor(std::string const & descriptorName);

    template<typename DescriptorType>
    static Descriptor * _createDescriptor() {
        std::string descriptorName = DescriptorType::_getDescriptorName();//voluntary copy
        DescriptorRegistry & registry = _getInstance();
        assert(registry.descriptors.find(descriptorName) == registry.descriptors.end());
        auto pair = registry.descriptors.insert(std::make_pair<std::string, Descriptor*>(std::move(descriptorName), new DescriptorType()));
        return pair.first->second;
    }

	static void _printDescriptorList();
};


};};//TENS