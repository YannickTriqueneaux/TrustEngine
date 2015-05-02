

template <class T>
void add_(std::vector<T> & vec, T &&arg)
{
	vec.push_back(std::forward<T>(arg));
}
template <class T,class A>
void add_(std::vector<T> & vec, A &&arg)
{
	vec.emplace_back(arg);
}

template<class T, class A>
std::vector<T> & operator <<(std::vector<T> & vec, A &&arg){
	add_(vec, std::forward<A>(arg));
	return vec;
}

template<class T>
std::vector<T> & operator ++(std::vector<T> & vec){
	vec.emplace_back();
	return vec;
}

//template <class T, class ... Args>
//void print_(T && val, Args &&... args)
//{
//	print_(std::forward<T>(val));
//	print_(std::forward<Args>(args)...);
//}
//
//template <class ... Args>
//void print(Args &&... args)
//{
//	cout << "Inmpression de " << sizeof...(Args) << " parametres: ";
//	print_(std::forward<Args>(args)...);
//}