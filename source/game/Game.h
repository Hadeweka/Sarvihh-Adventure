#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Running_Game.h"

//! Include all scenes here
#include "Scene.h"
#include "Scene_Map.h"
#include "Scene_Menu.h"
#include "Scene_Test_2.h"

class Game {

public:

	Game();
	~Game() = default;

	void loop();

private:

	void initialize_new_scene();	//! Actually switch scene to new scene

	//! Pointer to the running game (map, actor, etc.), which should survive scene changes
	std::shared_ptr<Running_Game> running_game;

	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<Scene> scene = nullptr;

	std::shared_ptr<Scene_ID> next_scene_id;
	

};