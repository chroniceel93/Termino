#include "Gameboard_TEX.h"

Game::Gameboard_TEX::Gameboard_TEX() {
    int tex_w = 0;
    int tex_h = 0;
    texture = nullptr;
    game = nullptr;
    texture_init = false;
    texture_load = false;

    int img_Flags = IMG_INIT_PNG;
    // figure this black magic out!
    if ( !( IMG_Init(img_Flags) & img_Flags)) {
        throw IMG_GetError();
        texture_init = false;
    } else {
        texture_init = true;
    }
}

Game::Gameboard_TEX::Gameboard_TEX(Game::Gameboard *board) {
    int tex_w = 0;
    int tex_h = 0;
    texture = nullptr;
    game = board;
    texture_init = false;
    texture_load = false;

    int img_Flags = IMG_INIT_PNG;
    if ( !( IMG_Init(img_Flags) & img_Flags)) {
        throw IMG_GetError();
        texture_init = false;
    } else {
        texture_init = true;
    }
}

Game::Gameboard_TEX::~Gameboard_TEX() {}

void Game::Gameboard_TEX::draw_texture(int x, int y) {

    SDL_Rect temp;

    temp.x = x;
    temp.y = y;
    
    // WHY
    // Also, sets temp.x and temp.y to reflect given texture.
    SDL_QueryTexture(texture, NULL, NULL, &temp.w, &temp.h);
    SDL_RenderCopy(game->renderer, texture, NULL, &temp);
}


void Game::Gameboard_TEX::load_texture(std::string path) {
    SDL_Surface * temp_surface = IMG_Load(path.c_str());
    if (temp_surface == nullptr) {
        throw IMG_GetError();
    } else {
        texture = SDL_CreateTextureFromSurface( game->renderer
                                                , temp_surface);
        if (texture == nullptr) {
            throw IMG_GetError();
        }
        SDL_FreeSurface(temp_surface);
    }
}

void Game::Gameboard_TEX::load_texture(std::string path
                                    , Game::Gameboard *board) {
    SDL_Surface * temp_surface = IMG_Load(path.c_str());
    if (temp_surface == nullptr) {
        throw IMG_GetError();
    } else {
        texture = SDL_CreateTextureFromSurface( board->renderer
                                                , temp_surface);
        if (texture == nullptr) {
            throw SDL_GetError();
        }
        SDL_FreeSurface(temp_surface);
    }
    return;
}

void Game::Gameboard_TEX::set_board(Game::Gameboard *board) {
    game = board;
}