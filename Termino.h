#ifndef TERMINO_H_
#define TERMINO_H_

#include "Gameboard.h"
#include "Gameboard_TEX.h"

namespace Tetris{
    class Termino {
                enum TERM_ID {
            L,
            J,
            T,
            I,
            Z,
            S
        };

        TERM_ID name;

        Game::Gameboard_TEX term_block;

        bool termino_shape[4][4];
        int termino_rot_size;

    public:

        // to be of any use, you MUST pass a gameboard object here
        Termino(Game::Gameboard *gameboard);

        void draw_termino(int x, int y);
        ~Termino() {}
    };
};
#endif