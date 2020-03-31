#ifndef IT_SHAPE_H
#define IT_SHAPE_H

#include "shape.h"

template<typename T>
class IterableShape: public Shape
{
public:
	virtual const IterableCollection<T> getData() const = 0;
};

#endif


