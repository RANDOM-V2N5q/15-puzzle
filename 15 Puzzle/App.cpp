#include "MainHeader.h"

App::App(int argc, char *argv[]) {
	this->argc = argc;
	this->argv = argv;

	createConfig();
	createWindow();
	stateType = StateType::menu;
}

App::~App() {
}

void App::run() {
	while(window->isOpen()) {
		if(stateType == StateType::menu) {
			state = new Menu(window, config);
		}
		else if(stateType == StateType::start) {
			state = new Start(window, config);
		}
		else if(stateType == StateType::exit) {
			window->close();
			break;
		}
		stateType = state->run();
		delete state;
	}
}

void App::createConfig() {
	if(argc == 2) {
		config = Config(argv[1]);
	}
	else {
		config = Config();
	}
}

void App::createWindow() {
	window = config.getRenderWindow();
}
