#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

#include "DrawTitle.hpp"





void DrawTitle(sf::RenderWindow& window)
{   
    

    
    

    sf::Font open_sans;

    open_sans.loadFromFile("res/fonts/Flappy.ttf");

    sf::Text my_text;
    my_text.setFont(open_sans);

    my_text.setString("Flappy Bird");
    my_text.setPosition(80,300);
    my_text.setFillColor(sf::Color::Red);
    my_text.setCharacterSize(90);

    
        
    window.draw(my_text);
    
    sf::Text sub_text;
    sub_text.setFont(open_sans);

    sub_text.setString("Press J To Flap");
    sub_text.setPosition(120,400);

    
    sub_text.setFillColor(sf::Color::Blue);   

    
    sub_text.setCharacterSize(50);

    window.draw(sub_text);


}

