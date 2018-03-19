#include "SplashScreen.h" 
#include "CondrewCarzina.h"

void SplashScreen::Show(sf::RenderWindow & renderWindow) { 
	sf::Image image; 
	if(!image.loadFromFile("images/SplashScreen.png")) { 
		return; 
	} 
	
	/*
	sf::Sprite sprite(image);
	renderWindow.draw(sprite); 
	renderWindow.display();

	sf::Event event;
	while(gameState != CondrewCarzina::GameState::Playing) {
		while(renderWindow.GetEvent(event)) { 
			if(event.type == sf::Event::EventType::KeyPressed || 
				event.type == sf::Event::EventType::MouseButtonPressed || 
				event.type == sf::Event::EventType::Closed) {
				return; 
			} 
		} 
	} 
	*/
}
