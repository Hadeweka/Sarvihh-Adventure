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

	auto turn_angle = 0.0f;
	auto turn_count = 0u;

	auto motion = sf::Vector2f();

	auto go_up = false;
	auto go_down = false;
	auto go_left = false;
	auto go_right = false;

	auto do_turn = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		go_left = true;
		motion.x -= 6.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		go_right = true;
		motion.x += 6.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		go_up = true;
		motion.y -= 6.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		go_down = true;
		motion.y += 6.0f;
	}

	int dir_x = (go_right - go_left);
	int dir_y = (go_down - go_up);

	if (dir_x == 1) {

		if (dir_y == -1) turn_angle = 135.0f;
		else if (dir_y == 0) turn_angle = 180.0f;
		else if (dir_y == 1) turn_angle = 225.0f;

	} else if (dir_x == 0) {

		if (dir_y == -1) turn_angle = 90.0;
		else if (dir_y == 0) do_turn = false;
		else if (dir_y == 1) turn_angle = 270.0f;

	} else if (dir_x == -1) {

		if (dir_y == -1) turn_angle = 45.0f;
		else if (dir_y == 0) turn_angle = 0.0f;
		else if (dir_y == 1) turn_angle = 315.0f;

	}

	actor->move_by(motion);

	if(do_turn) actor->turn_towards(turn_angle, 6.0f);

	while (window->pollEvent(event)) {

		if (event.key.code == sf::Keyboard::Escape) change_scene(Scene_ID::None);

	}

}