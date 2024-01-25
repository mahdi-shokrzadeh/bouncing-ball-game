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


// Each ball score
#define BALL_SCORE 10



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
SDL_Surface *startHoverButtonSurface = NULL;
SDL_Texture *startHoverButton = NULL;
SDL_Rect startHoverButtonRect;
SDL_Rect startHoverButtonRectSrc;
SDL_Surface *startTextSurface;
SDL_Texture *startText;
SDL_Rect startTextRectSrc;
SDL_Rect startTextRect;

SDL_Surface *leaderButtonSurface = NULL;
SDL_Texture *leaderButton = NULL;
SDL_Rect leaderButtonRect;
SDL_Rect leaderButtonRectSrc;
SDL_Surface *leaderHoverButtonSurface = NULL;
SDL_Texture *leaderHoverButton = NULL;
SDL_Rect leaderHoverButtonRect;
SDL_Rect leaderHoverButtonRectSrc;
SDL_Surface *leaderTextSurface;
SDL_Texture *leaderText;
SDL_Rect leaderTextRectSrc;
SDL_Rect leaderTextRect;

SDL_Surface *backButtonSurface = NULL;
SDL_Texture *backButton = NULL;
SDL_Rect backButtonRect;
SDL_Rect backButtonRectSrc;
SDL_Surface *backHoverButtonSurface = NULL;
SDL_Texture *backHoverButton = NULL;
SDL_Rect backHoverButtonRect;
SDL_Rect backHoverButtonRectSrc;
SDL_Surface *backTextSurface;
SDL_Texture *backText;
SDL_Rect backTextRectSrc;
SDL_Rect backTextRect;

SDL_Surface *DoYouWantToQuitTextSurface;
SDL_Texture *DoYouWantToQuitText;
SDL_Rect DoYouWantToQuitTextRectSrc;
SDL_Rect DoYouWantToQuitTextRect;

SDL_Surface *iWantQuitButtonSurface = NULL;
SDL_Texture *iWantQuitButton = NULL;
SDL_Rect iWantQuitButtonRect;
SDL_Rect iWantQuitButtonRectSrc;
SDL_Surface *iWantQuitTextSurface;
SDL_Texture *iWantQuitText;
SDL_Rect iWantQuitTextRectSrc;
SDL_Rect iWantQuitTextRect;

SDL_Surface *normalModeButtonSurface = NULL;
SDL_Texture *normalModeButton = NULL;
SDL_Rect normalModeButtonRect;
SDL_Rect normalModeButtonRectSrc;
SDL_Surface *normalModeHoverButtonSurface = NULL;
SDL_Texture *normalModeHoverButton = NULL;
SDL_Rect normalModeHoverButtonRect;
SDL_Rect normalModeHoverButtonRectSrc;
SDL_Surface *normalModeTextSurface;
SDL_Texture *normalModeText;
SDL_Rect normalModeTextRectSrc;
SDL_Rect normalModeTextRect;

SDL_Surface *timedModeButtonSurface = NULL;
SDL_Texture *timedModeButton = NULL;
SDL_Rect timedModeButtonRect;
SDL_Rect timedModeButtonRectSrc;
SDL_Surface *timedModeHoverButtonSurface = NULL;
SDL_Texture *timedModeHoverButton = NULL;
SDL_Rect timedModeHoverButtonRect;
SDL_Rect timedModeHoverButtonRectSrc;
SDL_Surface *timedModeTextSurface;
SDL_Texture *timedModeText;
SDL_Rect timedModeTextRectSrc;
SDL_Rect timedModeTextRect;

SDL_Surface *randomModeButtonSurface = NULL;
SDL_Texture *randomModeButton = NULL;
SDL_Rect randomModeButtonRect;
SDL_Rect randomModeButtonRectSrc;
SDL_Surface *randomModeHoverButtonSurface = NULL;
SDL_Texture *randomModeHoverButton = NULL;
SDL_Rect randomModeHoverButtonRect;
SDL_Rect randomModeHoverButtonRectSrc;
SDL_Surface *randomModeTextSurface;
SDL_Texture *randomModeText;
SDL_Rect randomModeTextRectSrc;
SDL_Rect randomModeTextRect;

SDL_Surface *infiniteModeButtonSurface = NULL;
SDL_Texture *infiniteModeButton = NULL;
SDL_Rect infiniteModeButtonRect;
SDL_Rect infiniteModeButtonRectSrc;
SDL_Surface *infiniteModeHoverButtonSurface = NULL;
SDL_Texture *infiniteModeHoverButton = NULL;
SDL_Rect infiniteModeHoverButtonRect;
SDL_Rect infiniteModeHoverButtonRectSrc;
SDL_Surface *infiniteModeTextSurface;
SDL_Texture *infiniteModeText;
SDL_Rect infiniteModeTextRectSrc;
SDL_Rect infiniteModeTextRect;


// Setting default
int soundVolume = 0;
int musicVolume = 0;
theme th = th1;



#endif //BOUNCING_BALL_GAME_SETTINGS_H