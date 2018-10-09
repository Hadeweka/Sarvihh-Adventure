#pragma once

#include <memory>

#include "Map.h"

class Running_Game {

public:

	Running_Game();
	~Running_Game() = default;

	bool has_map();
	std::shared_ptr<Map> get_map();
	void generate_map();

private:

	std::shared_ptr<Map> map = nullptr;

};