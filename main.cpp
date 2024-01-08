
/*
 * In the name of GOD
 * Bouncing Ball Game
 * Mohammad Mahdi Shokrzadeh and Sina Hashemi
 * Dr.Arasteh and Dr.Vosooqi
 * DEC 2023 - JAN 2024
 */

#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
//include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL2_gfx.h>

using namespace std;

// Headers
#include "common/colors.h"
#include "common/themes.h"


//Global variables
#define DELAY 10
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 720

// Global variables related to game
#define SPEED_OF_THROWN_BALL 10

// structures
typedef struct DOUBLE_POINT {
    double x;
    double y;
} DOUBLE_POINT;


typedef struct BALL {
    SDL_Color color;
    DOUBLE_POINT center;
} BALL;


// variables related to balls
const int radius_of_balls = 15;
const int width_of_ball_box = 35;
double vertical_speed = 0.25;
vector<BALL> balls;


// variables related to targeter
DOUBLE_POINT center_of_shooting_ball = {
        .x = 300,
        .y = 620,
};
DOUBLE_POINT center_of_reserved_ball = {
        .x = 220,
        .y = 670,
};

BALL thrown_ball;
bool ball_is_being_thrown = false;
double dxOfThrownBall;
double dyOfThrownBall;


double degree = 180.0;
int targeter_balls_radius = 2;
double targeter_balls_dist = 9.0;


// SDL Window
SDL_Window *window;

// SDL Renderer to draw to
SDL_Renderer *renderer;

// SDL font
TTF_Font *font = NULL;

// theme
theme th = th1;

// where are we?
bool main_menu = true, start_menu = false, leaderboard = false, setting = false, quit_menu = false, game = false;


// funcs

// Game
void setRandomColor(SDL_Color &color);

void initializeBalls();

void initializeShootingBalls(BALL &shooter_ball, BALL &reserved_ball);

void swapShootingBalls(BALL &shooter_ball, BALL &reserved_ball);

void drawShootingBalls(BALL shooter_ball, BALL reserved_ball);

void drawTargeter();

void handleTargeterEvent(int type);

bool checkCollTargeterAndBalls(DOUBLE_POINT targeter_point);

double calculateDistance(DOUBLE_POINT a, DOUBLE_POINT b);

void handleShootBall(BALL &shooting_ball, BALL &reserved_ball);

void handleBallShooting();


// Menus

void Main_Menu(bool MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, bool &game, bool &main_menu);

void Game(BALL shooter_ball, BALL reserved_ball);

void loop() {

    SDL_bool loop = SDL_TRUE;
    SDL_Event event;


    initializeBalls();
    BALL shooter_ball;
    BALL reserved_ball;
    initializeShootingBalls(shooter_ball, reserved_ball);

    bool MouseClicked = false;
    int x_MouseClicked = 0;
    int y_MouseClicked = 0;
    int x_MouseWhere = 0;
    int y_MouseWhere = 0;


    while (loop) {

        // Allow quiting with escape key by polling for pending events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                loop = SDL_FALSE;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {

                    case SDLK_ESCAPE :
                        loop = SDL_FALSE;
                        break;

                    case SDLK_SPACE:
                        swapShootingBalls(shooter_ball, reserved_ball);
                        drawShootingBalls(shooter_ball, reserved_ball);
                        break;

                    case SDLK_RIGHT :
                        handleTargeterEvent(0);
                        break;

                    case SDLK_s :
                        handleShootBall(shooter_ball, reserved_ball);
                        break;

                    case SDLK_LEFT :
                        handleTargeterEvent(1);
                        break;

                    default:
                        loop = SDL_TRUE;
                }
            } else if (event.type == SDL_KEYUP) {
                switch (event.key.keysym.sym) {
                    default:
                        loop = SDL_TRUE;
                }
            } else if(event.type == SDL_MOUSEBUTTONDOWN) {
                MouseClicked = true;
                x_MouseClicked = event.button.x;
                y_MouseClicked = event.button.y;
            } else if(event.type == SDL_MOUSEBUTTONUP) {
                MouseClicked = false;
            }
        }

        // get mouse free location
        SDL_GetMouseState(&x_MouseWhere, &y_MouseWhere);

        // Blank out the renderer with all black
        SDL_SetRenderDrawColor(renderer, BLACK.r, BLACK.g, BLACK.b, 255);
        SDL_RenderClear(renderer);

        if (main_menu)
            Main_Menu(MouseClicked, x_MouseClicked, y_MouseClicked, x_MouseWhere, y_MouseWhere, game, main_menu);
        else if (game)
            Game(shooter_ball, reserved_ball);

        // Present to renderer
        //SDL_RenderPresent(renderer);
        SDL_Delay(DELAY);
    }
}


