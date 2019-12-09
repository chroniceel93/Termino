#include "runner.h"

int main() {
    Game::Gameboard bob;
    Tetris::Termino L(&bob, Tetris::Termino::L);
    Tetris::Termino J(&bob, Tetris::Termino::J);
    Tetris::Termino Z(&bob, Tetris::Termino::Z);
    for (;true;) {
        L.draw_termino(6, 10);
       // J.draw_termino(4, 2);
       // Z.draw_termino(6, 10);
        bob.update_screen();
        SDL_Delay(1000);
        L.draw_termino(4, 10);
        bob.update_screen();
        SDL_Delay(1000);
        L.draw_termino(2, 10);
        bob.update_screen();
        SDL_Delay(1000);
        L.draw_termino(6, 10);
        bob.update_screen();
        SDL_Delay(1000);
        L.draw_termino(6, 12);
        bob.update_screen();
        SDL_Delay(1000);
        
    }  

    return 0;
}



// 1. before anything else, I want to get sprite rendering implemented.
// 1a. rgb, 256, and 4-color textures
// 1b. 4-color textures use pallets
