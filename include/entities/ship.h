#ifndef SHIP_H
#define SHIP_H

#include <Geometry.h>
#include "collections/bullets_collection.h"
#include "moving_polygone_particle.h"
#include "gun.h"

struct ShipConfig
{
	Vec2d init_position;
	Color color;
	Vec2d init_velocity;
	VerticesArray vertices;
	double angle_acc;
	double radius;
	double init_angle;
	double acc;
	GunConfig gun_config;
};

class Ship : public MovingPolygoneParticle, public CircleCollider
{
protected:
	double angle;
	double acc;
	const Vertice &nose;
	std::unique_ptr<Gun> gun;

public:
	Ship(const ShipConfig);

	inline double getAngle() { return angle; }

	const Ship &setAngle(double);

	inline bool toRemove(double timestamp) { return false; }

	const Ship &rotateLeft();

	const Ship &rotateRight();

	const Ship &accelerate();

	const Ship &step(double) override;

	BulletsCollection shoot(double);
};

#endif