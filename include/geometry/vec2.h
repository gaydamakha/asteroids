#ifndef VEC2_H
#define VEC2_H
#include <math.h>
#include "Utils.h"

template <typename T>
class Vec2
{
	T x;
	T y;
public:
	inline Vec2() = default;

	//Copy constructor
	inline Vec2(const Vec2<T>&) = default;

	Vec2(T x, T y) : x(x), y(y) {}

	// Vec2<T> vec2;
	// T k;
	// vec2 + k;
	inline Vec2<T> operator+(T k) const
	{
		return Vec2{ x + k, y + k };
	}

	// Vec2<T> vec1, vec2;
	// vec1 + vec2;
	inline Vec2<T> operator+(const Vec2<T>& v) const
	{
		return Vec2{ x + v.x, y + v.y };
	}

	// Vec2<T> vec2;
	// T k;
	// vec2 += k;
	inline Vec2<T> operator+=(T k)
	{
		x += k;
		y += k;
		return *this;
	}

	// Vec2<T> vec1, vec2;
	// vec1 += vec2;
	inline Vec2<T> operator+=(const Vec2<T>& v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	// Vec2<T> vec2;
	// T k;
	// vec2 - k;
	inline Vec2<T> operator-(T k) const
	{
		return Vec2{ x - k, y - k };
	}

	// Vec2<T> vec1, vec2;
	// vec1 - vec2;
	inline Vec2<T> operator-(const Vec2<T>& v) const
	{
		return Vec2{ x - v.x, y - v.y };
	}

	// Vec2<T> vec2;
	// T k;
	// vec2 -= k;
	inline Vec2<T> operator-=(T k)
	{
		x -= k;
		y -= k;
		return *this;
	}

	// Vec2<T> vec1, vec2;
	// vec1 -= vec2;
	inline Vec2<T> operator-=(const Vec2<T>& v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	// Vec2<T> vec2;
	// T k;
	// vec2 * k;
	inline Vec2<T> operator*(T k) const
	{
		return Vec2{ x * k, y * k };
	}

	// Vec2<T> vec1, vec2;
	// vec1 * vec2;
	inline Vec2<T> operator*(const Vec2<T>& v) const
	{
		return Vec2{ x * v.x, y * v.y };
	}

	// Vec2<T> vec2;
	// T k;
	// vec2 *= k;
	inline Vec2<T> operator*=(T k)
	{
		x *= k;
		y *= k;
		return *this;
	}

	// Vec2<T> vec1, vec2;
	// vec1 *= vec2;
	inline Vec2<T> operator*=(const Vec2<T>& v)
	{
		x *= v.x;
		y *= v.y;
		return *this;
	}

	// Vec2<T> vec2;
	// T k;
	// vec2 / k;
	inline Vec2<T> operator/(T k) const
	{
		return Vec2{ x / k, y / k };
	}

	// Vec2<T> vec1, vec2;
	// vec1 / vec2;
	inline Vec2<T> operator/(const Vec2<T>& v) const
	{
		return Vec2{ x / v.x, y / v.y };
	}

	// Vec2<T> vec2;
	// T k;
	// vec2 /= k;
	inline Vec2<T> operator/=(T k)
	{
		x /= k;
		y /= k;
		return *this;
	}

	// Vec2<T> vec1, vec2;
	// vec1 /= vec2;
	inline Vec2<T> operator/=(const Vec2<T>& v)
	{
		x /= v.x;
		y /= v.y;
		return *this;
	}

	// Vec2<T> vec1;
	// +vec1;
	inline Vec2<T> operator+() const
	{
		return Vec2<T>(+x, +y);
	}
	inline Vec2<T> operator-() const
	{
		return Vec2<T>(-x, -y);
	}

	inline T getX() const
	{
		return x;
	}

	inline T getY() const
	{
		return y;
	}
};

// Vec2<T> vec2;
// T k;
// k + vec2;
template <typename T>
inline Vec2<T> operator+(T k, const Vec2<T>& vec)
{
	return Vec2<T>(vec.getX() + k, vec.getY() + k);
}

// Vec2<T> vec2;
// T k;
// k * vec2;
template <typename T>
inline Vec2<T> operator*(T k, const Vec2<T>& vec)
{
	return Vec2<T>(vec.getX() * k, vec.getY() * k);
}

template<typename T>
inline Vec2<T> Vec2_gen(T x, T y)
{
	static_assert(std::is_arithmetic_v<T>, "Parameter's type should be arithmetic");
	return Vec2<T>(x, y);
}


//Returns a random vector of norm 1
template<typename T>
Vec2<T> Vec2_aleagen()
{
	//The x will be generated randomly
	auto gen = alea_generator((T)0, (T)1);
	T x = gen();
	//The y should be equal to this to have a vector of norm 1
	T y = sqrt(1 - x * x);

	return Vec2<T>(x, y);
}

template<typename T>
Vec2<T> Vec2_aleagen(T xmin, T xmax, T ymin, T ymax, bool exclude_zero = false)
{
	auto xgen = alea_generator(xmin, xmax);
	auto ygen = alea_generator(ymin, ymax);

	return Vec2<T>(xgen(), ygen());
}

//Returns a random vector of norm between 0 or 1
template<typename T>
Vec2<T> Vec2_aleanormgen()
{
	//The x will be generated randomly
	auto gen = alea_generator((T)0, (T)1);
	T x = gen();
	//The maximum y value is calculated, then y is calculated
	auto ygen = alea_generator((T)0, sqrt(1 - x * x));

	return Vec2<T>(x, ygen());
}


//No outside(righthand) "-" operator - no sense to do the next:
// T k;
// Vec2<T> vec2 = {5,6};
// k - vec2;
// Same for /, +=, -=, *=, /= operators
using Vec2i = Vec2<int>;
using Vec2f = Vec2<float>;
using Vec2d = Vec2<double>;

#endif