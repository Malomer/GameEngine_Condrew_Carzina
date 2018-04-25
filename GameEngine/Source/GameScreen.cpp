
#include "GameScreen.h"
#include "Ball.h"
#include "Imports.h"
#include "GameObject.h"
#include "ShapeRenderer.h"
#include "TestRenderer.h"
#include "PowerupManager.h"

void GameScreen::Start() {
	// Ball
	GameObject *ball = gameObjectManager.CreateObject("Ball");

	sf::CircleShape *circle = new sf::CircleShape();
	circle->setFillColor(sf::Color::White);
	circle->setRadius(10);

	sf::Vector2u screenSize = mainWindow->getSize();
	ball->transform.transformMatrix.translate(Vector3(screenSize.x / 2, screenSize.y / 2, 0.f));

	ball->AddComponent(StrongComponentPtr(new TestRenderer(circle)));
	ball->AddComponent(StrongComponentPtr(new Ball()));

	// Player 1
	GameObject *player1 = gameObjectManager.CreateObject("Player1");
	sf::RectangleShape *shape = new sf::RectangleShape();
	shape->setFillColor(sf::Color::Blue);
	shape->setSize(sf::Vector2f(20.f, 120.f));

	player1->AddComponent(StrongComponentPtr(new TestRenderer(shape)));
	player1->AddComponent(StrongComponentPtr(new Player(1, ball)));
	player1->transform.transformMatrix.translate(Vector3(30.f, 10.f, 0.f));
	player1->worldTransform.translate(Vector3(30.f, 10.f, 0.f));

	// Player 2
	GameObject *player2 = gameObjectManager.CreateObject("Player2");
	sf::RectangleShape *shape2 = new sf::RectangleShape();
	shape2->setFillColor(sf::Color::Red);
	shape2->setSize(sf::Vector2f(20.f, 120.f));

	player2->AddComponent(StrongComponentPtr(new TestRenderer(shape2)));
	player2->AddComponent(StrongComponentPtr(new Player(2, ball)));
	player2->transform.transformMatrix.translate(Vector3(970.f, 10.f, 0.f));
	player2->worldTransform.translate(Vector3(970.f, 10.f, 0.f));

	//player1->AddComponent(StrongComponentPtr(new ShapeRenderer(shape)));

	//GameObject *player2 = gameObjectManager.CreateObject("Player2");
	//player2->AddComponent(StrongComponentPtr(new Player(2)));

	sf::Font font;
	if (!font.loadFromFile("resources/sansation.ttf"))
		printf("Could not load font!\n");

	sf::Text pauseMessage;
	pauseMessage.setFont(font);
	pauseMessage.setCharacterSize(40);
	pauseMessage.setPosition(170.f, 150.f);
	pauseMessage.setFillColor(sf::Color::White);
	pauseMessage.setString("Welcome to SFML pong!\nPress space to start the game");


	// Powerup Manager
	GameObject *powerupManager = gameObjectManager.CreateObject("PowerupManager");
	powerupManager->AddComponent(StrongComponentPtr(new PowerupManager()));

	// Init Game Objects
	gameObjectManager.InitGameObjects();

	// Debug
	std::map<ComponentId, StrongComponentPtr>::iterator it;
	for (it = player1->m_components.begin(); it != player1->m_components.end(); it++) {
		printf("Comp = %s\n", it->second->VGetName());
	}
}

void GameScreen::End() {
	ClearDrawables();
	//powerupManager->Shutdown();
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
	// Window closed or escape key pressed: exit
	if ((event.type == sf::Event::Closed) ||
		((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
	{
		mainWindow->close();
	}

	return true;
}
