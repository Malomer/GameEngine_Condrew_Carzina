#include <SFML/Graphics.hpp>

#include "CondrewCarzina.h" 

int main(int argc, char* argv[]) { 
	CondrewCarzina::Initialize();
	CondrewCarzina::Start();
	return 0; 
} 

void CondrewCarzina::Start(void) {
	if (gameState != Uninitialized)
		return; 
	mainWindow.create(sf::VideoMode(1024, 768, 32), "CondrewCarzina Engine"); 
	gameState = CondrewCarzina::Playing;
	while (!IsExiting()) { 
		GameLoop(); 
	}
	mainWindow.close(); 
}

// This method is only used to test if SFML loads properly.
int mainTest()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
