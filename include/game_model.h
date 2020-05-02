#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include "timer.h"
#include "collections/asteroids_collection.h"
#include "collections/ships_collection.h"
#include "collections/bullets_collection.h"
#include "collections/game_levels_collection.h"
#include "factories/asteroids_factory.h"
#include "player.h"

class GameModel
{
	bool game_over;
	bool game_began;
	unsigned game_width;
	unsigned game_height;

	GameLevelsCollection::Iterator current_level;

	std::unique_ptr<Timer> timer;

	std::unique_ptr<AsteroidsFactory> asteroids_factory;

	std::shared_ptr<Ship> ship;

	std::unique_ptr<Player> player;

	AsteroidsCollection asteroids;

	BulletsCollection bullets;

	GameLevelsCollection levels;

public:
	GameModel(unsigned game_width, unsigned game_height, const GameLevelsCollection& levels);

	//Begins the game from the first level
	void begin();

	inline void finish() { game_began = false; }

	inline bool isBegan() { return game_began; }

	void update();

	void accelerateShip();

	void rotateShipLeft();

	void rotateShipRight();

	void shoot();

private:
	const GameModel& setLevel(const GameLevelsCollection::Iterator&);

	void addAsteroid(AsteroidSize);

	void addShipAtCenter();

	void resetPlayer();

	const Particle &checkBorders(Particle &) const;

public:
	inline AsteroidsCollection getAsteroids() const { return asteroids; }

	inline const Ship &getShip() const { return *ship; }

	inline BulletsCollection getBullets() const { return bullets; }

	inline bool isOver() const { return game_over; }
};

#endif