#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include "collections/asteroids_collection.h"
#include "collections/ships_collection.h"

class GameModel
{
	unsigned game_width;
	unsigned game_height;
	
	//Asteroids configs
	double max_astr_vel;
	double max_astr_angle_vel;

	//Ship configs
	double ship_acc;
	double ship_angle_acc;

	//env characteristics
	double env_resistence;

	AsteroidsCollection asteroids;
	// A collection of ships to anticipate multiplayer
	ShipsCollection ships;
 	//TODO: add bullets
public:
	GameModel(unsigned game_width, unsigned game_height);

	void update(double);

	void addRandomAsteroidWithRandomVelocity();

	void addShipAtCenter(double);

	void accelerateShips();

	void rotateShipsLeft();

	void rotateShipsRight();

	void resetShips(double);

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