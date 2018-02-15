#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class CondrewCarzina {

public:
	static void Start();
	static void Initialize(); 

private:
	static bool IsExiting();
	static void GameLoop();
	
	enum GameState { 
		Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting
	};
	
	static GameState gameState;
	static sf::RenderWindow mainWindow; 
}; 