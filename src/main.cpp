#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#include "DrawTitle.hpp"
#include "Bird.hpp"
#include "Background.hpp"
#include "Pipe.hpp"
#include "checkScore.hpp"
#include "resetGame.hpp"



int main()
{
    sf::RenderWindow window(sf::VideoMode(650, 720), "Floppy Bard");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);


    //Initiate Classes

    Bird bird;

    Pipe pipe_one;

    Pipe pipe_two(800, 450);

    Pipe pipe_three(1200, 400);

 
    //game variables
    bool gameOn = true;
    bool gameStart = false;
    int score = 0;

    //Window Loop is on
    while (window.isOpen())
    {
        

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
            {
                gameStart = true;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && (!gameOn))
            {
                resetGame(bird, pipe_one, pipe_two, pipe_three, gameOn, score);
            }   

            


        }

         


        if (gameStart)
        {
            
            
            
            

            Background(window);
            
            
            bird.draw(window, gameOn); 
            

            pipe_one.draw(window, gameOn);
            pipe_two.draw(window, gameOn);
            pipe_three.draw(window, gameOn);

            checkScore(bird.return_Birdpos(), pipe_one.return_Pipepos(), gameOn, window, score);
            checkScore(bird.return_Birdpos(), pipe_two.return_Pipepos(), gameOn, window, score);
            checkScore(bird.return_Birdpos(), pipe_three.return_Pipepos(), gameOn, window, score);

        } else{

            Background(window);
            DrawTitle(window);

      
        }        

        window.display();
    } 


    return 0;
}