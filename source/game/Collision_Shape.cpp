#include "Collision_Shape.h"

CS_Circle::CS_Circle(sf::Vector2f center, float radius) {

	this->center = center;
	this->radius = radius;

}

sf::Vector2f CS_Circle::get_center() {

	return center;

}

float CS_Circle::get_radius() {

	return radius;

}

CS_Ellipse::CS_Ellipse(sf::Vector2f center, float major_axis, float minor_axis, float angle) {

	this->center = center;
	this->major_axis = major_axis;
	this->minor_axis = minor_axis;
	this->angle = angle;

}

sf::Vector2f CS_Ellipse::get_center() {

	return center;

}

float CS_Ellipse::get_major_axis() {

	return major_axis;

}

float CS_Ellipse::get_minor_axis() {

	return minor_axis;

}

float CS_Ellipse::get_angle() {

	return angle;

}