#pragma once
#include "MainHeader.h"

class State {
protected:
	StateType stateType;
	sf::RenderWindow *window;
	Config config;

public:
	State();
	State(sf::RenderWindow *window, Config config);
	~State();

	virtual void event();
	virtual void update();
	virtual void render();
	virtual StateType run();
};