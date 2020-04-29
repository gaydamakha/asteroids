#ifndef IT_SHAPE_H
#define IT_SHAPE_H

#include "shape.h"

template<typename T>
class IterableShape: public Shape, public IterableCollection<T>
{
public:
	virtual const IterableCollection<T> getData() = 0;
	virtual const IterableCollection<T> getData() const = 0;
};

#endif


