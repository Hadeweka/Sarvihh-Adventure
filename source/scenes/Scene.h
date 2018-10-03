#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class Scene {

public:

	Scene(std::shared_ptr<sf::RenderWindow> window);
	~Scene() = default;

	void draw();
	void update();

	virtual void init();
	virtual void process_events();
	
protected:

	virtual void draw_routine();
	virtual void update_routine();

	std::shared_ptr<sf::RenderWindow> window;

};