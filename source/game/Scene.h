#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Running_Game.h"

enum class Scene_ID {

	None,
	No_Change,
	Map,
	Menu

};

class Scene {

public:

	Scene(std::shared_ptr<sf::RenderWindow> window, 
		std::shared_ptr<Scene_ID> next_scene_id, 
		std::shared_ptr<Running_Game> running_game);
	~Scene() = default;

	void draw();
	void update();

	virtual void on_init();
	virtual void on_exit();

	virtual void process_events();
	
protected:

	virtual void draw_routine();
	virtual void update_routine();

	void change_scene(Scene_ID scene_id);

	std::shared_ptr<sf::RenderWindow> window;

	std::shared_ptr<Scene_ID> next_scene_id;

	std::shared_ptr<Running_Game> running_game;

};
