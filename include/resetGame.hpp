#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "DrawTitle.hpp"
#include "Bird.hpp"
#include "Background.hpp"
#include "Pipe.hpp"
#include "checkScore.hpp"



void resetGame(Bird& bird, Pipe& pipe, Pipe& pipe_two, Pipe& pipe_three, bool& gameOn, int& score);