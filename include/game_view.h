#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include "entities/asteroid.h"
#include "entities/ship.h"
#include "drawer.h"

class GameView
{
public:
	virtual void clear() const = 0;

	virtual void update() = 0;

	virtual void showAsteroid(const Asteroid& a) const = 0;
	
	virtual void showShip(const Ship& s) const = 0;

	virtual void showBullet(const Bullet &b) const = 0;
};
#endif // !GAME_VIEW_H
