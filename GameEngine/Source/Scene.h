#pragma once

#include "GameObjectManager.h"
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <vector>
#include "DrawableRenderer.h"
#include "ShapeRenderer.h"

class Scene {

public:

	std::vector<DrawableRenderer*> drawables;
	std::vector<ShapeRenderer*> drawables1;
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

	void RegisterDrawable(DrawableRenderer *spriteRenderer);
	void RegisterDrawable(ShapeRenderer *spriteRenderer);
	void ClearDrawables();
};
