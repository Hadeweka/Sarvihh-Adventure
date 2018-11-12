#include "Entity.h"

Entity::Entity() {

	sprite.setRotation(0.0f);

}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	states.transform *= getTransform();
	target.draw(sprite, states);

}

sf::Vector2i Entity::get_int_coords() {

	return sf::Vector2i(get_coords());

}

void Entity::tick() {

	auto distance_per_movement_tick = velocity * 0.05f;

	move_by(distance_per_movement_tick);

}

sf::Vector2f Entity::get_coords() {

	return sf::Vector2f(sprite.getPosition());

}

void Entity::set_coords(sf::Vector2f new_coords) {

	sprite.setPosition(new_coords);

}

void Entity::move_by(sf::Vector2f move_coords) {

	sprite.move(move_coords);

}

void Entity::turn_towards(float angle, float speed) {

	//! TODO: Check collisions. Do this by buffering the input.
	
	auto previous_angle = get_angle();
	auto difference_angle = std::remainderf((previous_angle - angle), 360.0f);

	if (fabs(difference_angle) <= speed * 1.0f) {
	
		set_angle(angle);
	
	} else {

		rotate_by(difference_angle <= 0.0f ? speed : -speed);

	}

}

void Entity::rotate_by(float angle) {

	sprite.rotate(angle);

}

void Entity::set_angle(float angle) {

	sprite.setRotation(angle);

}

void Entity::single_motion(sf::Vector2f motion_velocity) {

	velocity = motion_velocity;
}

float Entity::get_angle() {

	return sprite.getRotation();

}

void Entity::set_texture(const sf::Texture& texture) {

	sprite.setTexture(texture);

}

void Entity::set_texture_rect(const sf::IntRect& rectangle) {

	sprite.setTextureRect(rectangle);
	//! TODO: Enable custom midpoint instead of rectangle mid
	sprite.setOrigin(sf::Vector2f(0.5f * static_cast<float>(rectangle.width), 0.5f * static_cast<float>(rectangle.height)));

}
