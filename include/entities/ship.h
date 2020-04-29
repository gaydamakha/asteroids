#ifndef SHIP_H
#define SHIP_H

#include <Geometry.h>
#include "collections/bullets_collection.h"
#include "shape_view_game_entity.h"
#include "moving_polygone_particle.h"
#include "gun.h"

class Ship : public MovingPolygoneParticle, public CircleCollider, public ShapeViewGameEntity
{
protected:
	double angle;
	double acc;
	const Vertice& nose;
	std::unique_ptr<Gun> gun;
public:
	Ship(
		const Vec2d &coords,
		const Color &color,
		const Vec2d &velocity,
		const Polygone &shape,
		double angle_acc,
		double radius,
		double init_angle,
		double acc,
		const GunConfig&);

	void step(double);

	void slow(double);

	void accelerate();

	void rotateLeft();

	void rotateRight();

	BulletsCollection shoot(double);

	inline double getAngle() { return angle; }

	void setAngle(double);

	inline const Shape getShape() const { return polygone; }

	inline bool toRemove(double timestamp) { return false; }
};

#endif