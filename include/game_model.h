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
	double max_ship_vel;
	double max_ship_acc;
	double ship_jerk;
	// double max_ship_angle_vel;

	// double ship_angle_acc_step;

	//env characteristics
	double env_resistence;

	AsteroidsCollection asteroids;
	// A collection of ships to anticipate multiplayer
	ShipsCollection ships;
 	//TODO: add bullets
public:
	GameModel(unsigned game_width, unsigned game_height);

	void update();

	void addRandomAsteroidWithRandomVelocity();

	void addShipAtCenter(Vec2d direction);

	void accelerateShips();

	void rotateShipsLeft();

	void rotateShipsRight();

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