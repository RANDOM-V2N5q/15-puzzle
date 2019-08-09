#pragma once
#include "MainHeader.h"

class App {
private:
	int argc;
	char **argv;

	Config config;
	sf::RenderWindow *window;
	StateType stateType;
	State *state;

	void createConfig();
	void createWindow();
public:
	App(int argc, char *argv[]);
	~App();

	void run();
};

