
#include "PingPongPing.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "GameScreen.h"
#include "SceneManager.h"

void PingPongPing::Setup() {
	mainWindow.setVerticalSyncEnabled(true);
	mainWindow.setKeyRepeatEnabled(false);

	printf("Registering Scenes...\n");

	// Register scenes
	SceneManager::RegisterScene(new SplashScreen(mainWindow));
	SceneManager::RegisterScene(new MainMenu(mainWindow));
	SceneManager::RegisterScene(new GameScreen(mainWindow));
	
	// Show splash screen
	printf("Showing Splash...\n");
	SceneManager::LoadScene("Splash");
}

void PingPongPing::GameLoop(INT32 ms) {
	SceneManager::activeScene->update(ms);
}

void PingPongPing::Render() {
	mainWindow.clear();
	SceneManager::activeScene->draw();
	mainWindow.display();
}

