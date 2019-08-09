#include "MainHeader.h"

Menu::Menu(sf::RenderWindow *window, Config config) : State(window, config) {
	stateType = StateType::menu;

	buttons.push_back(new Button(StateType::start));
	buttons.push_back(new Button(StateType::exit));
}

Menu::~Menu() {
}

void Menu::event() {
	sf::Event event;
	while(window->pollEvent(event)) {
		if(event.type == sf::Event::Closed) {
			window->close();
		}
		else if(event.type == sf::Event::MouseMoved) {
			mousePosition = event.mouseMove;
		}
		else if(event.type == sf::Event::MouseButtonReleased) {
			mousePressed = 1;
		}
	}
}

void Menu::update() {
	for(int i = 0; i < buttons.size(); i++) {
		if(isMouseOnButton(*buttons[i])) {
			if(mousePressed) {
				stateType = buttons[i]->onClick();
			}
			else {
				buttons[i]->onHover();
			}
		}
		else {
			buttons[i]->setDefault();
		}
	}
	mousePressed = 0;
}

void Menu::render() {
	window->clear();
	for(int i = 0; i < buttons.size(); i++) {
		window->draw(*buttons[i]);
	}
	window->display();
}

StateType Menu::run() {
	while(stateType == StateType::menu && window->isOpen()) {
		event();
		update();
		render();
	}
	return stateType;
}

bool Menu::isMouseOnButton(Button btn) {
	int left = btn.getPosition().x;
	int top = btn.getPosition().y;
	int width = btn.getTextureRect().width;
	int height = btn.getTextureRect().height;
	int x = mousePosition.x;
	int y = mousePosition.y;

	if((left < x) && (left + width > x) && (top < y) && (top + height > y)) {
		return 1;
	}
	else {
		return 0;
	}
}
