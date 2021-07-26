#include<stdio.h>
#include<stdlib.h>
#include<SFML/Graphics.hpp>

struct data {
	int height;
	int posx;
}line[1000];

int randomh{ 0 };


int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Tutorial", sf::Style::Close |sf::Style::Resize | sf::Style::Fullscreen);
	for (int i{0}; i < 1000; i++) {
		randomh = 1 + rand() % (1080);
		line[i].height = randomh;
		line[i].posx = i * 2;
	}

	sf::RectangleShape rectangle(sf::Vector2f(10.8f, 178));
	rectangle.setFillColor(sf::Color(235, 149, 13));

	sf::Text instructions;
	instructions.setString("Reset Sorting: [R]\nExit Sorting: [ESCAPE]");
	instructions.setPosition(sf::Vector2f(50.0f, 50.0f));
	instructions.setFillColor(sf::Color::White);
	instructions.setCharacterSize(24);

	sf::Font font;
	font.loadFromFile("Fonts/Roboto-Regular.ttf");

	instructions.setFont(font);


	srand(time(NULL));

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();

			case sf::Event::Resized:
				printf("New heigh: %i, New width: %i \n", evnt.size.height, evnt.size.width);

			case sf::Event::KeyPressed:
				if (evnt.key.code == sf::Keyboard::R) {
					for (int i{ 0 }; i < 1000; i++) {
						randomh = 1 + rand() % (1080);
						line[i].height = randomh;
						line[i].posx = i * 2;
					}
				}
				else if (evnt.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}
		}
		for (int i{0}; i < 1000; i++) 
		{
			if(line[i].height > line[i + 1].height)
			{
				int t_swap{ line[i + 1].height };
				line[i + 1].height = line[i].height;
				line[i].height = t_swap;
			}
		}
		sf::Time slp = sf::milliseconds(25);
		sf::sleep(slp);
		window.clear(sf::Color::Black);


		for (int i{ 0 }; i < 1000; i++) 
		{
			rectangle.setFillColor(sf::Color(235, 149, 13));
			rectangle.setPosition(line[i].posx, 1080);
			rectangle.setSize(sf::Vector2f(1.5f, line[i].height));
			rectangle.setRotation(180);
			window.draw(rectangle);
		}
		window.draw(instructions);
		window.display();
	}

	return 0;
}
