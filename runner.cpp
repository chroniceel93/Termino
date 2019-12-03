#include "runner.h"

int main() {
    Game::Gameboard bob;
    Game::Gameboard_TEX bob_face(&bob);


    bob_face.load_texture("test.png");

    for (auto i = 0; 1!= 0;) {
    }

    return 0;
}

// 1. before anything else, I want to get sprite rendering implemented.
// 1a. rgb, 256, and 4-color textures
// 1b. 4-color textures use pallets
