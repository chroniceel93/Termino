#ifndef GAMEBOARD_TEX_H_
#define GAMEBOARD_TEX_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Gameboard.h"

namespace Game {

/**
 * class Gameboard_TEX
 * 
 * an addon to the gameboard class, meant to handle textures...
 * this class can be given to Gameboard and used to render a loaded
 * texture.
 **/
    class Gameboard_TEX {
    private:
        bool texture_init, texture_load;

        Game::Gameboard *game;

        SDL_Texture *texture;

        int tex_h;
        int tex_w;
    public:
    // basic constructor and destructors
    // flesh out with cpy and mov later
        Gameboard_TEX();

        Gameboard_TEX(Game::Gameboard *board);

        ~Gameboard_TEX();

        void load_texture(std::string path);

        void load_texture(std::string path, Game::Gameboard *board);

        void draw_texture(int x, int y);

        void draw_texture(int x, int y, int h, int w);
    };
}


#endif