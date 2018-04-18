
#include "GameScreen.h"
#include "Ball.h"
#include "Imports.h"
#include "GameObject.h"

void GameScreen::Start() {
	GameObject *ball = gameObjectManager.CreateObject("Ball");
	ball->AddComponent(StrongComponentPtr(new Ball()));
}

void GameScreen::End() {

}

bool GameScreen::update(INT32 time) {
//	gameObjectManager.Update(time);
	return true;
}

void GameScreen::draw() {

}

bool GameScreen::handleEvent(const sf::Event& event) {
	return true;
}
