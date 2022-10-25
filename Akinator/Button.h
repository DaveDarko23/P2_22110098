#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Button {
public:
	Button(){}

	Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor) {
		text.setString(t);
		text.setFillColor(textColor);
		text.setCharacterSize(charSize);

		button.setSize(size);
		button.setFillColor(bgColor);
	}

	void setFont(sf::Font& font) {
		text.setFont(font);
	}

	void setBackColor(sf::Color color) {
		button.setFillColor(color);
	}
	
	void setTextColor(sf::Color color) {
		text.setFillColor(color);
	}

	void setText(string textito) {
		text.setString(textito);
	};

	void setPosition(sf::Vector2f pos) {
		button.setPosition(pos);

		float xPos = (pos.x + button.getGlobalBounds().width / 4) - (text.getGlobalBounds().width / 2);
		float yPos = (pos.y + button.getGlobalBounds().height / 2) - (text.getGlobalBounds().height / 2);

		text.setPosition({ xPos, yPos });
	}

	void drawTo(sf::RenderWindow &window) {
		window.draw(button);
		window.draw(text);
	}

	bool isMouserOver(sf::RenderWindow& window) {
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float btnPosX = button.getPosition().x;
		float btnPosY = button.getPosition().y;

		float btnXPosWidth = button.getPosition().x + button.getLocalBounds().width;
		float btnYPosHeight = button.getPosition().y + button.getLocalBounds().height;

		return (mouseX < btnXPosWidth&& mouseX >btnPosX && mouseY < btnYPosHeight&& mouseY > btnPosY);
	}

private:
	sf::RectangleShape button;
	sf::Text text;


};