#pragma once
#include "MainHeader.h"

class Start : public State {
	sf::Image image;
	std::vector<sf::Texture> tilesTextures;
	std::vector<sf::Sprite> tiles;
	bool **puzzelsOnPlane;
	bool renderWindow;

	void prepareTextures();
	void createTiles();
	void initPuzzelsOnPlane();
	void createTable();
	void setValues();
	int getRows();
	int getColumns();
	sf::Sprite* getTile(int x, int y);
	void move(sf::Sprite* t);
	void reset();
	void random();
public:
	Start(sf::RenderWindow *window, Config config);
	~Start();

	void event();
	void update();
	void render();
	StateType run();
};

