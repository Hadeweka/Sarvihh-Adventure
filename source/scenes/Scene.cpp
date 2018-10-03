#include "Scene.h"

Scene::Scene(std::shared_ptr<sf::RenderWindow> window) {

	this->window = window;

}

void Scene::draw() {

	window->clear();

	draw_routine();

	window->display();

}

void Scene::update() {

	update_routine();

}

void Scene::init() {

	//! Initialization stuff here

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