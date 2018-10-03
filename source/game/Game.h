#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Scene.h"
#include "Scene_Test.h"

class Game {

public:

	Game();
	~Game() = default;

	void loop();

private:

	std::shared_ptr<sf::RenderWindow> window;
	std::unique_ptr<Scene> scene;

	std::unique_ptr<Scene> next_scene = nullptr;

	template <typename T> void change_scene();	//! Create new scene object
	void initialize_new_scene();	//! Actually switch scene to new scene

};