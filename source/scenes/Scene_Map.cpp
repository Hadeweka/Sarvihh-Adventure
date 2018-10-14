#pragma once

#include "Scene_Map.h"

void Scene_Map::on_init() {

	if (!running_game->has_map()) {

		running_game->generate_map();

	}

	map = running_game->get_map();

	//! Debug starting position

	actor = std::make_shared<Entity>();
	actor->set_coords(sf::Vector2f(1920.0f * 0.5f, 1080.0f * 0.5f));

	if (!sarvihh_texture.loadFromFile("media/graphics/Sarvihh.png")) {

		exit(-1);
		//! TODO: Error handling
	}

	actor->set_texture(sarvihh_texture);
	actor->set_texture_rect(sf::IntRect(0, 0, 50, 30));

	view = sf::View(sf::FloatRect(0, 0, 1920, 1080));
	update_view();

}

void Scene_Map::draw_routine() {

	auto actor_coords = actor->get_coords();
	map->reload_layers(actor_coords.x, actor_coords.y);
	window->draw(*map, sf::BlendAlpha);
	window->draw(*actor, sf::BlendAlpha);
}

void Scene_Map::update_routine() {

	map->update();
	update_view();

}

void Scene_Map::update_view() {

	auto actor_coords = actor->get_coords();
	view.setCenter(actor_coords.x, actor_coords.y);
	window->setView(view);

}

void Scene_Map::process_events() {

	sf::Event event;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		actor->move_by(sf::Vector2f(-6.0f, 0.0f));
		actor->turn_towards(0.0f, 6.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		actor->move_by(sf::Vector2f(6.0f, 0.0f));
		actor->turn_towards(180.0f, 6.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		actor->move_by(sf::Vector2f(0.0f, -6.0f));
		actor->turn_towards(90.0f, 6.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		actor->move_by(sf::Vector2f(0.0f, 6.0f));
		actor->turn_towards(270.0f, 6.0f);
	}

	while (window->pollEvent(event)) {

		if (event.key.code == sf::Keyboard::Escape) change_scene(Scene_ID::None);

	}

}