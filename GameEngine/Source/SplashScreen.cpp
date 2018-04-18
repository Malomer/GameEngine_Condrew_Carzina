
#include "SplashScreen.h"

void SplashScreen::Start() {
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setOrigin(backgroundSprite.getLocalBounds().width / 2.f, backgroundSprite.getLocalBounds().height / 2.f);
	//backgroundSprite.setPosition(mainWindow.getSize().x / 2.f, mainWindow.getSize().y / 2.f);
}

void SplashScreen::End() {

}

bool SplashScreen::update(INT32 time) {
	printf("Called from SpashScreen!");
	return true;
}

void SplashScreen::draw() {

}

bool SplashScreen::handleEvent(const sf::Event& event) {
	return true;
}
