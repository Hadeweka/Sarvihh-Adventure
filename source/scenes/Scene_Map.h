#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Scene.h"
#include "Map.h"
#include "Entity.h"

class Scene_Map : public Scene {

public:

	using Scene::Scene;

	void on_init();

	void process_events();

private:

	void draw_routine();
	void update_routine();

	void update_view();

	std::shared_ptr<Map> map;
	sf::View view;

	std::shared_ptr<Entity> actor;

};