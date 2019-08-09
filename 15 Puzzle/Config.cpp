#include "MainHeader.h"

Config::Config() {
	configFileName = "config.cfg";
	loadConfigFile();
}

Config::Config(char *configFileName) {
	this->configFileName = configFileName;
	loadConfigFile();
}

Config::~Config() {
}

void Config::createDefaultConfig() {
	std::fstream outputStream(configFileName, std::fstream::out);

	if(outputStream.is_open()) {
		outputStream << "framerateLimit: 60\n";
		outputStream << "width: 1000\n";
		outputStream << "height: 1000\n";
		outputStream << "bitsPerPixel: 32\n";
		outputStream << "title: Nodes\n";
		outputStream << "titleBar: 1\n";
		outputStream << "resize: 0\n";
		outputStream << "close: 1\n";
		outputStream << "fullscreen: 0\n";
		outputStream << "depth: 0\n";
		outputStream << "stencil: 0\n";
		outputStream << "antialiasing: 0\n";
		outputStream << "major: 1\n";
		outputStream << "minor: 1\n";
		outputStream << "attributes: 0\n";
		outputStream << "sRgb: 0\n";
		outputStream << "tileSize: 250\n";
		outputStream << "photoFileName: img/photo.png\n";
	}
}

void Config::loadConfigFile() {
	std::fstream inputStream(configFileName, std::fstream::in);

	if(inputStream.is_open()) {
		std::string line;
		while(inputStream >> line) {
			if(line == "framerateLimit:") {
				inputStream >> framerateLimit;
			}
			else if(line == "width:") {
				inputStream >> width;
			}
			else if(line == "height:") {
				inputStream >> height;
			}
			else if(line == "bitsPerPixel:") {
				inputStream >> bitsPerPixel;
			}
			else if(line == "title:") {
				inputStream >> title;
			}
			else if(line == "titleBar:") {
				inputStream >> titleBar;
			}
			else if(line == "resize:") {
				inputStream >> resize;
			}
			else if(line == "close:") {
				inputStream >> close;
			}
			else if(line == "fullscreen:") {
				inputStream >> fullscreen;
			}
			else if(line == "depth:") {
				inputStream >> depth;
			}
			else if(line == "stencil:") {
				inputStream >> stencil;
			}
			else if(line == "antialiasing:") {
				inputStream >> antialiasing;
			}
			else if(line == "major:") {
				inputStream >> major;
			}
			else if(line == "minor:") {
				inputStream >> minor;
			}
			else if(line == "attributes:") {
				inputStream >> attributes;
			}
			else if(line == "sRgb:") {
				inputStream >> sRgb;
			}
			else if(line == "tileSize:") {
				inputStream >> tileSize;
			}
			else if(line == "photoFileName:") {
				inputStream >> photoFileName;
			}
		}
	}
	else {
		createDefaultConfig();
		loadConfigFile();
	}
}

void Config::saveConfig() {
}

sf::VideoMode Config::getVideoMode() {
	return sf::VideoMode(width, height, bitsPerPixel);
}

std::string Config::getTitle() {
	return std::string(title);
}

unsigned int Config::getStyle() {
	unsigned int style{};

	if(titleBar) {
		style |= 1 << 0;
	}
	if(resize) {
		style |= 1 << 1;
	}
	if(close) {
		style |= 1 << 2;
	}
	if(fullscreen) {
		style |= 1 << 3;
	}
	return style;
}

sf::ContextSettings Config::getContextSettings() {
	return sf::ContextSettings(depth, stencil, antialiasing, major, minor, attributes, sRgb);
}

sf::RenderWindow* Config::getRenderWindow() {
	sf::RenderWindow *window = new sf::RenderWindow(getVideoMode(), getTitle(), getStyle(), getContextSettings());
	window->setFramerateLimit(framerateLimit);
	return window;
}

unsigned int Config::getTileSize() {
	return tileSize;
}

std::string Config::getPhotoFileName() {
	return photoFileName;
}
