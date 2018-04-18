
#include "PingPongPing.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "GameScreen.h"
#include "SceneManager.h"

void PingPongPing::Setup() {
	printf("Registering Scenes...\n");

	// Register scenes
	SceneManager::RegisterScene(new SplashScreen(mainWindow));
	//SceneManager::RegisterScene(new MainMenu(mainWindow));
	//SceneManager::RegisterScene(new GameScreen(mainWindow));
	
	// Show splash screen
	printf("Showing Splash...\n");
	//SceneManager::LoadScene("Splash");
}

void PingPongPing::GameLoop(INT32 ms) {
	//SceneManager::GetActiveScene().update(ms);
}

void PingPongPing::Render() {
	//SceneManager::GetActiveScene().draw();
}

