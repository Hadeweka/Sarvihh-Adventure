#pragma once

class Counter {

public:

	Counter() = default;
	~Counter() = default;

	unsigned int get_value();
	void update();

private:

	unsigned int value = 0;

};