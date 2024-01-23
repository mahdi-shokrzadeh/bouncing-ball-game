#ifndef BOUNCING_BALL_GAME_THEMES_H
#define BOUNCING_BALL_GAME_THEMES_H



struct theme {
    char bg[64]; //background address
    char music[64]; //music address
    char button[64]; //button address
    char cannon[64]; //cannon image address
    char font[64]; //font address
    SDL_Color MainColor; //theme main color
    SDL_Color SecColor; //theme second color
    SDL_Color TextColor; //theme text color
    // to be continued...
};

const theme th1 = {"", "", "", "", "", BLUE, CYAN, WHITE};
const theme Jungle = {"assets/Jungle/bg.jpg", "assets/Jungle/music.mp3", "assets/Jungle/button.png",
                      "", "assets/Jungle/font.ttf", BROWN, CHOCOLATE, WHITE};
const theme Ocean = {"assets/Ocean/bg.jpg", "assets/Ocean/music.mp3", "assets/Ocean/button.png",
                     "", "assets/Ocean/font.ttf", GREEN, FOREST_GREEN, WHITE};
const theme Space = {"assets/Space/bg.jpg", "assets/Space/music.mp3", "assets/Space/button.png",
                     "", "assets/Space/font.ttf", BLUE, CYAN, WHITE};


void themeChanger(theme newTheme) {

}


#endif //BOUNCING_BALL_GAME_THEMES_H
