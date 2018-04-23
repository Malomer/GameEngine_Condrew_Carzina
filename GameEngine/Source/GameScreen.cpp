
#include "GameScreen.h"
#include "Ball.h"
#include "Imports.h"
#include "GameObject.h"
#include "ShapeRenderer.h"
#include "TestRenderer.h"

void GameScreen::Start() {
	GameObject *ball = gameObjectManager.CreateObject("Ball");
	ball->AddComponent(StrongComponentPtr(new Ball()));

	GameObject *player1 = gameObjectManager.CreateObject("Player1");
	player1->AddComponent(StrongComponentPtr(new Player(1)));
	player1->transform.transformMatrix.translate(Vector3(10.f, 10.f, 0.f));

	sf::RectangleShape *shape = new sf::RectangleShape();
	shape->setFillColor(sf::Color::Blue);
	shape->setSize(sf::Vector2f(40.f, 40.f));

	player1->AddComponent(StrongComponentPtr(new TestRenderer(shape)));
	//player1->AddComponent(StrongComponentPtr(new ShapeRenderer(shape)));

	GameObject *player2 = gameObjectManager.CreateObject("Player2");
	player2->AddComponent(StrongComponentPtr(new Player(2)));
}

void GameScreen::End() {
	ClearDrawables();
	powerupManager->Shutdown();
}

bool GameScreen::update(INT32 time) {
	gameObjectManager.Update(time);
	return true;
}

void GameScreen::draw() {
	for (std::vector<DrawableRenderer*>::iterator it = drawables.begin(); it != drawables.end(); ++it) {
		(*it)->Draw();
	}

	for (std::vector<ShapeRenderer*>::iterator itt = drawables1.begin(); itt != drawables1.end(); ++itt) {
		(*itt)->Draw();
	}
}

bool GameScreen::handleEvent(const sf::Event& event) {
	return true;
}
