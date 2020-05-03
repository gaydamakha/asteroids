#include <string>
#include "interface/game_view.h"
#include "interface/drawer.h"
#include "entities/asteroid.h"

void GameView::clear() const
{
	drawer->fillScreen(background);
}

void GameView::update(const GameModel &game_model)
{	
	//Show all the asteroids
	for (auto &asteroid : game_model.getAsteroids())
	{
		this->showAsteroid(*asteroid);
	}

	//Show the ship
	this->showShip(game_model.getShip());

	//Show all the bullets
	for (auto &bullet: game_model.getBullets())
	{
		this->showBullet(*bullet);
	}

	//TODO: show game stats view
}

void GameView::showAsteroid(const Asteroid &a) const
{
	drawer->drawPolygone(a.getPolygone(), a.getColor());
}

void GameView::showShip(const Ship &s) const
{
	drawer->drawPolygone(s.getPolygone(), s.getColor());
}

void GameView::showBullet(const Bullet &b) const
{
	std::shared_ptr<Circle> c = std::static_pointer_cast<Circle>(b.getShape());
	drawer->drawSquare(c->getRadius(), b.getCoords(), b.getColor());
}