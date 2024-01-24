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

// Buttons setup for making them global

SDL_Surface *settingButtonSurface = NULL;
SDL_Texture *settingButton = NULL;
SDL_Rect settingButtonRect;
SDL_Rect settingButtonRectSrc;

SDL_Surface *exitButtonSurface = NULL;
SDL_Texture *exitButton = NULL;
SDL_Rect exitButtonRect;
SDL_Rect exitButtonRectSrc;

SDL_Surface *startButtonSurface = NULL;
SDL_Texture *startButton = NULL;
SDL_Rect startButtonRect;
SDL_Rect startButtonRectSrc;
SDL_Surface *startTextSurface;
SDL_Texture *startText;
SDL_Rect startTextRectSrc;
SDL_Rect startTextRect;

SDL_Surface *leaderButtonSurface = NULL;
SDL_Texture *leaderButton = NULL;
SDL_Rect leaderButtonRect;
SDL_Rect leaderButtonRectSrc;
SDL_Surface *leaderTextSurface;
SDL_Texture *leaderText;
SDL_Rect leaderTextRectSrc;
SDL_Rect leaderTextRect;



// Setting default
int soundVolume = 0;
int musicVolume = 0;
theme th = th1;



#endif //BOUNCING_BALL_GAME_SETTINGS_H