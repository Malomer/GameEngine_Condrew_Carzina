#pragma once

#include <SFML/Graphics.hpp>
#include <windows.h>
#include "GameObjectManager.h"

class Scene {

public:

	sf::RenderWindow *mainWindow;
	GameObjectManager gameObjectManager;

	Scene(sf::RenderWindow &mainWindow) {
		this->mainWindow = &mainWindow;
	}

	virtual std::string GetScreenType() { return ""; }
	virtual void Start() { }
	virtual void End() { }
	virtual void draw() { }
	virtual bool update(INT32 time) { return true; }
	virtual bool handleEvent(const sf::Event& event) { return true; }
};
