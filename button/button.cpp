#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.hpp"


Button::Button()
{}

Button::Button(std::string text, sf::Vector2f buttonSize, int characterSize, sf::Color bgNormal, sf::Color textNormal)
{
    this->text.setString(text);
    this->textNormal = textNormal;
    this->text.setColor(this->textNormal);
    this->text.setCharacterSize(characterSize);

    this->button.setSize(buttonSize);
    this->bgNormal = bgNormal;
    this->button.setFillColor(this->bgNormal);

}


void Button::setFont(const sf::Font& font)
{
    this->text.setFont(font);
}

void Button::setBGColor(const sf::Color& color)
{
    this->button.setFillColor(color);
}

void Button::setTextColor(const sf::Color& color)
{
    this->text.setColor(color);
}

void Button::setPosition(const sf::Vector2f& position)
{
    this->button.setPosition(position);

    float xPosition = (position.x + this->button.getGlobalBounds().width / 2) - (this->text.getGlobalBounds().width / 2);
    float yPosition = (position.y + this->button.getGlobalBounds().height / 2) - (this->text.getGlobalBounds().height / 2);
    text.setPosition({ xPosition, yPosition });
}

void Button::drawButton(sf::RenderWindow& window)
{
    window.draw(this->button);
    window.draw(this->text);

}
