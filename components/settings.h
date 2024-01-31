#ifndef BOUNCING_BALL_GAME_SETTINGS_H
#define BOUNCING_BALL_GAME_SETTINGS_H

// Window settings
#define DELAY 10
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 720


// Global variables related to game
#define SPEED_OF_THROWN_BALL 6

// how many lines of balls?
#define NUMBER_OF_ROWS 20

#define NUMBER_OF_BALLS_IN_EACH_COL 12

#define MAX_NUMBER_OF_ROWS 20

// Escape lines
#define ESCAPE_FOR_BALLS_ARRAY 6
#define FINAL_ROWS (ESCAPE_FOR_BALLS_ARRAY + NUMBER_OF_ROWS)


// Each ball score
#define BALL_SCORE 10
#define FALLING_BALL_SCORE 15



// targeter
#define TARGETER_SPEED 1.2

// least number of balls to be destroyed after collision
#define LEAST_BALLS_NUMBER 2


// SDL Window
SDL_Window *window;

// SDL Renderer to draw to
SDL_Renderer *renderer;


// main.cpp loop
SDL_bool main_loop = SDL_TRUE;


// patterns
#define DIMENTION_OF_LEVELS 20

// levels

// 2 stands for a ball with lock
// 3 stands for two color ball


//int level_1[20][12] = {
//        {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
//        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
//        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
//        {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
//        {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
//        {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
//        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
//        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
//        {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
//        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
//        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
//        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
//        {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
//
//};


