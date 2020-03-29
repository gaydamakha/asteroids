#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include "collections/asteroids_collection.h"

using Vector = std::pair<Vec2d, Vec2d>;

class GameModel
{
	unsigned game_width;
	unsigned game_height;
	double max_astr_vel;
	double max_astr_angle_vel;
	AsteroidsCollection asteroids;
 	//TODO: add ship and bullet
public:
	GameModel(unsigned game_width, unsigned game_height)
	{
		this->game_width = game_width;
		this->game_height = game_height;
		this->max_astr_vel = 0.1;
		this->max_astr_angle_vel = 2.;
	}

	void update();

	void addRandomAsteroidWithRandomVelocity();

	inline AsteroidsCollection getAsteroids() const
	{
		return asteroids;
	}
};

#endif