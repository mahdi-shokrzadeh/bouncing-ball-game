#ifndef BOUNCING_BALL_GAME_THEMES_H
#define BOUNCING_BALL_GAME_THEMES_H



struct theme {
    int num;
    char bg[64]; //background address
    char music[64]; //music address
    char button[64]; //button address
    char buttonHover[64]; //button Hover address
    char buttonQuit[64]; //button Quit address
    char cannon[64]; //cannon image address
    char fontLoc[64]; //font address
    int fontSize;
    SDL_Color MainColor; //theme main color
    SDL_Color SecColor; //theme second color
    SDL_Color TextColor; //theme text color
    // to be continued...
};

const theme th1 = {0, "", "", "", "","", "", "", 50, BLUE, CYAN, WHITE};
const theme Jungle = {1, "assets/Jungle/bg.jpg", "assets/Jungle/music.mp3",
                      "assets/Jungle/button.png", "assets/Jungle/buttonHover.png", "assets/Jungle/buttonQuit.png",
                      "",
                      "assets/Jungle/font.ttf", 50,
                      BROWN, CHOCOLATE, WHITE};
const theme Ocean = {2, "assets/Ocean/bg.jpg", "assets/Ocean/music.mp3",
                     "assets/Ocean/button.png", "assets/Ocean/buttonHover.png", "assets/Ocean/buttonQuit.png",
                     "",
                     "assets/Ocean/font.ttc", 50,
                     GREEN, FOREST_GREEN, WHITE};
const theme Space = {3, "assets/Space/bg.jpg", "assets/Space/music.mp3",
                     "assets/Space/button.png", "assets/Space/buttonHover.png", "assets/Space/buttonQuit.png",
                     "",
                     "assets/Space/font.ttc", 50,
                     BLUE, CYAN, WHITE};


#endif //BOUNCING_BALL_GAME_THEMES_H
