#pragma once
#include "MainHeader.h"

class Button : public sf::Sprite {
private:
	StateType stateType;
	sf::Texture normal;
	sf::Texture hover;

	static int count;
public:
	Button(StateType stateType);
	~Button();

	StateType onClick();
	void onHover();
	void setDefault();
};

