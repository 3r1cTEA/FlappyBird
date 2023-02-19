#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

#include "Background.hpp"

void Background(sf::RenderWindow& window)
{   
    
//Background
    sf::Texture background;

    if (!background.loadFromFile("res/imgs/background-night.png", sf::IntRect(0,0,720,720)))
    {
        std::cout<<"can't load background"<<std::endl;
    }

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);

    backgroundSprite.setPosition(sf::Vector2f(0,-150));

    backgroundSprite.scale(sf::Vector2f(3,2));

    window.draw(backgroundSprite);
    
    

    


}