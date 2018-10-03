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

	change_scene<Scene_Test>();
	initialize_new_scene();

}

void Game::loop() {

	while (window->isOpen()) {

		scene->draw();
		scene->process_events();
		scene->update();

		if (next_scene) initialize_new_scene();

	}

	//system("pause");

}

template <typename T> void Game::change_scene() {
	
	next_scene = std::make_unique<T>(window);

}

void Game::initialize_new_scene() {

	scene = std::move(next_scene);
	scene->init();
	next_scene = nullptr;

}