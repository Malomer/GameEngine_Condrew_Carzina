
#include "SplashScreen.h"
#include "SceneManager.h"

void SplashScreen::Start() {
	if (backgroundTexture.loadFromFile("C:\\Users\\Andrew\\Documents\\Github\\GameEngine_Condrew_Carzina\\GameEngine\\GameEngine\\Assets\\texture.jpg")) {
	}

	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setOrigin(backgroundSprite.getLocalBounds().width / 2.f, backgroundSprite.getLocalBounds().height / 2.f);
	backgroundSprite.setPosition(mainWindow->getSize().x / 2.f, mainWindow->getSize().y / 2.f);
}

void SplashScreen::End() {

}

bool SplashScreen::update(INT32 time) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		printf("Called from SpashScreen!\n");
		SceneManager::LoadScene("Game");
	}
	return true;
}

void SplashScreen::draw() {
	mainWindow->draw(backgroundSprite);
}

bool SplashScreen::handleEvent(const sf::Event& event) {
	return true;
}
