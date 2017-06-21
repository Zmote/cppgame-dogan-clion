#ifndef __TEST_VIEW__  
#define __TEST_VIEW__  

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class TestView {
public:
	TestView() {
		init();
	}
private:
	void init() {
		sf::ContextSettings settings{};
		settings.antialiasingLevel = 8;
		sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!",sf::Style::Default,settings);
		sf::CircleShape shape{100.f};
		sf::CircleShape shape2{50.f};
		shape2.setFillColor(sf::Color::Blue);
		shape.setFillColor(sf::Color::Green);
		bool mouseClicked{};

		if(sf::Shader::isAvailable()){

		}

		while (window.isOpen())
		{
			sf::Event event{};
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					window.close();
				}

				if (event.type == sf::Event::MouseButtonPressed) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					float startX{shape.getPosition().x};
					float startY{shape.getPosition().y};
					float endX{startX + (2*shape.getRadius())};
					float endY{startY + (2 * shape.getRadius())};
					if (mousePos.x >= startX && mousePos.x <= endX && mousePos.y >= startY && mousePos.y <= endY) {
						mouseClicked = !mouseClicked;
					}

				}

				if (event.type == sf::Event::MouseMoved && mouseClicked) {
					float radius = shape.getRadius();
					sf::Vector2i currentMousePosition = sf::Mouse::getPosition(window);
					shape.setPosition(currentMousePosition.x - radius,currentMousePosition.y - radius);
				}

			}

			window.clear();
			window.draw(shape2);
			window.draw(shape);
			window.display();
		}
	}
};

#endif 