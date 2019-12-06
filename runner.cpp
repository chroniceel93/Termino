#include "runner.h"

int main() {
    Game::Gameboard bob;
    Game::Gameboard_TEX bob_face(&bob);

    try {
        bob_face.load_texture("test.png");
    } catch (char const *f) {
        std::cout << f;
    }

//288
//88

    int x = 20;
    int y = 0;
    int direction = 0;
    for (; true;) {

        switch (direction) {
        case 0:
            if (x == 288 && y != 88) {
                direction = 2;
                y++;
                x--;
            } else if (y == 88 && x != 288) {
                direction = 1;
                y--;
                x++;
            } else if (y == 88 && x == 288) {
                direction = 3;
                y--;
                x--;
            } else {
                x++;
                y++;
            }
            break;
        case 1:
            if (x == 288 && y != 0) {
                direction = 3;
                x--;
                y--;
            } else if (y == 0 && x != 288) {
                direction = 0;
                x++;
                y++;
            } else if (y == 0 && x == 288) {
                direction = 2;
                y++;
                x--;
            } else {
                y--;
                x++;
            }
            break;
        case 2:
            if (x == 0 && y != 88) {
                direction = 0;
                x++;
                y++;
            } else if (y == 88 && x != 0) {
                direction = 3;
                x--;
                y--;
            } else if (x == 0 && y == 88) {
                direction = 1;
                x++;
                y--;
            } else {
                x--;
                y++;
            }
            break;
        case 3:
            if (x == 0 && y != 0) {
                direction = 2;
                x++;
                y--;
            } else if (y == 0 && x != 0) {
                direction = 1;
                x--;
                y++;
            } else if (x == 0 && y ) {
                direction = 0;
                x++;
                y++;
            } else {
                x--;
                y--;
            }
            break;
        default:
            // do nothing, things went weird
            break;
        }
        
        bob_face.draw_texture(x, y);
        bob.update_screen();
    }

    return 0;
}

// 1. before anything else, I want to get sprite rendering implemented.
// 1a. rgb, 256, and 4-color textures
// 1b. 4-color textures use pallets
