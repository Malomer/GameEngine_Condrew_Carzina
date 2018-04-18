#pragma once

#include "Scene.h"

class SplashScreen : public Scene {
	using Scene::Scene;

public:

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	sf::Text startText;

	void Start();
	void End();
	void draw();
	virtual bool update(INT32 time);
	virtual bool handleEvent(const sf::Event& event);

	std::string GetScreenType() {
		return "Splash";
	}
};
