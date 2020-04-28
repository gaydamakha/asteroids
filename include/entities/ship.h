#ifndef SHIP_H
#define SHIP_H

#include <Geometry.h>
#include "collections/bullets_collection.h"
#include "shape_view_game_entity.h"
#include "moving_polygone_particle.h"

class Ship : public MovingPolygoneParticle, public CircleCollider, public ShapeViewGameEntity
{
protected:
	//TODO: make something with all it constants...
	double angle;
	double acc;
	double bullets_cd;
	double last_bullet_time;
	Color bullets_color;
	double bullets_vel;
	double bullets_size;
	double bullets_ttl;
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
		double bullets_cd,
		double bullets_vel,
		double bullets_size,
		double bullets_ttl,
		const Color& bullets_color);

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