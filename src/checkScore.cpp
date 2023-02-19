#include "checkScore.hpp"

void checkScore(sf::Vector2f& birdPos, sf::Vector2f& pipePos, bool& dude, sf::RenderWindow& window, int& score)
{
	sf::Font open_sans;

    open_sans.loadFromFile("res/fonts/Flappy.ttf");
    sf::Text sub_text;
    sub_text.setFont(open_sans);
    
    std::string s = std::to_string(score);
    std::string note = "Your score is: ";
    sub_text.setString(note + s);
    sub_text.setPosition(10,50);

    
    sub_text.setFillColor(sf::Color::White);   

    
    sub_text.setCharacterSize(25);

    window.draw(sub_text);

    if (birdPos.y > 675 || birdPos.y < 10)
    {
        dude = false;

       
    }


	if ((birdPos.x + 45)>pipePos.x && (birdPos.x- 45) < pipePos.x)
	{
		
		if (birdPos.y < (pipePos.y-175))
		{
			
			dude = false;
			
		}
		if (birdPos.y > pipePos.y )
		{
			//std::cout<<"You lose low"<<std::endl;
			dude = false;
		}
		if (birdPos.y < (pipePos.y-175))
		{
			//std::cout<<"You lose high"<<std::endl;
			dude = false;

			
		}
		if(birdPos.y > (pipePos.y-25) )
		{
			//std::cout<<"You lose low"<<std::endl;
			dude = false;

		}

	}else if((birdPos.x- 50) == pipePos.x){
		
		score++;
    
   
	}
	if(!dude){
	sub_text.setString("You Lose!");
    sub_text.setPosition(100,300);

    
    sub_text.setFillColor(sf::Color::Red);   

    
    sub_text.setCharacterSize(100);

    window.draw(sub_text);

    sf::Text reset_text;
    reset_text.setFont(open_sans);
   	reset_text.setString("Press Enter to Play Again");
    reset_text.setPosition(25,500);

    
    reset_text.setFillColor(sf::Color::Black);   

    
    reset_text.setCharacterSize(45);

    window.draw(reset_text);

    window.draw(sub_text);


	}
	
}