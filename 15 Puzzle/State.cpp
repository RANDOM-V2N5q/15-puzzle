#include "MainHeader.h"

State::State() {
}

State::State(sf::RenderWindow *window, Config config) {
	this->window = window;
	this->config = config;
}

State::~State() {
}

void State::event() {
}

void State::update() {
}

void State::render() {
}

StateType State::run() {
	return StateType();
}
