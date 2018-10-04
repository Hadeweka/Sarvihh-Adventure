#include "Scene.h"

Scene::Scene(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Scene_ID> next_scene_id) {

	this->window = window;
	this->next_scene_id = next_scene_id;

}

void Scene::draw() {

	window->clear();

	draw_routine();

	window->display();

}

void Scene::update() {

	update_routine();

}

void Scene::on_init() {

	//! Initialization stuff here

}

void Scene::on_exit() {

	//! Finalization stuff here

}

void Scene::draw_routine() {

	//! Drawing stuff here

}

void Scene::process_events() {

	//! Event processing here

}

void Scene::update_routine() {

	//! Updating stuff here

}

void Scene::change_scene(Scene_ID scene_id) {

	*next_scene_id = scene_id;

}
