#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

// TODO: Copy and move constructors for Gameboard class.

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

// TODO: Breaking gameboard class while porting
// SDL Handling from main into gameboard class.
// Gameboard class is being upgraded from a partial
// SDL interface class, to a full SDL interface class.



namespace Game {
// translates SDL keycodes into something my code understands...
// will keep, likely makes it more portable... if I want to gut sdl code...
// input and most logic in other games will still be usable.
    enum KeyPressed {
        k_wait,
        k_up,
        k_right,
        k_down,
        k_left,
        k_space
    };

/**
 * class Gameboard
 *
 * Used to draw a 10x10 pixel of a given color at a given position (trans-
 * lated into a 80x56 co-ordinate grid)
 *
 * We are assuming that the screen size is 800x600, will work on decoupling
 * resolution later
 *
 * The 1st vertical line is reserved for scoreboard functionality,
 * will be implemented later
 */
    class Gameboard {
    private:
        // these variables will be used once I implement logic to determine
        // pixel size given arbitrary screen size.

        int score;

        const int screen_width = 800;
        const int screen_height = 600;

        bool SDL_Status; // keep track of sdl status. If false, game logic
        // should abort immediately

        SDL_Window *window; // SDL window object
        SDL_Renderer *renderer; // SDL renderer object (this draws to things)
        SDL_Color background, text;  // background color
        SDL_Event input; // input queue

        TTF_Font *font; // font object

        KeyPressed mem; // stores last valid input

        friend class Gameboard_TEX;

        void draw_texture ( int xpos
            , int ypos
            , SDL_Texture *input);


    public:

        // Constructor
        Gameboard() ;

/**
 * bool status();
 *
 * Returns SDL_Status, used to determine whether SDL initialized correctly
 * from outside of the class
 *
 * return bool
 **/
        bool status();

/**
 * void blank_screen()
 *
 * re-draws entire texture with background color. This should be called if
 * restarting game logic
 * 
 * depereciated: Switching render pipeline to redraw entere screen each frame
 * no shared texture.
 **/
//        void blank_screen();

/**
 * void draw_block()
 *
 * Takes a co-ordinate pair and a color, and draws a block of that color,
 * at that co-ordinate.
 *
 * Assumes that the co-ordinates conform to an 80x60 grid.
 **/
        void draw_block( int xpos
            , int ypos
            , unsigned char r
            , unsigned char g
            , unsigned char b);


/**
 * void draw_text()
 *
 * Takes a co-ordinate pair and a string, renders the string as text to a surf-
 * ace, copies that to a texture, and draws to the render texture at the given
 * co-ordinates.
 *
 * The co-ordinates DO NOT conform to the 80x60 grid, so make sure to give the
 * unmodified coordinates.
 **/
        void draw_text ( int xpos
            , int ypos
            , std::string input);


/**
 * void input_reset()
 *
 * Simple utility function that resets mem to default value.
 **/
        void input_reset();

/**
 * void set_bg_color()
 *
 * Simple utility function that updates the background color.
 **/
        void set_bg_color(unsigned char r, unsigned char g, unsigned char b) ;

/**
 * void set_text_color()
 *
 * Simple utility function that updates the text color.
 **/
        void set_text_color(unsigned char r, unsigned char g,
                            unsigned char b);

/**
 * void update_screen()
 *
 * Presensts screen surface.
 **/
        void update_screen();

/**
 * KeyPressed update_input();
 *
 * Handles the input queue from sdl, saves the last given input into mem,
 * and returns that.
 *
 * If, instead, SDL_QUIT is set, the set the sdl state accordingly, and logic
 * should exit.
 *
 * return KeyPressed
 **/
        KeyPressed update_input();

        ~Gameboard() ;
    };
};

#endif
