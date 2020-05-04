#include <string>
#include "interface/game_view.h"
#include "interface/drawer.h"
#include "entities/asteroid.h"

GameView::GameView(const std::string &game_name, int game_width, int game_height, const Color &background)
{
	this->game_name = game_name;
	this->background = background;
	this->game_width = game_width;
	this->game_height = game_height;
	//Inverse letters by Y axis
	for (auto &letter : font.getFont())
	{
		for (auto &symbol : (*letter).getSymbols())
		{
			for (auto &vertice : (*symbol).getVertices())
			{
				(*vertice) = Vec2d(vertice->getX(), -vertice->getY());
			}
		}
	}
}
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
	for (auto &bullet : game_model.getBullets())
	{
		this->showBullet(*bullet);
	}

	//TODO: show game stats view
	this->showStats(game_model.getStats());
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

void GameView::showStats(const GameStats &stats) const
{
	unsigned offset = 0;
	unsigned length = 0;
	unsigned padding = 20;
	Vec2d left_corner(padding, 40);
	Vec2d right_corner(this->game_width - padding, 40);

	//Show scores
	std::string scores = "Scores: " + std::to_string(stats.player_scores);
	for (auto& letter : font.get(scores))
	{
		Vec2d position(left_corner.getX() + offset, left_corner.getY());
		for (auto &s : letter->getSymbols())
		{
			drawer->drawShapeWithVertices(position, *s, GREEN);
		}
		offset += letter->getWidth();
	}
	
	//Show highscores
	std::string highscores = "Highscores: " + std::to_string(stats.player_highscores);
	left_corner = {20, 70};
	offset = 0;
	for (auto& letter : font.get(highscores))
	{
		Vec2d position(left_corner.getX() + offset, left_corner.getY());
		for (auto &s : letter->getSymbols())
		{
			drawer->drawShapeWithVertices(position, *s, GREEN);
		}
		offset += letter->getWidth();
	}

	//Show level name
	std::string level_name = stats.level_name;
	length = 0;
	for (auto& letter : font.get(level_name))
	{
		length += letter->getWidth();
	}
	double level_name_center = length/2;
	// Vec2d center(this->game_width/2, this->game_height/2);
	left_corner = {this->game_width/2 - level_name_center, 40};
	offset = 0;
	for (auto& letter : font.get(level_name))
	{
		Vec2d position(left_corner.getX() + offset, left_corner.getY());
		for (auto &s : letter->getSymbols())
		{
			drawer->drawShapeWithVertices(position, *s, GREEN);
		}
		offset += letter->getWidth();
	}

	//Show lifepoints
	std::string lifepoints = "Lifepoints: " + std::to_string(stats.player_lifepoints);
	length = 0;
	for (auto& letter : font.get(lifepoints))
	{
		length += letter->getWidth();
	}
	left_corner = {right_corner.getX() - length, right_corner.getY()};
	offset = 0;
	for (auto& letter : font.get(lifepoints))
	{
		Vec2d position(left_corner.getX() + offset, left_corner.getY());
		for (auto &s : letter->getSymbols())
		{
			drawer->drawShapeWithVertices(position, *s, GREEN);
		}
		offset += letter->getWidth();
	}
}