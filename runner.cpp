#include "runner.h"



int main() {
    Game::Gameboard bob;
    Tetris::Termino L(&bob);
    for (;true;) {
        L.draw_termino(4, 19);
        bob.update_screen();
    }  

    return 0;
}



// 1. before anything else, I want to get sprite rendering implemented.
// 1a. rgb, 256, and 4-color textures
// 1b. 4-color textures use pallets
