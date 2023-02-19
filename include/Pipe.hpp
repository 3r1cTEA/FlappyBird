#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Pipe
{
public:
	Pipe();
	Pipe(int start_x, int start_y);
	~Pipe();
	
	sf::Vector2f m_gapPosition;

	sf::Vector2f& return_Pipepos();

	
	void resetPipe(int start_x, int start_y);
	void draw(sf::RenderWindow& window, bool& gameOn);
	

private:
	sf::IntRect rectSourceSprite;
	
	sf::IntRect m_rectSourceSprite;

	sf::Texture load();
	sf::Texture load_top();

	sf::Texture bottom_pipe;
	
	sf::Texture top_pipe;

	void reset(sf::Vector2f& m_gapPosition);


};