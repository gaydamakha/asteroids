#ifndef ITERABLE_COLLECTION_H
#define ITERABLE_COLLECTION_H
#include <vector>
#include <functional>

template<typename T>
class IterableCollection
{
	using Iterator = typename std::vector<T>::iterator;
protected: 
	std::vector<T> collection;
public:
	IterableCollection<T>() : collection() {}

	~IterableCollection()
	{
		collection.clear();
	}

	const IterableCollection<T> push(const T& p)
	{
		collection.emplace_back(p);
		
		return *this;
	}
	
	const IterableCollection<T> filter(std::function<bool(const T&)> f) const
	{
		collection.erase(std::remove_if(collection.begin(), collection.end(), f), collection.end());

		return *this;
	}

	Iterator begin()
	{
		return collection.begin();
	}

	Iterator prev(const Iterator& current)
	{
		return std::prev(current);
	}
	
	Iterator next(const Iterator& current)
	{
		return std::next(current);
	}

	Iterator end()
	{
		return collection.end();
	}

	const T& operator[](int index) const
	{
		return collection[index];
	}
	
	const std::size_t getSize() const
	{
		return collection.size();
	}

};
#endif
