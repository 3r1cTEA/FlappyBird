#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

#include "Bird.hpp"

Bird::Bird():s_rectanglePosition(250, 350), rectSourceSprite(0,0,50,75)
{
	
}

Bird::~Bird()
{

}

sf::Vector2f& Bird::return_Birdpos()
{
    return s_rectanglePosition ;

}


void Bird::resetBird()
{
    s_rectanglePosition.x = 250;
    s_rectanglePosition.y = 350;
}

sf::Texture Bird::load()
{
    sf::Texture texture;


    if (!texture.loadFromFile("res/imgs/bird_frame_1.png", rectSourceSprite))
    {
        std::cout<<"Can't load bird sprite:"<<std::endl;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        if (!texture.loadFromFile("res/imgs/bird_frame_4.png", rectSourceSprite))
        {
            std::cout<<"Can't load bird sprite:"<<std::endl;
        }

    return texture;
}

void Bird::draw(sf::RenderWindow& window,bool& gameOn)
{
 
    m_texture = load();

    if (gameOn)
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        {
            s_rectanglePosition.y -= 10;
        }
        else
        {
            s_rectanglePosition.y += 3;
        }   
    }


    

	sf::Sprite enemySprite;

       
    enemySprite.setTextureRect(rectSourceSprite);

 	

    enemySprite.setTexture(m_texture);
    enemySprite.setPosition(s_rectanglePosition);

    enemySprite.scale(sf::Vector2f(1,1));

    window.draw(enemySprite);

}