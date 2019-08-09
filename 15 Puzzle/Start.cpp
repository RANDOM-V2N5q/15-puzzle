#include "MainHeader.h"


Start::Start(sf::RenderWindow *window, Config config) : State(window, config) {
	stateType = StateType::start;
	renderWindow = 1;

	prepareTextures();
	createTiles();
	initPuzzelsOnPlane();
	random();
}

Start::~Start() {
	for(int i = 0; i < getColumns(); i++) {
		delete puzzelsOnPlane[i];
	}
	delete puzzelsOnPlane;
}

void Start::event() {
	sf::Event event;
	while(window->pollEvent(event)) {
		if(event.type == sf::Event::Closed) {
			window->close();
		}
		else if(event.type == sf::Event::MouseButtonPressed) {
			sf::Sprite *tmp = getTile(event.mouseButton.x, event.mouseButton.y);
			if(tmp != nullptr) {
				move(tmp);
			}
			renderWindow = 1;
		}
		else if(event.type == sf::Event::KeyPressed) {
			if(event.key.code == sf::Keyboard::R) {
				reset();
				random();
				renderWindow = 1;
			}
		}
	}
}

void Start::update() {
}

void Start::render() {
	window->clear();
	for(int i = 0; i < tiles.size(); i++) {
		window->draw(tiles[i]);
	}
	window->display();
}

StateType Start::run() {
	while(stateType == StateType::start && window->isOpen()) {
		event();
		if(renderWindow) {
			render();
			renderWindow = 0;
		}
	}
	return StateType();
}

int Start::getRows() {
	return image.getSize().y / config.getTileSize();
}

int Start::getColumns() {
	return image.getSize().x / config.getTileSize();
}

sf::Sprite * Start::getTile(int x, int y) {
	for(int i = 0; i < tiles.size(); i++) {
		if((tiles[i].getPosition().x < x) && (tiles[i].getPosition().x + config.getTileSize() > x) && (tiles[i].getPosition().y < y) && (tiles[i].getPosition().y + config.getTileSize() > y)) {
			return &tiles[i];
		}
	}
	return nullptr;
}

void Start::move(sf::Sprite* t) {
	int col = t->getPosition().x / config.getTileSize();
	int row = t->getPosition().y / config.getTileSize();
	int x = t->getPosition().x;
	int y = t->getPosition().y;

	if(col > 0) {
		if(puzzelsOnPlane[col - 1][row] == 0) {
			t->setPosition(sf::Vector2f(x - config.getTileSize(), y));
			puzzelsOnPlane[col - 1][row] = 1;
			puzzelsOnPlane[col][row] = 0;
		}
	}
	if(col < getColumns() - 1) {
		if(puzzelsOnPlane[col + 1][row] == 0) {
			t->setPosition(sf::Vector2f(x + config.getTileSize(), y));
			puzzelsOnPlane[col + 1][row] = 1;
			puzzelsOnPlane[col][row] = 0;
		}
	}
	if(row > 0) {
		if(puzzelsOnPlane[col][row - 1] == 0) {
			t->setPosition(sf::Vector2f(x, y - config.getTileSize()));
			puzzelsOnPlane[col][row - 1] = 1;
			puzzelsOnPlane[col][row] = 0;
		}
	}
	if(row < getRows() - 1) {
		if(puzzelsOnPlane[col][row + 1] == 0) {
			t->setPosition(sf::Vector2f(x, y + config.getTileSize()));
			puzzelsOnPlane[col][row + 1] = 1;
			puzzelsOnPlane[col][row] = 0;
		}
	}
}

void Start::reset() {
	tiles.clear();
	createTiles();
	setValues();
}

void Start::random() {
	for(int i = 0; i < 1000; i++) {
		move(&tiles[rand() % (getColumns()*getRows() - 2)]);
	}
}

void Start::prepareTextures() {
	image.loadFromFile(config.getPhotoFileName());
	sf::Texture texture;

	for(int col = 0; col < image.getSize().x; col += config.getTileSize()) {
		for(int row = 0; row < image.getSize().y; row += config.getTileSize()) {
			texture.loadFromImage(image, sf::IntRect(col, row, config.getTileSize(), config.getTileSize()));
			tilesTextures.push_back(texture);
		}
	}
}

void Start::createTiles() {
	sf::Sprite srite;
	int i{};

	for(int col = 0; col < getColumns(); col++) {
		for(int row = 0; row < getRows(); row++) {
			srite.setTexture(tilesTextures[i++]);
			srite.setPosition(sf::Vector2f(col*config.getTileSize(), row*config.getTileSize()));
			tiles.push_back(srite);
		}
	}
	tiles.pop_back();
}

void Start::initPuzzelsOnPlane() {
	createTable();
	setValues();
}

void Start::createTable() {
	puzzelsOnPlane = new bool*[getColumns()];
	for(int i = 0; i < getColumns(); i++) {
		puzzelsOnPlane[i] = new bool[getRows()];
	}
}

void Start::setValues() {
	for(int i = 0; i < getColumns(); i++) {
		for(int j = 0; j < getRows(); j++) {
			puzzelsOnPlane[i][j] = 1;
		}
	}
	puzzelsOnPlane[getColumns() - 1][getRows() - 1] = 0;
}
