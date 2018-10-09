#pragma once

#include "Scene_Map.h"

void Scene_Map::on_init() {

	if (!running_game->has_map()) {

		running_game->generate_map();

	}

	map = running_game->get_map();

	actor_x = 0.5f * 32.0f;
	actor_y = 0.5f * 18.0f;

	view = sf::View(sf::FloatRect(0, 0, 1920, 1080));
	update_view();

}

void Scene_Map::draw_routine() {

	map->reload_layers(actor_x, actor_y);
	window->draw(*map, sf::BlendAlpha);
}

void Scene_Map::update_routine() {

	map->update();
	update_view();

}

void Scene_Map::update_view() {

	view.setCenter(actor_x * 60, actor_y * 60);
	window->setView(view);

}

void Scene_Map::process_events() {

	sf::Event event;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) actor_x -= 0.1f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) actor_x += 0.1f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) actor_y -= 0.1f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) actor_y += 0.1f;

	while (window->pollEvent(event)) {

		if (event.key.code == sf::Keyboard::Escape) change_scene(Scene_ID::None);
		if (event.key.code == sf::Keyboard::Enter) change_scene(Scene_ID::Test_2);

	}

}