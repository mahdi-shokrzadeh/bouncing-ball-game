#ifndef BOUNCING_BALL_GAME_THEMES_H
#define BOUNCING_BALL_GAME_THEMES_H

#include <string>
#include "colors.h"

struct theme {
    string bg; //background address
    string music; //music address
    string cannon; //cannon image address
    SDL_Color MainColor; //theme main color
    SDL_Color SecColor; //theme second color
    SDL_Color TextColor; //theme text color
    // to be continued...
};

const theme th1 = {"", "", "", BLUE, CYAN, WHITE};

#endif //BOUNCING_BALL_GAME_THEMES_H
