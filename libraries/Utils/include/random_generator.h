#ifndef R_GEN_H
#define R_GEN_H
#include <random>

class Randomizer
{
	unsigned seed;	
	std::mt19937 *mt;
public:

	inline Randomizer(unsigned seed)
	{
		this->seed = seed == 0 ? std::random_device()() : seed;
		mt = new std::mt19937(this->seed);
	}

	Randomizer(const Randomizer& r)
	{
		seed = r.seed;
		mt = new std::mt19937(seed);
		*mt = *r.mt;
	}
	~Randomizer()
	{
		delete mt;
	}
	
	std::mt19937* getMt() const
	{
		return mt;
	}
};

template<typename T, typename Enable = void>
class RandomGenerator;

template<typename T>
class RandomGenerator<T, std::enable_if_t<std::is_integral_v<T>>>
{
	std::uniform_int_distribution<T> dis;
	Randomizer rnd;
public:
	RandomGenerator(T low, T high, unsigned seed) : dis(low, high), rnd(seed) {}

	auto operator()() const
	{
		return dis(*rnd.getMt());
	}
};

template<typename T>
class RandomGenerator<T, std::enable_if_t<std::is_floating_point_v<T>>>
{
	std::uniform_real_distribution<T> dis;
	Randomizer rnd;
public:
	RandomGenerator(T low, T high, unsigned seed): dis(low, high), rnd(seed) {}
	
	T operator()()
	{
		return dis(*rnd.getMt());
	}
};

template <typename T>
RandomGenerator<T> alea_generator(T low, T high, unsigned seed = 0)
{
	static_assert(std::is_arithmetic_v<T>, "Parameter's type should be arithmetic");
	return RandomGenerator<T>(low, high, seed);
}

#endif