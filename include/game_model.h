#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include "collections/asteroids_collection.h"
#include "collections/ships_collection.h"

class GameModel
{
	unsigned game_width;
	unsigned game_height;
	double max_astr_vel;
	double max_astr_angle_vel;
	AsteroidsCollection asteroids;
	// A collection of ships to anticipate multiplayer
	ShipsCollection ships;
 	//TODO: add bullets
public:
	GameModel(unsigned game_width, unsigned game_height);

	void update();

	void addRandomAsteroidWithRandomVelocity();

	void addShipAtCenter();

	inline AsteroidsCollection getAsteroids() const
	{
		return asteroids;
	}

	inline ShipsCollection getShips() const
	{
		return ships;
	}
};

#endif