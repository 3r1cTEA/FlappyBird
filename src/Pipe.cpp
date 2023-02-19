#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

#include "Pipe.hpp"

Pipe::Pipe():m_gapPosition(600, 500), m_rectSourceSprite(0,0,60,450)
{
   
   bottom_pipe = load();
   top_pipe = load_top();
    
}

Pipe::Pipe(int start_x, int start_y):m_gapPosition(start_x, start_y), m_rectSourceSprite(0,0,60,450)
{
   
   bottom_pipe = load();
   top_pipe = load_top();
    
}

Pipe::~Pipe()
{

}

sf::Vector2f& Pipe::return_Pipepos()
{
    return m_gapPosition ;

}


sf::Texture Pipe::load()
{
	sf::Texture texture;

	if (!texture.loadFromFile("res/imgs/pipe.png", m_rectSourceSprite))
    {
        std::cout<<"Can't load bird sprite:"<<std::endl;
    }
  
    return texture;
}

sf::Texture Pipe::load_top()
{
    sf::Texture texture;

    if (!texture.loadFromFile("res/imgs/downpipe.png", m_rectSourceSprite))
    {
        std::cout<<"Can't load bird sprite:"<<std::endl;
    }
  
    return texture;
}

void Pipe::resetPipe(int start_x, int start_y){
    m_gapPosition.x = start_x;
    m_gapPosition.y = start_y;
}


void Pipe::draw(sf::RenderWindow& window, bool& gameOn)
{

    if(gameOn){m_gapPosition.x -= 1;}



    sf::Vector2f gapPosition_yo = m_gapPosition;
    gapPosition_yo.y -= 500;

	sf::Sprite pipebottom;
    sf::Sprite pipetop;


       
    pipebottom.setTextureRect(rectSourceSprite);
    pipetop.setTextureRect(rectSourceSprite);
 	

    pipebottom.setTexture(bottom_pipe);
    pipetop.setTexture(top_pipe);
    
    pipebottom.setPosition(m_gapPosition);
    pipetop.setPosition(gapPosition_yo);

    pipebottom.scale(sf::Vector2f(1,1));
    pipetop.scale(sf::Vector2f(1,1));



    window.draw(pipebottom);
    window.draw(pipetop);

    if (m_gapPosition.x <= -50)
        {
            reset(m_gapPosition);
        }
}

void Pipe::reset(sf::Vector2f& m_gapPosition)
{
    
    m_gapPosition.x = 700;

    m_gapPosition.y = rand() % 100 + 400;
}

