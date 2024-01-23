
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
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <fstream>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL2_gfxPrimitives.h>
//#include <SDL2/SDL2_gfx.h>

using namespace std;

// Headers

#include "common/colors.h"
#include "common/themes.h"
#include "components/settings.h"
#include "components/structs.h"
#include "components/window.h"
#include "components/game.h"
#include "components/filemanage.h"



// funcs

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



    map<string, bool> Locator;
    Locator["main_menu"] = true;
    Locator["start_menu"] = false;
    Locator["game"] = false;



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

        if (Locator["main_menu"])
            Main_Menu(MouseClicked, x_MouseClicked, y_MouseClicked, x_MouseWhere, y_MouseWhere, Locator);
        else if (Locator["game"])
            Game(shooter_ball, reserved_ball);
        // //Present to renderer
        //SDL_RenderPresent(renderer);
        SDL_Delay(DELAY);
    }
}


int main(int argv, char **args) {

    srand(time(NULL));
    settingReader();

    // SDL Inits
    Uint32 SDL_flags = SDL_INIT_EVERYTHING;
    // Uint32 WND_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;
    SDL_Init(SDL_flags);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, WND_flags, &window, &renderer);
    SDL_RaiseWindow(window);

    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);

    TTF_Init();
    font = TTF_OpenFont("assets/font.ttc", 50);


    //loop
    loop();


    //clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;

    TTF_CloseFont(font);
    font = NULL;

    TTF_Quit();
    SDL_Quit();
    return 0;
}