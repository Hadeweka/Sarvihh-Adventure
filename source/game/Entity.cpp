#include "Entity.h"

Entity::Entity() {


}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	states.transform *= getTransform();
	target.draw(sprite, states);

}

sf::Vector2i Entity::get_coords() {

	return sf::Vector2i(sprite.getPosition());

}

void Entity::set_coords(sf::Vector2i new_coords) {

	sprite.setPosition(sf::Vector2f(new_coords));

}

void Entity::move_by(sf::Vector2i move_coords) {

	sprite.move(sf::Vector2f(move_coords));

}

void Entity::set_texture(const sf::Texture& texture) {

	sprite.setTexture(texture);

}

void Entity::set_texture_rect(const sf::IntRect& rectangle) {

	sprite.setTextureRect(rectangle);
	//! TODO: Enable custom midpoint instead of rectangle mid
	sprite.setOrigin(sf::Vector2f(0.5 * static_cast<float>(rectangle.width), 0.5 * static_cast<float>(rectangle.height)));

}
