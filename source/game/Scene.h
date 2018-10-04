#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

enum class Scene_ID {

	None,
	No_Change,
	Test,
	Test_2

};

class Scene {

public:

	Scene(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Scene_ID> next_scene_id);
	~Scene() = default;

	void draw();
	void update();

	virtual void on_init();
	virtual void on_exit();

	virtual void process_events();
	
protected:

	virtual void draw_routine();
	virtual void update_routine();

	void change_scene(Scene_ID scene_id);

	std::shared_ptr<sf::RenderWindow> window;

	std::shared_ptr<Scene_ID> next_scene_id;

};
