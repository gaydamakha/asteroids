#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <array>
#include <cassert>

class Color
{
	std::array<uint8_t, 4> data_;

public:
	inline Color() = default;

	//Copy
	inline Color(const Color&) = default;
	//	inline Color(const Color& c) : data_(c.data_) {} ;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       //: data_(c.data_) {}

	inline Color(uint8_t v) : data_{ v,v,v,255 } {}

	Color(uint8_t r, uint8_t g, uint8_t b) : data_{ r,g,b,255 } {}

	inline const uint8_t operator [](uint32_t i) const
	{
		assert(i < 4);
		return data_[i];
	}

	inline const Color operator=(const std::array<uint8_t, 4>& a) { data_ = a; return *this; }

	// Color color;
	// double k;
	// color + k;
	// Unused as (uint8_t) constructor is defined - every int could become a color using this constructor
	inline const Color operator+(double k) const
	{
		return Color{ uint8_t(data_[0] + k), uint8_t(data_[1] + k), uint8_t(data_[2] + k) };
	}

	// Color color1, color2;
	// color1 + color2;
	inline const Color operator+(const Color& color) const
	{
		return Color{ uint8_t(data_[0] + color.data_[0]), uint8_t(data_[1] + color.data_[1]), uint8_t(data_[2] + color.data_[2]) };
	}

	// Color color;
	// double k;
	// color * k;
	inline const Color operator*(double k) const
	{
		return Color{ uint8_t(data_[0] * k), uint8_t(data_[1] * k), uint8_t(data_[2] * k) };
	}

	inline friend const std::ostream& operator<<(std::ostream& out, const Color& color);

	inline const void setOpacity(double op)
	{
		data_[3] = uint8_t(255.99 * op);
	}
};

// Color color;
// double k;
// k*color;
inline const Color operator*(double k, const Color& color)
{
	return Color{ uint8_t(color[0] * k), uint8_t(color[1] * k), uint8_t(color[2] * k) };
}

// Color color;
// double k;
// k + color;
inline const Color operator+(double k, const Color& color)
{
	return Color{ uint8_t(color[0] + k), uint8_t(color[1] + k), uint8_t(color[2] + k) };
}

inline const std::ostream& operator<<(std::ostream& out, const Color& color)
{
	out <<
		static_cast<unsigned>(color.data_[0]) << ", " <<
		static_cast<unsigned>(color.data_[1]) << ", " <<
		static_cast<unsigned>(color.data_[2]) << ", " <<
		static_cast<unsigned>(color.data_[3]);

	return out;
}

static const Color BLACK = 0;
static const Color WHITE = 255;
static const Color GREY = 128;
static const Color RED = { 255,0,0 };
static const Color GREEN = { 0,255,0 };
static const Color BLUE = { 0,0,255 };

static const Color YELLOW = RED + GREEN;
static const Color MAGENTA = RED + BLUE;
static const Color CYAN = GREEN + BLUE;
static const Color ORANGE = RED * 0.5 + 0.5 * YELLOW;

#endif