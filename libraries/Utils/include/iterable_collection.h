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

	typename std::vector<T>::iterator prev(const typename std::vector<T>::iterator& current)
	{
		return std::prev(current);
	}
	
	typename std::vector<T>::iterator next(const typename std::vector<T>::iterator& current)
	{
		return std::next(current);
	}

	typename std::vector<T>::iterator end()
	{
		return collection.end();
	}

	T& operator[](int index)
	{
		return collection[index];
	}

	typename std::vector<T> getData() const
	{
		return collection;
	}

	std::size_t getSize() const
	{
		return collection.size();
	}

	~IterableCollection()
	{
		collection.clear();
	}
};
#endif
