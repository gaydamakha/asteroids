#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include "timer.h"
#include "collections/asteroids_collection.h"
#include "collections/ships_collection.h"
#include "collections/bullets_collection.h"
#include "factories/asteroids_factory.h"

class GameModel
{
	unsigned game_width;
	unsigned game_height;

	//Ship configs
	double ship_init_angle;
	double ship_acc;
	double ship_angle_acc;
	double bullet_cd;
	double bullets_vel;
    double bullets_ttl;
    double bullets_size;

	//env characteristics
	double env_resistence;

	std::unique_ptr<Timer> timer;

	std::unique_ptr<AsteroidsFactory> asteroids_factory;

	AsteroidsCollection asteroids;

	std::shared_ptr<Ship> ship;
	
	BulletsCollection bullets;

public:
	GameModel(unsigned game_width, unsigned game_height);

	void update();
	//TODO: make it private
	void addAsteroid(AsteroidSize);
	//TODO: make it private
	void addShipAtCenter();

	void accelerateShip();

	void rotateShipLeft();

	void rotateShipRight();

	void shoot();
private:
	void resetShip();

	void checkBorders(MovingParticle &) const;
	
public:
	inline AsteroidsCollection getAsteroids() const { return asteroids; }

	inline const Ship& getShip() const { return *ship; }

	inline BulletsCollection getBullets() const { return bullets; }
};

#endif