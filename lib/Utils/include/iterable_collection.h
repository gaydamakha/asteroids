#ifndef ITERABLE_COLLECTION_H
#define ITERABLE_COLLECTION_H

#include <vector>
#include <functional>
#include <memory>

template <typename T>
class IterableCollection
{
public:
	using Element = typename std::shared_ptr<T>;
	using Iterator = typename std::vector<Element>::iterator;

protected:
	std::vector<Element> collection;

public:
	IterableCollection<T>() : collection() {}

	IterableCollection<T>(unsigned size): collection(size) {}

	//The use of delegating constructor
	IterableCollection<T>(std::initializer_list<T> il) : IterableCollection<T>()
	{
		for (auto &el : il)
		{
			this->push(el);
		}
	}

	~IterableCollection()
	{
		collection.clear();
	}

	const IterableCollection<T> push(const T &p)
	{
		collection.emplace_back(std::make_shared<T>(p));

		return *this;
	}

	const IterableCollection<T> filter(std::function<bool(std::shared_ptr<T>)> f)
	{
		collection.erase(std::remove_if(collection.begin(), collection.end(), f), collection.end());

		return *this;
	}

	const IterableCollection<T> moveFrom(IterableCollection<T> &ic)
	{
		collection.insert(collection.end(), std::make_move_iterator(ic.begin()), std::make_move_iterator(ic.end()));
		ic.clear();
		return *this;
	}

	const IterableCollection<T> sort()
	{
		std::sort(collection.begin(), collection.end(), [](Element e1, Element e2) {
			return *e1 < *e2;
		});
		return *this;
	}

	Iterator erase(const Iterator &pos)
	{
		auto c = collection.begin();
		return collection.erase(pos);
	}

	const IterableCollection<T> clear()
	{
		collection.clear();

		return *this;
	}

	Iterator begin()
	{
		return collection.begin();
	}

	const Iterator prev(const Iterator &current) const
	{
		return std::prev(current);
	}

	const Iterator next(const Iterator &current) const
	{
		return std::next(current);
	}

	Iterator end()
	{
		return collection.end();
	}

	T &operator[](int index)
	{
		return *collection[index];
	}

	const T &operator[](int index) const
	{
		return *collection[index];
	}

	const std::size_t getSize() const
	{
		return collection.size();
	}
};
#endif
