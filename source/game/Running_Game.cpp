#include "Running_Game.h"

Running_Game::Running_Game() {


}

bool Running_Game::has_map() {

	return (map ? true : false);

}

std::shared_ptr<Map> Running_Game::get_map() {

	return map;

}

void Running_Game::generate_map() {

	map = std::make_shared<Map>();
	map->load(100, 100);

}