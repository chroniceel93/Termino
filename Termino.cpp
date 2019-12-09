#include "Termino.h"

Tetris::Termino::Termino(Game::Gameboard *gameboard) {
        name = L;
        term_block.set_board(gameboard);
        term_block.load_texture("Term_bloc.png");

        // init termino_shape to all false;
        for (auto x = 0; x < 4; x++) {
            for (auto y = 0; y < 4; y++) {
                termino_shape[x][y] = 0; //check this later
            }
        }

        switch (name) {
            case L:// basic implementation, all other shapes stubbed.
                termino_rot_size = 3;
                termino_shape[0][1] = true;
                termino_shape[1][1] = true;
                termino_shape[2][1] = true;
                termino_shape[2][2] = true;
                break;
            case J:
                break;
            case T:
                break;
            case I:
                break;
            case Z:
                break;
            case S:
                break;
            default:
                break;
        }
        // Randomize block rotation once rotation function is implemented.
    }

void Tetris::Termino::draw_termino(int x, int y) {
        auto x_offset = 0;
        auto y_offset = 0;

        if (x < 20 ) {
            x += 280;
        } else if (x > 800) {
            x = 0;
        } else {
            // input is sane, do nothing
        }

        if (y > 10) {
            y += 60;
        } else if (y > 600) {
            y = 0;
        } else {
            // input is sane, do nothing
        }

        if (termino_rot_size == 3) {
            y_offset = -24;
            for (auto h = 0; h < 3; h++) {
                x_offset = -24;
                for (auto w = 0; w < 3; w++) {
                    if (termino_shape[w][h]) {
                        term_block.draw_texture(x + x_offset, y + y_offset);
                    } else {

                    }
                    x_offset += 24;
                }
                y_offset += 24;
            }
        } else {
            term_block.draw_texture(x, y);
        }
    }