int main(int argv, char **args) {

    srand(time(NULL));


    // SDL Inits
    Uint32 SDL_flags = SDL_INIT_EVERYTHING;// SDL_INIT_VIDEO | SDL_INIT_TIMER
    // Uint32 WND_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;
    SDL_Init(SDL_flags);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, WND_flags, &window, &renderer);
    SDL_RaiseWindow(window);
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    TTF_Init();
    font = TTF_OpenFont("assets/font.ttc", 50);


    loop();

    //clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    window = NULL;
    renderer = NULL;
    font = NULL;

    TTF_Quit();
    SDL_Quit();
    return 0;
}

void Main_Menu(bool MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, bool &game, bool &main_menu) {

    // Draw buttons

    SDL_SetRenderDrawColor(renderer, th.MainColor.r, th.MainColor.g, th.MainColor.b, 255);
    SDL_RenderClear(renderer);


    // start button
    SDL_Rect startBtn = {100, 300, 400, 80};
    SDL_Surface *startSurf = TTF_RenderText_Solid(font, "Start", WHITE);
    SDL_Texture *startText = SDL_CreateTextureFromSurface(renderer, startSurf);
    SDL_Rect textStart = {250, 300, startSurf->w, startSurf->h};

    SDL_SetRenderDrawColor(renderer, th.SecColor.r, th.SecColor.g, th.SecColor.b, 255);
    SDL_RenderFillRect(renderer, &startBtn);
    SDL_RenderCopy(renderer, startText, NULL, &textStart);

    // Leaderboard button
    SDL_Rect leaderBtn = {100, 400, 400, 80};
    SDL_Surface *leaderSurf = TTF_RenderText_Solid(font, "Leaderboard", WHITE);
    SDL_Texture *leaderText = SDL_CreateTextureFromSurface(renderer, leaderSurf);
    SDL_Rect textLeader = {170, 400, leaderSurf->w, leaderSurf->h};

    SDL_SetRenderDrawColor(renderer, th.SecColor.r, th.SecColor.g, th.SecColor.b, 255);
    SDL_RenderFillRect(renderer, &leaderBtn);
    SDL_RenderCopy(renderer, leaderText, NULL, &textLeader);

    // setting button
    SDL_Rect settingBtn = {100, 500, 400, 80};
    SDL_SetRenderDrawColor(renderer, th.SecColor.r, th.SecColor.g, th.SecColor.b, 255);
    SDL_RenderFillRect(renderer, &settingBtn);

    // quit button
    SDL_Rect quitBtn = {100, 600, 400, 80};
    SDL_SetRenderDrawColor(renderer, th.SecColor.r, th.SecColor.g, th.SecColor.b, 255);
    SDL_RenderFillRect(renderer, &quitBtn);

    // mouse actions
    /*if(x_MouseWhere >= startBtn.x && x_MouseWhere <= startBtn.x + startBtn.w && y_MouseWhere >= startBtn.y && y_MouseWhere <= startBtn.y + startBtn.h){
        void;
    }*/
    if(MouseClicked && (x_MouseClicked >= startBtn.x && x_MouseClicked <= startBtn.x + startBtn.w) && (y_MouseClicked >= startBtn.y && y_MouseClicked <= startBtn.y + startBtn.h)){
        game = !game;
        main_menu = !main_menu;
    }

    // destroyer
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startText);
    SDL_FreeSurface(startSurf);
    SDL_DestroyTexture(leaderText);
    SDL_FreeSurface(leaderSurf);
}

void Game(BALL shooter_ball, BALL reserved_ball) {

    // targeter

    drawTargeter();

    // drawing balls

    for (int i = 0; i < balls.size(); i++) {
        BALL &ball = balls[i];
        ball.center.y += vertical_speed;
        aacircleRGBA(renderer, Sint16(ball.center.x), Sint16(ball.center.y), 15,
                     ball.color.r, ball.color.g, ball.color.b, 255);
    }

    // handle ball shooting

    if (ball_is_being_thrown) {
        handleBallShooting();
    }


    // shooter
    SDL_Rect shooter_section = {10, 510, 580, 200};
    SDL_RenderDrawRect(renderer, &shooter_section);
    drawShootingBalls(shooter_ball, reserved_ball);

    SDL_RenderPresent(renderer);
}


void initializeBalls() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < SCREEN_WIDTH / width_of_ball_box; j++) {
            BALL ball = {
                    .color = {
                            .r=0,
                            .g=0,
                            .b=0,
                    },
                    .center = {
                            .x = double(j * width_of_ball_box + radius_of_balls + 3),
                            .y = double(i * (width_of_ball_box)),
                    },
            };
            setRandomColor(ball.color);
            balls.push_back(ball);
        }
    }
}


void setRandomColor(SDL_Color &color) {
    int i = rand() % 6;
    switch (i) {
        case (0):
            color = RED;
            break;
        case (1):
            color = CYAN;
            break;
        case (2) :
            color = BLUE;
            break;
        case (3) :
            color = PURPLE;
            break;
        case (4) :
            color = AQUA;
            break;
        default :
            color = YELLOW;
    }
}


