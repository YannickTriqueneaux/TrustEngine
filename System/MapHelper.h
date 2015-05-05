

#ifndef MAP_HELPER
#define MAP_HELPER

//template <class T>
//void add_(std::vector<T> & vec, T &&arg)
//{
//    vec.push_back(std::forward<T>(arg));
//}
template <class KeyType, class ValueType, class A>
void add_(std::map<KeyType, ValueType> & map, A &&arg)
{
    map.emplace(std::forward<A>(arg));
}

template<class KeyType, class ValueType, class A>
std::map<KeyType, ValueType> & operator <<(std::map<KeyType, ValueType> & map, A &&arg){
    add_(map, std::forward<A>(arg));
    return map;
}

#endif//MAP_HELPER