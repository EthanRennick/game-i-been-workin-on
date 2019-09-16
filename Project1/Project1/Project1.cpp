

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h> 
#include <time.h> 

void doStuff();


int main()
{

	//doStuff();
	sf::RenderWindow window(sf::VideoMode(800, 600), "Phil");

	sf::RectangleShape block;
	block.setSize(sf::Vector2f(10, 10));
	block.setFillColor(sf::Color::Blue);
	block.setPosition(50, 50);




	srand(time(NULL));
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);


	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;

	clock.restart();
	int keypressPause = 0;
	int movePause = 0;
	while (window.isOpen())
	{

		// check if the close window button is clicked on.
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//add to the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.

		if (timeSinceLastUpdate > timePerFrame)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				block.move(1, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				block.move(-1, 0);
			}
		}


		window.clear(sf::Color::Yellow);
		window.draw(block);
		window.display();

	//	timeSinceLastUpdate = sf::Time::Zero;
	}
	return 0;

}

void doStuff()
{
	std::cout << "y'all ready for this? \n";
	std::system("pause");	
}
