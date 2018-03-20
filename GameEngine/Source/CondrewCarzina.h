#pragma once

#include "SFML/Graphics.hpp"
#include "GameObjectManager.h"
#include <direct.h>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <stdint.h>
#include <iostream>

class CondrewCarzina {

public:
	void Start();
	void Initialize();

	bool CheckStorage(const long diskSpaceNeeded);
	bool CheckMemory(const long physicalRAMNeeded, const long virtualRAMNeeded);
	DWORD ReadCPUSpeed();

	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };

	bool isExiting;

private:
	bool IsExiting();
	void GameLoop(INT32 time);

	//GameObjectManager gameObjectManager;
	GameState gameState;
	sf::RenderWindow mainWindow;
};