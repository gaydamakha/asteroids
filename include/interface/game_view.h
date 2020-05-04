#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <Utils.h>
#include "font/hershey.h"
#include "components/button.h"
#include "game_stats.h"
#include "game_model.h"
#include "entities/asteroid.h"
#include "entities/ship.h"
#include "drawer.h"

class GameView
{
protected:
	//Paddings from the boards of the screen
	static const unsigned x_padding = 20;
	static const unsigned y_padding = 40;
	static const unsigned str_h = y_padding;
	const int game_width, game_height;
	Vec2d center;
	Vec2d left_up_corner;
	Vec2d right_up_corner;
	Vec2d highscores_stat_pos;
	Vec2d level_stat_pos;
	Color background;
	std::string game_name;
	std::unique_ptr<Drawer> drawer;
	Hershey font;
public:
	GameView(const std::string&, int, int, const Color& background = BLACK);
	virtual void clear() const;

	virtual void update(const GameModel &game_model);

	inline const Vec2d& getCenter() const { return center; }

	virtual void showButton(const Button &button) const;

	virtual void showText(const Vec2d&, const std::string, const Color&) const;
private:
	virtual void showAsteroid(const Asteroid &a) const;

	virtual void showShip(const Ship &s) const;

	virtual void showBullet(const Bullet &b) const;

	virtual void showStats(const GameStats&) const;
};
#endif // !GAME_VIEW_H
