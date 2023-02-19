#include "resetGame.hpp"

void resetGame(Bird& bird, Pipe& pipe, Pipe& pipe_two, Pipe& pipe_three, bool& gameOn, int& score){

    gameOn = true;
    bird.resetBird();
    pipe.resetPipe(800,500);
    pipe_two.resetPipe(1000, 490);
    pipe_three.resetPipe(1200,450);
    score = 0;

}