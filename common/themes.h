#ifndef BOUNCING_BALL_GAME_THEMES_H
#define BOUNCING_BALL_GAME_THEMES_H

#include <string>
#include "colors.h"

struct theme {
    string bg; //background address
    string music; //music address
    int MainR, MainG, MainB; //theme main color
    int SecR, SecG, SecB; //theme second color
    // to be continued...
};

const theme th1 = {"", "",
                   BLUE.r, BLUE.g, BLUE.b,
                   CYAN.r, CYAN.g, CYAN.b};

#endif //BOUNCING_BALL_GAME_THEMES_H
