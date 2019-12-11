#include "runner.h"

int main() {
    Game::Gameboard bob;
    Tetris::Termino L(&bob, Tetris::Termino::L);
    Tetris::Termino J(&bob, Tetris::Termino::J);
    Tetris::Termino Z(&bob, Tetris::Termino::Z);
    for (;true;) {
        L.draw_termino(6, 10);
        bob.update_screen();
        SDL_Delay(1000);
        L.termino_rotate_cw();
        L.draw_termino(6, 10);
        bob.update_screen();
        SDL_Delay(1000);
        L.termino_rotate_cw();
        L.draw_termino(6, 10);
        bob.update_screen();
        SDL_Delay(1000);
        L.termino_rotate_cw();
        L.draw_termino(6, 10);
        bob.update_screen();
        SDL_Delay(1000);
        
    }  

    return 0;
}



// 1. before anything else, I want to get sprite rendering implemented.
// 1a. rgb, 256, and 4-color textures
// 1b. 4-color textures use pallets
