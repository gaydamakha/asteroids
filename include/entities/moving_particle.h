#ifndef MOVING_PARTICLE_H
#define MOVING_PARTICLE_H

#include "particle.h"

class MovingParticle : public Particle
{
protected:
	Vec2d velocity;

public:
	MovingParticle(
		const Vec2d &coords,
		const Color &color,
		const Vec2d &velocity) : Particle(coords, color)
	{
		this->velocity = velocity;
	}

	inline Vec2d getVelocity() const
	{
		return velocity;
	}

	virtual MovingParticle &setVelocity(Vec2d v)
	{
		velocity = v;

		return *this;
	}

	const MovingParticle &step(double s) override
	{
		// Velocity is px per second, so we multiply it by seconds
		coords += velocity * s;

		return *this;
	}

	virtual const MovingParticle &accelerate(double angle, double acc)
	{
		velocity += Vec2d(cosd(angle) * acc, sind(angle) * acc);

		return *this;
	}

	virtual const MovingParticle &slow(double k)
	{
		velocity -= velocity * k;

		return *this;
	}
};

#endif