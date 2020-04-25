#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include <bits/stdc++.h>
#include "collections/asteroids_collection.h"
#include "collections/ships_collection.h"
#include "factories/asteroid_factory.h"

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
	AsteroidsCollection new_asteroids;
	// A collection of ships to anticipate multiplayer
	ShipsCollection ships;
	//TODO: add bullets

	static const std::map<AsteroidSize, AsteroidDesc> asteroids_config;

public:
	GameModel(unsigned game_width, unsigned game_height);

	void update(double);

	void addAsteroid(AsteroidSize);

	void addShipAtCenter(double);

	void accelerateShips();

	void rotateShipsLeft();

	void rotateShipsRight();

private:
	void resetShip(Ship &);

	void checkBorders(MovingParticle &) const;
	
public:
	inline AsteroidsCollection getAsteroids() const { return asteroids; }

	inline ShipsCollection getShips() const { return ships; }

	//Temp methods
	void splitAsteroid();
};

#endif