int level_1[20][12] = {
        {1, 1, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 3, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
};


// locator
map<string, bool> Locator;


// Timer
#define TIMER  50


// SDL setup
TTF_Font *font = NULL;

Mix_Music *music = NULL;

SDL_Surface *bgSurface = NULL;
SDL_Texture *bg = NULL;
SDL_Rect bgRect;

//

// Setting default
int soundVolume = 0;
int musicVolume = 0;
theme th = th1;

// logo

SDL_Surface *logoSurface = NULL;
SDL_Texture *logo = NULL;
SDL_Rect logoRectSrc;
SDL_Rect logoRect;

// Buttons setup for making them global

SDL_Surface *mainMenuButtonSurface = NULL;
SDL_Texture *mainMenuButton = NULL;
SDL_Rect mainMenuButtonRect;
SDL_Rect mainMenuButtonRectSrc;
SDL_Surface *mainMenuHoverButtonSurface = NULL;
SDL_Texture *mainMenuHoverButton = NULL;
SDL_Rect mainMenuHoverButtonRect;
SDL_Rect mainMenuHoverButtonRectSrc;
SDL_Surface *mainMenuTextSurface;
SDL_Texture *mainMenuText;
SDL_Rect mainMenuTextRectSrc;
SDL_Rect mainMenuTextRect;

SDL_Surface *settingButtonSurface = NULL;
SDL_Texture *settingButton = NULL;
SDL_Rect settingButtonRect;
SDL_Rect settingButtonRectSrc;

SDL_Surface *exitButtonSurface = NULL;
SDL_Texture *exitButton = NULL;
SDL_Rect exitButtonRect;
SDL_Rect exitButtonRectSrc;

SDL_Rect settingBox = {50, 50, 500, 500};
SDL_Rect soundOutsideRect = {108, 60, 100, 48};
SDL_Rect soundInsideRect = {108, 60, soundVolume, 48};
SDL_Rect musicOutsideRect = {108, 120, 100, 48};
SDL_Rect musicInsideRect = {108, 120, musicVolume, 48};

SDL_Surface *musicOnButtonSurface = NULL;
SDL_Texture *musicOnButton = NULL;
SDL_Rect musicOnButtonRect;
SDL_Rect musicOnButtonRectSrc;

SDL_Surface *musicOffButtonSurface = NULL;
SDL_Texture *musicOffButton = NULL;
SDL_Rect musicOffButtonRect;
SDL_Rect musicOffButtonRectSrc;

SDL_Surface *volumeOnButtonSurface = NULL;
SDL_Texture *volumeOnButton = NULL;
SDL_Rect volumeOnButtonRect;
SDL_Rect volumeOnButtonRectSrc;

SDL_Surface *volumeOffButtonSurface = NULL;
SDL_Texture *volumeOffButton = NULL;
SDL_Rect volumeOffButtonRect;
SDL_Rect volumeOffButtonRectSrc;

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

SDL_Surface *signInButtonSurface = NULL;
SDL_Texture *signInButton = NULL;
SDL_Rect signInButtonRect;
SDL_Rect signInButtonRectSrc;
SDL_Surface *signInHoverButtonSurface = NULL;
SDL_Texture *signInHoverButton = NULL;
SDL_Rect signInHoverButtonRect;
SDL_Rect signInHoverButtonRectSrc;
SDL_Surface *signInTextSurface;
SDL_Texture *signInText;
SDL_Rect signInTextRectSrc;
SDL_Rect signInTextRect;

SDL_Surface *logInButtonSurface = NULL;
SDL_Texture *logInButton = NULL;
SDL_Rect logInButtonRect;
SDL_Rect logInButtonRectSrc;
SDL_Surface *logInHoverButtonSurface = NULL;
SDL_Texture *logInHoverButton = NULL;
SDL_Rect logInHoverButtonRect;
SDL_Rect logInHoverButtonRectSrc;
SDL_Surface *logInTextSurface;
SDL_Texture *logInText;
SDL_Rect logInTextRectSrc;
SDL_Rect logInTextRect;

SDL_Surface *logOutButtonSurface = NULL;
SDL_Texture *logOutButton = NULL;
SDL_Rect logOutButtonRect;
SDL_Rect logOutButtonRectSrc;
SDL_Surface *logOutTextSurface;
SDL_Texture *logOutText;
SDL_Rect logOutTextRectSrc;
SDL_Rect logOutTextRect;

SDL_Surface *userNameTextSurface;
SDL_Texture *userNameText;
SDL_Rect userNameTextRectSrc;
SDL_Rect userNameTextRect;

SDL_Surface *usernameInputBoxSurface = NULL;
SDL_Texture *usernameInputBox = NULL;
SDL_Rect usernameInputBoxRect = {50, 100, 200, 50};
string inputText = "Enter Your Name";


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

SDL_Surface *jungleThemeButtonSurface = NULL;
SDL_Texture *jungleThemeButton = NULL;
SDL_Rect jungleThemeButtonRect;
SDL_Rect jungleThemeButtonRectSrc;
SDL_Surface *jungleThemeHoverButtonSurface = NULL;
SDL_Texture *jungleThemeHoverButton = NULL;
SDL_Rect jungleThemeHoverButtonRect;
SDL_Rect jungleThemeHoverButtonRectSrc;
SDL_Surface *jungleThemeTextSurface;
SDL_Texture *jungleThemeText;
SDL_Rect jungleThemeTextRectSrc;
SDL_Rect jungleThemeTextRect;

SDL_Surface *spaceThemeButtonSurface = NULL;
SDL_Texture *spaceThemeButton = NULL;
SDL_Rect spaceThemeButtonRect;
SDL_Rect spaceThemeButtonRectSrc;
SDL_Surface *spaceThemeHoverButtonSurface = NULL;
SDL_Texture *spaceThemeHoverButton = NULL;
SDL_Rect spaceThemeHoverButtonRect;
SDL_Rect spaceThemeHoverButtonRectSrc;
SDL_Surface *spaceThemeTextSurface;
SDL_Texture *spaceThemeText;
SDL_Rect spaceThemeTextRectSrc;
SDL_Rect spaceThemeTextRect;

SDL_Surface *oceanThemeButtonSurface = NULL;
SDL_Texture *oceanThemeButton = NULL;
SDL_Rect oceanThemeButtonRect;
SDL_Rect oceanThemeButtonRectSrc;
SDL_Surface *oceanThemeHoverButtonSurface = NULL;
SDL_Texture *oceanThemeHoverButton = NULL;
SDL_Rect oceanThemeHoverButtonRect;
SDL_Rect oceanThemeHoverButtonRectSrc;
SDL_Surface *oceanThemeTextSurface;
SDL_Texture *oceanThemeText;
SDL_Rect oceanThemeTextRectSrc;
SDL_Rect oceanThemeTextRect;

SDL_Surface *DoYouWantToQuitTextSurface;
SDL_Texture *DoYouWantToQuitText;
SDL_Rect DoYouWantToQuitTextRectSrc;
SDL_Rect DoYouWantToQuitTextRect;
SDL_Rect questionBox = {50, 200, 500, 200};

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

SDL_Surface *level1ButtonSurface = NULL;
SDL_Texture *level1Button = NULL;
SDL_Rect level1ButtonRect;
SDL_Rect level1ButtonRectSrc;
SDL_Surface *level1HoverButtonSurface = NULL;
SDL_Texture *level1HoverButton = NULL;
SDL_Rect level1HoverButtonRect;
SDL_Rect level1HoverButtonRectSrc;
SDL_Surface *level1TextSurface;
SDL_Texture *level1Text;
SDL_Rect level1TextRectSrc;
SDL_Rect level1TextRect;

SDL_Surface *level2ButtonSurface = NULL;
SDL_Texture *level2Button = NULL;
SDL_Rect level2ButtonRect;
SDL_Rect level2ButtonRectSrc;
SDL_Surface *level2HoverButtonSurface = NULL;
SDL_Texture *level2HoverButton = NULL;
SDL_Rect level2HoverButtonRect;
SDL_Rect level2HoverButtonRectSrc;
SDL_Surface *level2TextSurface;
SDL_Texture *level2Text;
SDL_Rect level2TextRectSrc;
SDL_Rect level2TextRect;

SDL_Surface *level3ButtonSurface = NULL;
SDL_Texture *level3Button = NULL;
SDL_Rect level3ButtonRect;
SDL_Rect level3ButtonRectSrc;
SDL_Surface *level3HoverButtonSurface = NULL;
SDL_Texture *level3HoverButton = NULL;
SDL_Rect level3HoverButtonRect;
SDL_Rect level3HoverButtonRectSrc;
SDL_Surface *level3TextSurface;
SDL_Texture *level3Text;
SDL_Rect level3TextRectSrc;
SDL_Rect level3TextRect;

SDL_Surface *level4ButtonSurface = NULL;
SDL_Texture *level4Button = NULL;
SDL_Rect level4ButtonRect;
SDL_Rect level4ButtonRectSrc;
SDL_Surface *level4HoverButtonSurface = NULL;
SDL_Texture *level4HoverButton = NULL;
SDL_Rect level4HoverButtonRect;
SDL_Rect level4HoverButtonRectSrc;
SDL_Surface *level4TextSurface;
SDL_Texture *level4Text;
SDL_Rect level4TextRectSrc;
SDL_Rect level4TextRect;

SDL_Surface *level5ButtonSurface = NULL;
SDL_Texture *level5Button = NULL;
SDL_Rect level5ButtonRect;
SDL_Rect level5ButtonRectSrc;
SDL_Surface *level5HoverButtonSurface = NULL;
SDL_Texture *level5HoverButton = NULL;
SDL_Rect level5HoverButtonRect;
SDL_Rect level5HoverButtonRectSrc;
SDL_Surface *level5TextSurface;
SDL_Texture *level5Text;
SDL_Rect level5TextRectSrc;
SDL_Rect level5TextRect;

// balls variables

SDL_Surface *redNormalBallSurface = NULL;
SDL_Texture *redNormalBall = NULL;
SDL_Surface *blueNormalBallSurface = NULL;
SDL_Texture *blueNormalBall = NULL;
SDL_Surface *cyanNormalBallSurface = NULL;
SDL_Texture *cyanNormalBall = NULL;
SDL_Surface *greenNormalBallSurface = NULL;
SDL_Texture *greenNormalBall = NULL;
SDL_Surface *purpleNormalBallSurface = NULL;
SDL_Texture *purpleNormalBall = NULL;
SDL_Surface *yellowNormalBallSurface = NULL;
SDL_Texture *yellowNormalBall = NULL;
SDL_Surface *silverNormalBallSurface = NULL;
SDL_Texture *silverNormalBall = NULL;

// two colors variables

SDL_Surface *blueYellowBallSurface = NULL;
SDL_Texture *blueYellowBall = NULL;
SDL_Surface *redBlueBallSurface = NULL;
SDL_Texture *redBlueBall = NULL;
SDL_Surface *yellowRedBallSurface = NULL;
SDL_Texture *yellowRedBall = NULL;

// locked colors variables

SDL_Surface *redLockedBallSurface = NULL;
SDL_Texture *redLockedBall = NULL;
SDL_Surface *blueLockedBallSurface = NULL;
SDL_Texture *blueLockedBall = NULL;
SDL_Surface *cyanLockedBallSurface = NULL;
SDL_Texture *cyanLockedBall = NULL;
SDL_Surface *greenLockedBallSurface = NULL;
SDL_Texture *greenLockedBall = NULL;
SDL_Surface *purpleLockedBallSurface = NULL;
SDL_Texture *purpleLockedBall = NULL;
SDL_Surface *yellowLockedBallSurface = NULL;
SDL_Texture *yellowLockedBall = NULL;
SDL_Surface *silverLockedBallSurface = NULL;
SDL_Texture *silverLockedBall = NULL;

// multi color ball variables

// game SFX variables

Mix_Chunk *winningSound = NULL;
Mix_Chunk *clickSound = NULL;
Mix_Chunk *losingSound = NULL;


#endif //BOUNCING_BALL_GAME_SETTINGS_H