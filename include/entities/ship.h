#ifndef SHIP_H
#define SHIP_H

#include <Geometry.h>
#include "collections/bullets_collection.h"
#include "moving_polygone_particle.h"
#include "gun.h"

struct ShipConfig
{
	const Vec2d init_position;
	const Color color;
	const Vec2d init_velocity;
	const std::initializer_list<Vec2d> vertices;
	const double angle_acc;
	const double radius;
	const double init_angle;
	const double acc;
	const GunConfig gun_config;
};

class Ship : public MovingPolygoneParticle, public CircleCollider
{
protected:
	double angle;
	double acc;
	const Vertice &nose;
	std::unique_ptr<Gun> gun;

public:
	Ship(const ShipConfig &);

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