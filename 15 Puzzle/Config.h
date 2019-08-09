#pragma once
#include "MainHeader.h"

class Config {
private:
	std::string configFileName;

	//RenderWindow
			unsigned int framerateLimit;
		//VideoMode
			unsigned int width;
			unsigned int height;
			unsigned int bitsPerPixel;
		//Title
			std::string title;
		//Style
			bool titleBar;
			bool resize;
			bool close;
			bool fullscreen;
		//ContextSettings
			unsigned int depth;
			unsigned int stencil;
			unsigned int antialiasing;
			unsigned int major;
			unsigned int minor;
			unsigned int attributes;
			bool sRgb;

	//Game
			unsigned int tileSize;
			std::string photoFileName;

public:
	Config();
	Config(char *configFileName);
	~Config();

	void createDefaultConfig();
	void loadConfigFile();
	void saveConfig();

	sf::VideoMode getVideoMode();
	std::string getTitle();
	unsigned int getStyle();
	sf::ContextSettings getContextSettings();
	sf::RenderWindow* getRenderWindow();
	unsigned int getTileSize();
	std::string getPhotoFileName();
};