#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
//#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL2_gfx.h>

using namespace std;

// Headers
#include "common/colors.h"


//Global variables
#define DELAY 10
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 720


// structures
typedef struct DOUBLE_POINT {
    double x;
    double y;
} DOUBLE_POINT;


typedef struct BALL {
    RGB_COLOR color;
    DOUBLE_POINT center;
} BALL;




// variables related to balls
const int radius_of_balls = 15;
const int width_of_ball_box = 35;
double vertical_speed = 0.4;
vector <BALL> balls;






using namespace std;

// variables

// SDL Window
SDL_Window *window;

// SDL Renderer to draw to
SDL_Renderer *renderer;


// funcs
void setRandomColor(RGB_COLOR &color);
void initializeBalls();
void initializeShooterBalls(BALL &shooter_ball ,BALL &reserved_ball);


void game_loop() {

    SDL_bool loop = SDL_TRUE;
    SDL_Event event;


    initializeBalls();
    BALL shooter_ball;
    BALL reserved_ball;
    initializeShooterBalls(shooter_ball , reserved_ball);


    while (loop) {
        // Allow quiting with escape key by polling for pending events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                loop = SDL_FALSE;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        loop = SDL_FALSE;
                        break;
                    default:
                        loop = SDL_TRUE;
                }
            }
        }

        // Blank out the renderer with all black
        SDL_SetRenderDrawColor(renderer, BLACK.r , BLACK.g , BLACK.b, 255);
        SDL_RenderClear(renderer);


        //

        for (int i = 0; i < balls.size(); i++) {
            BALL &ball = balls[i];
            ball.center.y += vertical_speed;
            aacircleRGBA(renderer , Sint16(ball.center.x)
                    , Sint16(ball.center.y) , 15 , ball.color.r , ball.color.g , ball.color.b , 255);
        }


        // Shooter

        SDL_Rect shooter_section = { 10 , 510 , 580 , 200};
        SDL_RenderDrawRect(renderer , &shooter_section );
        aacircleRGBA(renderer , Sint16(shooter_ball.center.x)
                , Sint16(shooter_ball.center.y) , 15 , shooter_ball.color.r , shooter_ball.color.g , shooter_ball.color.b , 255);

        aacircleRGBA(renderer , Sint16(reserved_ball.center.x)
                , Sint16(reserved_ball.center.y) , 15 , reserved_ball.color.r , reserved_ball.color.g , reserved_ball.color.b , 255);




        // Present to renderer
        SDL_RenderPresent(renderer);
        SDL_Delay(DELAY);
    }
}


int main(int argv, char** args) {

    srand(time(NULL));


    // SDL Inits
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER;
//    Uint32 WND_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;//SDL_WINDOW_BORDERLESS ;
    SDL_Init(SDL_flags);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, WND_flags, &window, &renderer);
    SDL_RaiseWindow(window);
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);

    game_loop();

    //clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


void initializeBalls(){
    for(int i = 1 ; i <= 5 ; i ++){
        for(int j = 0 ; j < SCREEN_WIDTH/width_of_ball_box ; j ++){
            BALL ball ={
                    .color = {
                            .r=0,
                            .g=0,
                            .b=0,
                    },
                    .center = {
                            .x = double(j*width_of_ball_box + radius_of_balls + 3),
                            .y = double(i*(width_of_ball_box)),
                    },
            };
            setRandomColor(ball.color);
            balls.push_back(ball);
        }
    }
}


void setRandomColor(RGB_COLOR &color)
{
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


void initializeShooterBalls(BALL &shooter_ball , BALL &reserved_ball){
    shooter_ball.center = {
            .x = 300,
            .y = 620,
    };
    reserved_ball.center = {
            .x = 220,
            .y = 670,
    };

    setRandomColor(shooter_ball.color);
    setRandomColor(reserved_ball.color);
    while (reserved_ball.color.r == shooter_ball.color.r) setRandomColor(reserved_ball.color);

}