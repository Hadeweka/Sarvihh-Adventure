#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Scene.h"
#include "Map.h"

class Scene_Map : public Scene {

public:

	using Scene::Scene;

	void on_init();

	void process_events();

private:

	void draw_routine();
	void update_routine();

	void update_view();

	Map map;
	sf::View view;

	float actor_x;
	float actor_y;

};