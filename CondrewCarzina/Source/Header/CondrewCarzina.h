#pragma once

#include "SFML/Window.hpp" 
#include "SFML/Graphics.hpp"
#include <direct.h>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>

class CondrewCarzina { 

public:
	void Start();
	void Initialize(); 

	bool CheckStorage(const long diskSpaceNeeded);
	bool CheckMemory(const long physicalRAMNeeded, const long virtualRAMNeeded);
	DWORD ReadCPUSpeed();

	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };

private:
    //bool IsExiting();
	//void GameLoop();

	GameState gameState;
	sf::RenderWindow mainWindow; 
};