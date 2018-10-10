#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable {

public:

	Entity();
	~Entity() = default;

	sf::Vector2<int> get_coords();
	void set_coords(sf::Vector2<int> new_coords);
	void move_by(sf::Vector2<int> move_coords);

private:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Sprite sprite;

	sf::Vector2<int> coords;

};