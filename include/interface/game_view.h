#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include "font/hershey.h"
#include "game_stats.h"
#include "game_model.h"
#include "entities/asteroid.h"
#include "entities/ship.h"
#include "drawer.h"

class GameView
{
protected:
	int game_width, game_height;
	std::string game_name;
	Color background;
	std::unique_ptr<Drawer> drawer;
	Hershey font;
public:
	GameView(const std::string&, int, int, const Color& background = BLACK);
	virtual void clear() const;

	virtual void update(const GameModel &game_model);

private:
	virtual void showAsteroid(const Asteroid &a) const;

	virtual void showShip(const Ship &s) const;

	virtual void showBullet(const Bullet &b) const;

	virtual void showStats(const GameStats&) const;
};
#endif // !GAME_VIEW_H
