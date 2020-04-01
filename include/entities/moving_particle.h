#ifndef MOVING_PARTICLE_H
#define MOVING_PARTICLE_H

#include "particle.h"

class MovingParticle : public Particle
{
protected:
	Vec2d velocity;
	Vec2d acceleration;
	double min_velocity;
	double max_velocity;
	double min_acceleration;
	double max_acceleration;
public:
	MovingParticle(
		const Vec2d& position,
		const Color& color,
		const Vec2d& velocity,
		const Vec2d& acceleration,
		double min_velocity,
		double max_velocity,
		double min_acceleration,
		double max_acceleration): Particle(position, color)
	{
		this->velocity = velocity;
		this->acceleration = acceleration;
		this->min_velocity = min_velocity;
		this->max_velocity = max_velocity;
		this->min_acceleration = min_acceleration;
		this->max_acceleration = max_acceleration;
	}
	
	inline Vec2d getVelocity() const
	{
		return velocity;
	}

	virtual void setVelocity(Vec2d v)
	{
		if (!v.getLength() < min_velocity && ! v.getLength() > max_velocity)
		{
			velocity = v;
		}	
	}

	inline Vec2d getAcceleration() const
	{
		return acceleration;
	}

	virtual void setAcceleration(Vec2d acc)
	{
		if (!acc.getLength() < min_acceleration && !acc.getLength() > max_acceleration)
		{
			acceleration = acc;
		}
	}

	void step()
	{
		Vec2d res = velocity + (acceleration / 2);
		if (!(res.getLength() < min_velocity) && !(res.getLength() > max_velocity))
		{
			velocity = res;
		}
		position += velocity;
	}

	virtual void accelerate(const Vec2d& acc)
	{
		Vec2d res = acceleration + (acc / 2);
		bool max = !(res.getLength() > max_acceleration);
		bool min = !(res.getLength() < min_acceleration);

		if (!max)
		{
			std::cout << "Not max!" << std::endl;
		}

		if (!min)
		{
			std::cout << "Not min!" << std::endl;
		}

		if (!(res.getLength() < min_acceleration) && !(res.getLength() > max_acceleration))
		{
			acceleration = res;
		}
	}
};

#endif