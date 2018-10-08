#include "Game.h"

#include <iostream>

Game::Game() {

	auto res_width = sf::VideoMode::getDesktopMode().width;
	auto res_height = sf::VideoMode::getDesktopMode().height;

	constexpr unsigned int reference_width = 1920;
	constexpr unsigned int reference_height = 1080;

	window = std::make_shared<sf::RenderWindow>(sf::VideoMode(res_width, res_height), "The Adventure of Sarvihh", sf::Style::Fullscreen);

	//window->setFramerateLimit(60);	//! Maybe 120
	window->setVerticalSyncEnabled(true);

	next_scene_id = std::make_shared<Scene_ID>(Scene_ID::Map);
	initialize_new_scene();

}

void Game::loop() {

	//! Main loop
	while (window->isOpen() && scene) {

		scene->draw();
		scene->process_events();
		scene->update();

		if (*next_scene_id == Scene_ID::None) {
			scene = nullptr;
		} else if (*next_scene_id != Scene_ID::No_Change) {
			initialize_new_scene();
		}

	}

	if (window->isOpen()) window->close();

}

void Game::initialize_new_scene() {

	//! Clean up last scene if available
	if(scene) scene->on_exit();

	//! Change to new scene
	if (*next_scene_id == Scene_ID::Map) scene = std::make_shared<Scene_Map>(window, next_scene_id);
	if (*next_scene_id == Scene_ID::Menu) scene = std::make_shared<Scene_Menu>(window, next_scene_id);
	if (*next_scene_id == Scene_ID::Test_2) scene = std::make_shared<Scene_Test_2>(window, next_scene_id);

	scene->on_init();
	*next_scene_id = Scene_ID::No_Change;

}