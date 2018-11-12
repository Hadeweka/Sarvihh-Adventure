#pragma once

#include <SFML/Graphics.hpp>

namespace Collider {

	bool check_circle_against_circle(sf::Vector2f circle_1_center, float circle_1_radius, 
		sf::Vector2f circle_2_center, float circle_2_radius);

	//! TODO: More collision algorithms
	//! TODO: Ellipse - Ellipse (with rotation)
	//! TODO: Ellipse - AABB
	
	//! TODO: Better structure, maybe separate class for collision shapes

}
