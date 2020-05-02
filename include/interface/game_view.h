#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include "game_model.h"
#include "entities/asteroid.h"
#include "entities/ship.h"
#include "drawer.h"

class GameView
{
protected:
	Color background;
	std::unique_ptr<Drawer> drawer;
public:
	virtual void clear() const;

	virtual void update(const GameModel &game_model);

private:
	virtual void showAsteroid(const Asteroid &a) const;

	virtual void showShip(const Ship &s) const;

	virtual void showBullet(const Bullet &b) const;
};
#endif // !GAME_VIEW_H
