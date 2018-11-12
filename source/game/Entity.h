#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable {

public:

	Entity();
	~Entity() = default;

	void tick();

	sf::Vector2f get_coords();
	sf::Vector2i get_int_coords();

	void set_coords(sf::Vector2f new_coords);
	void move_by(sf::Vector2f move_coords);

	void rotate_by(float angle);
	float get_angle();
	void set_angle(float angle);

	void single_motion(sf::Vector2f motion_velocity);

	void turn_towards(float angle, float speed);

	void set_texture(const sf::Texture& texture);
	void set_texture_rect(const sf::IntRect& rectangle);

private:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Sprite sprite;

	sf::Vector2f velocity;

};