void initializeShootingBalls(BALL &shooter_ball, BALL &reserved_ball) {

    shooter_ball.center.x = center_of_shooting_ball.x;
    shooter_ball.center.y = center_of_shooting_ball.y;

    reserved_ball.center.x = center_of_reserved_ball.x;
    reserved_ball.center.y = center_of_reserved_ball.y;

    setRandomColor(shooter_ball.color);
    setRandomColor(reserved_ball.color);
    while (reserved_ball.color.r == shooter_ball.color.r) setRandomColor(reserved_ball.color);

}


void swapShootingBalls(BALL &shooter_ball, BALL &reserved_ball) {
    swap(shooter_ball.color, reserved_ball.color);
//    cout << shooter_ball.color.r << " " ;
}


void drawShootingBalls(BALL shooter_ball, BALL reserved_ball) {
    aacircleRGBA(renderer, Sint16(shooter_ball.center.x),
                 Sint16(shooter_ball.center.y),
                 15, shooter_ball.color.r,
                 shooter_ball.color.g, shooter_ball.color.b, 255);

    aacircleRGBA(renderer, Sint16(reserved_ball.center.x), Sint16(reserved_ball.center.y), 15,
                 reserved_ball.color.r, reserved_ball.color.g, reserved_ball.color.b, 255);
//    SDL_RenderPresent(renderer);
}


void drawTargeter() {

    DOUBLE_POINT targeter_point = {
            .x = center_of_shooting_ball.x,
            .y = center_of_shooting_ball.y,
    };

    double dx = sin(degree * M_PI / 180.0) * targeter_balls_dist;
    double dy = cos(degree * M_PI / 180.0) * targeter_balls_dist;


    while (true) {

        if (targeter_point.y + dy <= 0 || checkCollTargeterAndBalls(targeter_point)) {
            break;
        }

        if (targeter_point.x + dx >= SCREEN_WIDTH) {
            dx *= -1;
        }
        if (targeter_point.x + dx <= 0) {
            dx *= -1;
        }


        if (calculateDistance(targeter_point, center_of_shooting_ball) >= 25) {
            aacircleRGBA(renderer, Sint16(targeter_point.x), Sint16(targeter_point.y), Sint16(targeter_balls_radius),
                         SILVER.r, SILVER.g, SILVER.b, 255);
        }

        targeter_point.y += dy;
        targeter_point.x += dx;
    }

}

void handleTargeterEvent(int type) {
    switch (type) {
//        case 0:
//            targeter_vertical_speed -= 0.5;
//            break;
//        case 1:
//            targeter_vertical_speed += 0.5;
//        break;
        case 0:
            if (degree >= 100)
                degree -= 0.5;
            break;
        case 1:
            if (degree <= 260)
                degree += 0.5;
            break;
        default:
            break;
    }
}

bool checkCollTargeterAndBalls(DOUBLE_POINT targeter_point) {

    for (unsigned int i = balls.size(); i > 0; i--) {
        BALL &ball = balls[i];

        if (ball.center.y <= -10) return false;

        if (calculateDistance(ball.center, targeter_point) <= radius_of_balls + 15) return true;

    }

}


double calculateDistance(DOUBLE_POINT a, DOUBLE_POINT b) {
    return sqrt((a.y - b.y) * (a.y - b.y) +
                (a.x - b.x) * (a.x - b.x));
}


void handleShootBall(BALL &shooting_ball, BALL &reserved_ball) {

    if (!ball_is_being_thrown) {
        ball_is_being_thrown = true;
        thrown_ball = shooting_ball;
        shooting_ball = reserved_ball;
        shooting_ball.center = center_of_shooting_ball;
        reserved_ball.center = center_of_reserved_ball;

        setRandomColor(reserved_ball.color);
        while (reserved_ball.color.r == shooting_ball.color.r) setRandomColor(reserved_ball.color);
        dxOfThrownBall = sin(degree * M_PI / 180.0) * SPEED_OF_THROWN_BALL;
        dyOfThrownBall = cos(degree * M_PI / 180.0) * SPEED_OF_THROWN_BALL;
        drawShootingBalls(shooting_ball , reserved_ball);
    }


}

void handleBallShooting() {

    if (thrown_ball.center.y + dyOfThrownBall <= 0) {
        ball_is_being_thrown = false;
    } else {
        if (thrown_ball.center.x + radius_of_balls + dxOfThrownBall >= SCREEN_WIDTH) {
            dxOfThrownBall *= -1;
        }
        if (thrown_ball.center.x + dxOfThrownBall - radius_of_balls <= 0) {
            dxOfThrownBall *= -1;
        }
    }
    thrown_ball.center.x += dxOfThrownBall;
    thrown_ball.center.y += dyOfThrownBall;

    aacircleRGBA(renderer, Sint16(thrown_ball.center.x), Sint16(thrown_ball.center.y),
                 Sint16(radius_of_balls), thrown_ball.color.r, thrown_ball.color.g, thrown_ball.color.b, 255);

}