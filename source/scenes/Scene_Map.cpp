#pragma once

#include "Scene_Map.h"

void Scene_Map::on_init() {

	if (!running_game->has_map()) {

		running_game->generate_map();

	}

	map = running_game->get_map();

	//! Debug starting position

	actor = std::make_shared<Entity>();
	actor->set_coords(sf::Vector2<int>(1920 / 2, 1080 / 2));

	view = sf::View(sf::FloatRect(0, 0, 1920, 1080));
	update_view();

}

void Scene_Map::draw_routine() {

	auto actor_coords = actor->get_coords();
	map->reload_layers(static_cast<float>(actor_coords.x), static_cast<float>(actor_coords.y));
	window->draw(*map, sf::BlendAlpha);
}

void Scene_Map::update_routine() {

	map->update();
	update_view();

}

void Scene_Map::update_view() {

	auto actor_coords = actor->get_coords();
	view.setCenter(static_cast<float>(actor_coords.x), static_cast<float>(actor_coords.y));
	window->setView(view);

}

void Scene_Map::process_events() {

	sf::Event event;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) actor->move_by(sf::Vector2i(-6, 0));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) actor->move_by(sf::Vector2i(6, 0));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) actor->move_by(sf::Vector2i(0, -6));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) actor->move_by(sf::Vector2i(0, 6));

	while (window->pollEvent(event)) {

		if (event.key.code == sf::Keyboard::Escape) change_scene(Scene_ID::None);

	}

}