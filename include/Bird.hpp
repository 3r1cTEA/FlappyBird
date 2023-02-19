#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Bird
{
public:
Bird();
~Bird();

//sf::Texture load();
void draw(sf::RenderWindow& window, bool& gameOn);
sf::Vector2f& return_Birdpos();

void resetBird();



private:
sf::Vector2f s_rectanglePosition;

sf::IntRect rectSourceSprite;
sf::Texture load();
sf::Texture m_texture;
};