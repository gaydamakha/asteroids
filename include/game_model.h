#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include "collections/asteroids_collection.h"


class GameModel
{
	unsigned game_width;
	unsigned game_height;
	double max_astr_vel;
	double max_astr_angle_vel;
	AsteroidsCollection asteroids;
 	//TODO: add ship and bullet
public:
	GameModel(unsigned game_width, unsigned game_height);

	void update();

	void addRandomAsteroidWithRandomVelocity();

	inline AsteroidsCollection getAsteroids() const
	{
		return asteroids;
	}
};

#endif