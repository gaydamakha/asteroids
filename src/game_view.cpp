#include <string>
#include "interface/game_view.h"
#include "interface/drawer.h"
#include "entities/asteroid.h"

GameView::GameView(const std::string &game_name, int game_width, int game_height, const Color &background) : game_width(game_width), game_height(game_height)
{
	this->game_name = game_name;
	this->background = background;
	left_up_corner = {x_padding, (double)(game_height - y_padding)};
	right_up_corner = {(double)(game_width - x_padding), double(game_height - y_padding)};
	highscores_stat_pos = {left_up_corner.getX(), left_up_corner.getY() - str_h};
	this->center = {double(game_width / 2), (double)(game_height / 2)};
}
void GameView::clear() const
{
	drawer->fillScreen(background);
}

void GameView::update(const GameModel &game_model)
{
	if (!game_model.isBegan())
		return;
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

	this->showStats(game_model.getStats());
}

void GameView::showAsteroid(const Asteroid &a) const
{
	drawer->drawShape(a.getShape(), a.getColor());
}

void GameView::showShip(const Ship &s) const
{
	drawer->drawShape(s.getShape(), s.getColor());
}

void GameView::showBullet(const Bullet &b) const
{
	std::shared_ptr<Circle> c = std::static_pointer_cast<Circle>(b.getColliderShape());
	drawer->drawSquare(c->getRadius(), b.getCoords(), b.getColor());
}

void GameView::showStats(const GameStats &stats) const
{
	unsigned offset = 0;
	unsigned length = 0;
	Vec2d current_pos;
	Font letters;
	//Show scores at left up corner
	std::string scores = "Scores: " + std::to_string(stats.player_scores);
	letters = font.get(scores);
	for (auto &letter : letters)
	{
		Vec2d position(left_up_corner.getX() + offset, left_up_corner.getY());
		for (auto &s : letter->getSymbols())
		{
			drawer->drawShape(position, s, GREEN);
		}
		offset += letter->getWidth();
	}

	//Show highscores
	std::string highscores = "Highscores: " + std::to_string(stats.player_highscores);
	offset = 0;
	letters = font.get(highscores);
	for (auto &letter : letters)
	{
		Vec2d position(highscores_stat_pos.getX() + offset, highscores_stat_pos.getY());
		for (auto &s : letter->getSymbols())
		{
			drawer->drawShape(position, s, GREEN);
		}
		offset += letter->getWidth();
	}

	//Show level name at the center
	this->showText({(double)(this->game_width / 2), y_padding}, stats.level_name, GREEN);

	//Show lifepoints
	std::string lifepoints = "Lifepoints: " + std::to_string(stats.player_lifepoints);
	length = 0;
	letters = font.get(lifepoints);
	for (auto &letter : letters)
	{
		length += letter->getWidth();
	}
	current_pos = {right_up_corner.getX() - length, right_up_corner.getY()};
	offset = 0;
	for (auto &letter : font.get(lifepoints))
	{
		Vec2d position(current_pos.getX() + offset, current_pos.getY());
		for (auto &s : letter->getSymbols())
		{
			drawer->drawShape(position, s, GREEN);
		}
		offset += letter->getWidth();
	}
}

void GameView::showButton(const Button &button) const
{
	drawer->drawShape(button.getColliderShape(), button.getColor());
	this->showText({button.getPosition().getX(), button.getPosition().getY() + str_h / 3}, button.getText(), button.getColor());
}

void GameView::showText(const Vec2d& pos, const std::string text, const Color& color) const
{
	Vec2d current_pos;
	unsigned offset = 0;
	unsigned length = 0;
	Font letters = font.get(text);
	for (auto &letter : letters)
	{
		length += letter->getWidth();
	}
	current_pos = {pos.getX() - length / 2, pos.getY()};
	for (auto &letter : letters)
	{
		Vec2d position(current_pos.getX() + offset, current_pos.getY());
		for (auto &s : letter->getSymbols())
		{
			drawer->drawShape(position, s, color);
		}
		offset += letter->getWidth();
	}
}
