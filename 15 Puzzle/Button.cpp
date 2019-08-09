#include "MainHeader.h"

Button::Button(StateType stateType) {
	if(stateType == StateType::start) {
		this->stateType = StateType::start;
		normal.loadFromFile("img/start.png");
		hover.loadFromFile("img/start-hover.png");
	}
	else if(stateType == StateType::exit) {
		this->stateType = StateType::exit;
		normal.loadFromFile("img/exit.png");
		hover.loadFromFile("img/exit-hover.png");
	}
	this->setPosition(250, 325 + count * 200);
	this->setTexture(normal);
	count++;
}

Button::~Button() {
	count -= 1;
}

StateType Button::onClick() {
	return stateType;
}

void Button::onHover() {
	this->setTexture(hover);
}

void Button::setDefault() {
	this->setTexture(normal);
}

int Button::count = 0;
