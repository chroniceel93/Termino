#include "Termino.h"

Tetris::Termino::Termino(Game::Gameboard *gameboard, TERM_ID enter) {
        name = enter;
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
                termino_rot_size = 3;
                termino_shape[0][1] = true;
                termino_shape[0][2] = true;
                termino_shape[1][1] = true;
                termino_shape[2][1] = true;
                break;
            case T:
                termino_rot_size = 3;
                termino_shape[0][0] = true;
                termino_shape[1][0] = true;
                termino_shape[2][0] = true;
                termino_shape[1][1] = true;
                break;
            case I:
                termino_rot_size = 4;
                termino_shape[0][0] = true;
                termino_shape[0][1] = true;
                termino_shape[0][2] = true;
                termino_shape[0][3] = true;
                break;
            case Z:
                termino_rot_size = 3;
                termino_shape[0][0] = true;
                termino_shape[1][0] = true;
                termino_shape[1][1] = true;
                termino_shape[1][2] = true;
                break;
            case S:
                break;
            case C:
                termino_rot_size = 2;
                termino_shape[0][0] = true;
                termino_shape[1][0] = true;
                termino_shape[0][1] = true;
                termino_shape[1][1] = true;
            default:
                break;
        }
        // Randomize block rotation once rotation function is implemented.
    }

void Tetris::Termino::draw_termino(int x, int y) {
        auto x_offset = 0;
        auto y_offset = 0;

        if (x < 10 ) {
            x *= 24;
            x += 280;
        } else if (x > 800) {
            x = 0;
        } else {
            // input is sane, do nothing
        }

        if (y < 20) {
            y *= 24;
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
                        term_block.draw_texture((x + x_offset)
                                                , ( y + y_offset));
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



/**
 * void Tetris::Termino::termino_rotate_cw()
 * 
 * for the size three version:
 * First, takes a full copy of the left and right sides of the termino,
 * and takes a copy of the middle of the top and bottom rows.
 * 
 * Second, reads the left and right copies into the top and bottom rows,
 * respectively, and reads the middle top and bottom values into the middle
 * right and left, respectively.
 **/
void Tetris::Termino::termino_rotate_cw() {
    /*
    bool rotate_left[3] = {false};
    bool rotate_right[3] = {false};
    bool rotate_top = false;
    bool rotate_bottom = false;

    // read in rotation data
    for (auto count = 0; count < 3; count++) {
        rotate_right[count] = termino_shape[2][count];
        rotate_left[count] = termino_shape[0][count];
    }
    rotate_top = termino_shape[1][0];
    rotate_bottom = termino_shape[1][2];
    for (auto count = 0; count < 3; count++) {
        termino_shape[count][2] = rotate_right[count];
        termino_shape[count][0] = rotate_left[count];
    }
    termino_shape[2][1] = rotate_top;
    termino_shape[0][1] = rotate_bottom;
    */
    bool temp[4][4];
    
    // copy data rotated by 90 degrees into temporary element
    // this is done by simply reading in the main element, 
    // left->right, top->bottom and writing that to the temp
    // element, top->bottom, right->left
// TODO: either modify these functions to handle larger terminoes, or make sure to
// create copes that will handle the larger terminoes. just add one to each magic
// number

// TODO: Explain the magic numbers. Or come up with class constants?
    int invert_counter = 2;

    for (auto y = 0; y < 3; y++) {
        for (auto x = 0; x < 3 ; x++ ) {
            temp[invert_counter][x] = termino_shape[x][y];
        }
        invert_counter--;
    }
    // complete copy of temporary element back into termino
    for (auto x = 0; x < 3; x++) {
        for (auto y = 0; y < 3 ; y++) {
            termino_shape[x][y] = temp[x][y];
        }
    }
}
