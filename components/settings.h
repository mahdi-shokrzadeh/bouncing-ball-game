#ifndef BOUNCING_BALL_GAME_SETTINGS_H
#define BOUNCING_BALL_GAME_SETTINGS_H

// Window settings
#define DELAY 10
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 720


// Global variables related to game
#define SPEED_OF_THROWN_BALL 6

// how many lines of balls?
#define NUMBER_OF_ROWS 4

#define NUMBER_OF_BALLS_IN_EACH_COL 12

#define MAX_NUMBER_OF_ROWS 20

// Escape lines
#define ESCAPE_FOR_BALLS_ARRAY 6
#define FINAL_ROWS (ESCAPE_FOR_BALLS_ARRAY + NUMBER_OF_ROWS)


// targeter
#define TARGETER_SPEED 0.9

// least number of balls to be destroyed after collision
#define LEAST_BALLS_NUMBER 2


// SDL Window
SDL_Window *window;

// SDL Renderer to draw to
SDL_Renderer *renderer;


// main.cpp loop
SDL_bool main_loop = SDL_TRUE;


// SDL setup
TTF_Font *font = NULL;

Mix_Music *music = NULL;

SDL_Surface *bgSurface = NULL;

SDL_Texture *bg = NULL;

SDL_Rect bgRect;


// Setting default
int soundVolume = 0;
int musicVolume = 0;
theme th = th1;



#endif //BOUNCING_BALL_GAME_SETTINGS_H