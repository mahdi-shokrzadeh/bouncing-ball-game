#ifndef BOUNCING_BALL_GAME_THEMES_H
#define BOUNCING_BALL_GAME_THEMES_H

#include <string>
#include "colors.h"

struct theme {
    string bg; //background address
    string music; //music address
    RGB_COLOR MainColor; //theme main color
    RGB_COLOR SecColor; //theme second color
    // to be continued...
};

const theme th1 = {"", "", BLUE, CYAN};

#endif //BOUNCING_BALL_GAME_THEMES_H
