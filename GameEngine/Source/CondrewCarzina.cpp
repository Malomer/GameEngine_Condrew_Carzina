#include "CondrewCarzina.h"
#include "RenderComponent.h"

#include "ChildInput.h"
#include "ParentInput.h"

#include <SFML/Graphics.hpp>

void CondrewCarzina::Initialize() {
	gameState = GameState::Uninitialized;

	// No minimum requirements yet TODO: Change this later

	/*
		Storage is not required for the game to run.
	if (CheckStorage(0)) {
		return;
	}
	*/

	if (CheckMemory(0, 0)) {
		return;
	}

	if (ReadCPUSpeed() < 0) {
		return;
	}

	gameState = GameState::ShowingSplash;
}

void CondrewCarzina::Start() {
	//if (gameState != Uninitialized)
	//	return;

	mainWindow.create(sf::VideoMode(1024, 768), "Ping Pong Ping");
	gameState = GameState::ShowingSplash;
	
	Setup();

	printf("Done setup! Starting game loop...\n");
	sf::Clock clock;
	//while (!IsExiting()) {
	while (true) {
		sf::Time elapsed = clock.restart();
		// float deltaTime = clock.restart().asSeconds();
		HandleEvents();
		//GameLoop(clock.getElapsedTime().asMilliseconds());
		//GameLoop(elapsed.asMilliseconds()); --
		GameLoop(elapsed.asSeconds());
		Render();
		//GameLoop(clock.getElapsedTime().asMilliseconds());
	}

	mainWindow.close();
}

std::string ExePath() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}

void CondrewCarzina::Setup() {
	mainWindow.setVerticalSyncEnabled(true);
	mainWindow.setKeyRepeatEnabled(false);

	//C:\Users\Andrew\Documents\Github\GameEngine_Condrew_Carzina\GameEngine\Build\Debug
	std::cout << "my directory is " << ExePath() << "\n";

	if (backgroundTexture.loadFromFile("Assets\\texture.jpg")) {
	}

	// Setup Splash Screen
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setOrigin(backgroundSprite.getLocalBounds().width / 2.f, backgroundSprite.getLocalBounds().height / 2.f);
	backgroundSprite.setPosition(mainWindow.getSize().x / 2.f, mainWindow.getSize().y / 2.f);

	// Setup Playing Screen
	parent = gameObjectManager.CreateObject("Parent");
	child = gameObjectManager.CreateObject("Child");

	child->SetParent(parent);

	//parent->AddComponent(StrongComponentPtr(new ParentInput(mainWindow)));
	//child->AddComponent(StrongComponentPtr(new ChildInput(mainWindow)));
}

void CondrewCarzina::GameLoop(INT32 time) {
	mainWindow.clear();

	switch (gameState) {
	case ShowingSplash:
		UpdateSplash();
		break;

	case Playing:
		UpdatePlaying(time);
		break;
	}

	mainWindow.display();
}

void CondrewCarzina::UpdateSplash() {
	mainWindow.draw(backgroundSprite);
}

void CondrewCarzina::UpdatePlaying(INT32 time) {
	gameObjectManager.Update(time);
}

void CondrewCarzina::HandleEvents() {
	sf::Event event;

	while (mainWindow.pollEvent(event)) {

		switch (event.type) {
			
		case sf::Event::Closed:
			mainWindow.close();
			break;

		/*
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::A) {
				if (gameState == GameState::ShowingSplash) {
					gameState = GameState::Playing;
				}
			}
			break;*/
		default:
			break;
		}
	}
}

bool CondrewCarzina::IsExiting() {
	return isExiting;
}

bool CondrewCarzina::CheckStorage(const long diskSpaceNeeded) {
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 const neededClusters = diskSpaceNeeded / (diskfree.sectors_per_cluster * diskfree.bytes_per_sector);
	if (diskfree.avail_clusters < neededClusters) {
		return false;
	}
	return true;
}

bool CondrewCarzina::CheckMemory(const long physicalRAMNeeded, const long virtualRAMNeeded) {
	MEMORYSTATUSEX status;
	GlobalMemoryStatusEx(&status);
	if (status.ullTotalPhys < physicalRAMNeeded) {
		std::cout << "CheckMemory: Not enough physical memory.\n";
		return false;
	}
	if (status.ullAvailVirtual < virtualRAMNeeded) {
		std::cout << "CheckMemory: Not enough virtual memory.\n";
		return false;
	}
	char *buff = new char[virtualRAMNeeded];
	if (buff) {
		delete[] buff;
		return true;
	} else {
		std::cout << "CheckMemory: Not enough contiguous memory.\n";
		return false;
	}
}

DWORD CondrewCarzina::ReadCPUSpeed() {
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);
	if (lError == ERROR_SUCCESS) {
		RegQueryValueEx(hKey, "~MH", NULL, &type, (LPBYTE)&dwMHz, &BufSize);
	}
	return dwMHz;
}

bool IsOnlyInstance(LPCTSTR gameTitle) {
	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS) {
		HWND hWnd = FindWindow(gameTitle, NULL);
		if (hWnd) {
			// An instance of your game is already running.
			ShowWindow(hWnd, SW_SHOWNORMAL);
			SetFocus(hWnd);
			SetForegroundWindow(hWnd);
			SetActiveWindow(hWnd);
			return false;
		}
	}
	return true;
}
