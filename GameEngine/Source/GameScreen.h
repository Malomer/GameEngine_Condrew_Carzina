#pragma once

#include "Scene.h"
#include "Powerup.h"
#include "PowerupManager.h"

#include <vector>

class GameScreen : public Scene {
	using Scene::Scene;

public:

	std::vector<Powerup> activePowerups;
	PowerupManager *powerupManager;

	void CreatePowerup(PowerupType type);
	virtual void Start();
	virtual void End();
	virtual void draw();
	virtual bool update(INT32 time);
	virtual bool handleEvent(const sf::Event& event);

	std::string GetScreenType() {
		return "Game";
	}
};
