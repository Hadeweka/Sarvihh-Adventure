#pragma once

#include <SFML/Graphics.hpp>

class Collision_Shape {

public:

	Collision_Shape() = default;

};



class CS_Circle : public Collision_Shape {

public:

	CS_Circle() = default;
	CS_Circle(sf::Vector2f center, float radius);

	sf::Vector2f get_center();
	float get_radius();

private:

	sf::Vector2f center;
	float radius = 0.0f;

};



class CS_Ellipse: public Collision_Shape {

public:

	CS_Ellipse() = default;
	CS_Ellipse(sf::Vector2f center, float major_axis, float minor_axis, float angle = 0.0f);

	sf::Vector2f get_center();
	float get_major_axis();
	float get_minor_axis();
	float get_angle();

private:

	sf::Vector2f center;
	float major_axis = 0.0f;
	float minor_axis = 0.0f;
	float angle = 0.0f;

};