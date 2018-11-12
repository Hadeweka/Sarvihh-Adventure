#include "Collider.h"

bool Collider::check_circle_against_circle(sf::Vector2f circle_1_center, float circle_1_radius, 
	sf::Vector2f circle_2_center, float circle_2_radius) {

	auto c1x = circle_1_center.x;
	auto c1y = circle_1_center.y;

	auto c2x = circle_2_center.x;
	auto c2y = circle_2_center.y;

	auto r1 = circle_1_radius;
	auto r2 = circle_2_radius;

	auto dx = c1x - c2x;
	auto dy = c1y - c2y;

	auto squared_distance = dx * dx + dy * dy;
	
	auto radius_sum = r1 + r2;
	auto squared_radius_sum = radius_sum * radius_sum;
	
	return (squared_distance < squared_radius_sum);

}