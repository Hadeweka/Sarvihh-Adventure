#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable {

public:

	Entity();
	~Entity() = default;

	sf::Vector2i get_coords();
	void set_coords(sf::Vector2i new_coords);
	void move_by(sf::Vector2i move_coords);

	void set_texture(const sf::Texture& texture);
	void set_texture_rect(const sf::IntRect& rectangle);

private:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Sprite sprite;

	sf::Vector2<int> coords;

};