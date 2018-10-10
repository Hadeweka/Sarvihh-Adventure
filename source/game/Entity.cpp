#include "Entity.h"

Entity::Entity() {


}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	states.transform *= getTransform();

}

sf::Vector2<int> Entity::get_coords() {

	return coords;

}

void Entity::set_coords(sf::Vector2<int> new_coords) {

	coords = new_coords;

}

void Entity::move_by(sf::Vector2<int> move_coords) {

	coords += move_coords;

}