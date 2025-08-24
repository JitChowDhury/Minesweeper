#include <SFML/Graphics.hpp>

class Game
{
private:
	 unsigned int WINDOW_WIDTH;
	 unsigned int WINDOW_HEIGHT;

	 const float boardWidth = 866.f;
	 const float boardHeight = 1080.f;
	 const float boardPosition = 530.f;

	sf::RenderWindow window;
	

	sf::Texture mainBgTexture;
	sf::Sprite mainBgSprite;

	sf::Texture boardTexture;
	sf::Sprite boardSprite;


public:
	Game();
	void HandleEvents();
	void Update();
	void Render();
	void Run();

};
