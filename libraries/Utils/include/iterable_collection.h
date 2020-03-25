#ifndef ITERABLE_COLLECTION_H
#define ITERABLE_COLLECTION_H
#include <vector>
#include <functional>

template<typename T>
class IterableCollection
{
protected: 
	std::vector<T> collection;
public:
	IterableCollection<T>() : collection() {}

	void push(const T& p)
	{
		collection.push_back(p);
	}
	
	void filter(std::function<bool(const T&)> f)
	{
		collection.erase(std::remove_if(collection.begin(), collection.end(), f), collection.end());
	}

	typename std::vector<T>::iterator begin()
	{
		return collection.begin();
	}

	typename std::vector<T>::iterator end()
	{
		return collection.end();
	}

	~IterableCollection()
	{
		collection.clear();
	}
};
#endif
