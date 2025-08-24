#include "Game.h"
#include<iostream>

Game::Game() :
    WINDOW_WIDTH(800),
    WINDOW_HEIGHT(600),
    window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Minesweeper")
{
    window.setFramerateLimit(60);


    if (!mainBgTexture.loadFromFile("assets/textures/minesweeper_bg.png"))
    {
        std::cout << "Failed to load background texture\n";
    }

    mainBgSprite.setTexture(mainBgTexture);


    mainBgSprite.setScale(
        static_cast<float>(WINDOW_WIDTH) / mainBgTexture.getSize().x,
        static_cast<float>(WINDOW_HEIGHT) / mainBgTexture.getSize().y
    );


    if (!boardTexture.loadFromFile("assets/textures/board.png"))
    {
        std::cout << "Failed to load board texture\n";
    }

    boardSprite.setTexture(boardTexture);

    // Scale board proportionally to fit window height
    float scaleY = static_cast<float>(WINDOW_HEIGHT) / boardTexture.getSize().y;
    float scaleX = scaleY;
    boardSprite.setScale(scaleX, scaleY);

    // Position board in the center horizontally
    float boardWidth = boardTexture.getSize().x * scaleX;
    boardSprite.setPosition((WINDOW_WIDTH - boardWidth) / 2.f, 0.f);
}

void Game::HandleEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void Game::Update()
{
}

void Game::Render()
{
	window.clear();
	window.draw(mainBgSprite);
	window.draw(boardSprite);
	window.display();
}

void Game::Run()
{
	while (window.isOpen())
	{
		Update();
		HandleEvents();
		Render();

	}
}
