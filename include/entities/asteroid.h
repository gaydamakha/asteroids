#ifndef ASTEROID_H
#define ASTEROID_H

#include <bits/stdc++.h>
#include <Geometry.h>
#include "moving_polygone_particle.h"
#include "shape_view_game_entity.h"

enum class AsteroidSize
{
	BIG,
	MEDIUM,
	SMALL
};


struct AsteroidDesc
{
	double min_radius;
	double max_radius;
	double granularity;
	double min_angle_vary;
	double max_angle_vary;
};

class Asteroid : public MovingPolygoneParticle, public CircleCollider, public ShapeViewGameEntity
{
	const AsteroidSize size;
	bool broken;
public:
	static const std::map<AsteroidSize, AsteroidDesc> props;

	Asteroid(const Vec2d &coords,
			 const Color &color,
			 const Vec2d &velocity,
			 const Polygone &shape,
			 double angle_acc,
			 double rad,
			 AsteroidSize size);

	void step(double);

	inline const AsteroidSize getSize() const { return size; }

	inline bool isBroken() const { return broken; }

	inline const Shape getShape() const { return polygone; }

	//Once asteroid is broken, it can not be restored
	inline const void broke() { broken = true; }

	inline bool toRemove(double timestamp) { return this->isBroken(); }
};

#endif