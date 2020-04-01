#ifndef MOVING_PARTICLE_H
#define MOVING_PARTICLE_H

#include "particle.h"

class MovingParticle : public Particle
{
protected:
	Vec2d velocity;
public:
	MovingParticle(
		const Vec2d& position,
		const Color& color,
		const Vec2d& velocity): Particle(position, color)
	{
		this->velocity = velocity;
	}
	
	inline Vec2d getVelocity() const
	{
		return velocity;
	}

	virtual void setVelocity(Vec2d v)
	{
		velocity = v;
	}

	void step()
	{
		position += velocity;
	}

	virtual void accelerate(double angle, double acc)
	{
		velocity += Vec2d(cosd(angle) * acc, sind(angle) * acc);
	}

	virtual void slow(double k)
	{
		velocity -= velocity*k;
	}
};

#endif