
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
#include <chrono>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#ifdef _WIN32
    #include <SDL2/SDL2_gfx.h>
#else
    #include <SDL2/SDL2_gfxPrimitives.h>
#endif

using namespace std;

// Headers

#include "common/colors.h"
#include "common/themes.h"
#include "components/settings.h"
#include "components/structs.h"
#include "common/functions.h"
#include "components/filemanage.h"
#include "components/window.h"
#include "components/game.h"



// funcs

void loop() {

    bool MouseClicked = false;
    int x_MouseClicked = 0;
    int y_MouseClicked = 0;
    int x_MouseWhere = 0;
    int y_MouseWhere = 0;


    Locator["main_menu"] = true;
    Locator["username_getter"] = false;
    Locator["start_menu"] = false;
    Locator["level_selector"] = false;
    Locator["random_mode"] = false;
    Locator["infinite_mode"] = false;
    Locator["leaderStart"] = false;
    Locator["leaderLevel"] = false;
    Locator["leaderboard"] = false;
    Locator["setting_menu"] = false;
    Locator["quit_menu"] = false;
    Locator["game"] = false;

    //bool normal_or_timed = true;// true == normal, false == timed
    //int levelNum = 0;
    GAME_INF gameInfo = {"", "", 0};


    while (main_loop) {

        // Allow quiting with escape key by polling for pending events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                main_loop = SDL_FALSE;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_BACKSPACE:
                        if (Locator["username_getter"])
                            if (inputText == "Enter Your Name") inputText = "";
                            else inputText = inputText.substr(0, inputText.length() - 1);
                        inputTextPresent();
                        break;
                    case SDLK_RETURN :
                        if (Locator["username_getter"]) {
                            gameInfo.user = inputText;
                            inputText = "Enter Your Name";
                            Locator["start_menu"] = !Locator["start_menu"];
                            Locator["username_getter"] = !Locator["username_getter"];
                        }
                        inputTextPresent();
                        break;
                    default:
                        main_loop = SDL_TRUE;
                }
            } else if (event.type == SDL_KEYUP) {
                switch (event.key.keysym.sym) {
                    default:
                        main_loop = SDL_TRUE;
                }
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                MouseClicked = true;
                x_MouseClicked = event.button.x;
                y_MouseClicked = event.button.y;
            } else if (event.type == SDL_MOUSEBUTTONUP) {
                MouseClicked = false;
            } else if (event.type == SDL_TEXTINPUT && Locator["username_getter"]) {
                if (inputText == "Enter Your Name") inputText = "";
                inputText += event.text.text;
                inputTextPresent();
            }
        }

        // get mouse free location
        SDL_GetMouseState(&x_MouseWhere, &y_MouseWhere);


        // Blank out the renderer with all black
        SDL_SetRenderDrawColor(renderer, BLACK.r, BLACK.g, BLACK.b, 255);
        SDL_RenderClear(renderer);


        // Blank out the renderer with all black
        SDL_SetRenderDrawColor(renderer, BLACK.r, BLACK.g, BLACK.b, 255);
        SDL_RenderClear(renderer);

        if (Locator["main_menu"])
            Main_Menu(MouseClicked, x_MouseClicked, y_MouseClicked, x_MouseWhere, y_MouseWhere, Locator);
        else if (Locator["username_getter"])
            username_getter(MouseClicked, x_MouseClicked, y_MouseClicked, x_MouseWhere, y_MouseWhere, Locator);
        else if (Locator["start_menu"])
            start_Menu(MouseClicked, x_MouseClicked, y_MouseClicked, x_MouseWhere, y_MouseWhere, Locator, gameInfo);
        else if (Locator["level_selector"])
            level_selector(MouseClicked, x_MouseClicked, y_MouseClicked, x_MouseWhere, y_MouseWhere, Locator, gameInfo);
        else if (Locator["leaderStart"])
            leader_start_Menu(MouseClicked, x_MouseClicked, y_MouseClicked, x_MouseWhere, y_MouseWhere, Locator, gameInfo);
        else if (Locator["leaderLevel"])
            leader_level_selector(MouseClicked, x_MouseClicked, y_MouseClicked, x_MouseWhere, y_MouseWhere, Locator, gameInfo);
        else if (Locator["leaderboard"])
            leaderboard(MouseClicked, x_MouseClicked, y_MouseClicked, x_MouseWhere, y_MouseWhere, Locator, gameInfo);
        else if (Locator["setting_menu"])
            settingMenu(MouseClicked, x_MouseClicked, y_MouseClicked, x_MouseWhere, y_MouseWhere, Locator);
        else if (Locator["quit_menu"])
            quitMenu(MouseClicked, x_MouseClicked, y_MouseClicked, x_MouseWhere, y_MouseWhere, Locator);
        else if (Locator["game"])
            handleGameProcess(gameInfo);


        // //Present to renderer
        SDL_RenderPresent(renderer);
        SDL_Delay(DELAY);
    }
}


int main(int argv, char **args) {

    srand(time(NULL));
    settingReader();
    reInitialingSoundMusic();

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
    font = TTF_OpenFont(th.fontLoc, th.fontSize);

    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    music = Mix_LoadMUS(th.music);
    Mix_VolumeMusic(musicVolume * 128 / 100);
    Mix_PlayMusic(music, -1);

    //set icon and title
    SDL_Surface *icon = IMG_Load("assets/icon.png");
    SDL_SetWindowIcon(window, icon);
    SDL_SetWindowTitle(window, "Bouncing Ball Gameeeeee!!!!");

    initializeButtonsAndBG();
    initializeBallsTexture();
    initializeSoundSFX();

    SDL_StartTextInput();
    inputTextPresent();


    //loop
    loop();


    //clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;

    TTF_CloseFont(font);
    font = NULL;

    Mix_FreeMusic(music);
    music = NULL;

    SDL_FreeSurface(icon);

    destroyButtonsAndBG();
    destroyBallsTexture();
    destroySoundSFX();

    SDL_StopTextInput();

    //Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();
    return 0;
}