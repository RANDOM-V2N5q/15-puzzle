#pragma once
#include "MainHeader.h"

class Menu : public State {
private:
	std::vector<Button*> buttons;
	sf::Event::MouseMoveEvent mousePosition;
	bool mousePressed;

public:
	Menu(sf::RenderWindow *window, Config config);
	~Menu();

	void event();
	void update();
	void render();
	StateType run();

	bool isMouseOnButton(Button btn);
};

