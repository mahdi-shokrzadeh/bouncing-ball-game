#ifndef BOUNCING_BALL_GAME_THEMES_H
#define BOUNCING_BALL_GAME_THEMES_H



struct theme {
    int num;
    char logo[64]; //logo address
    char bg[64]; //background address
    char music[64]; //music address
    char button[64]; //button address
    char buttonHover[64]; //button Hover address
    char buttonQuit[64]; //button Quit address
    char cannon[64]; //cannon image address
    int loc[100];
    char fontLoc[64]; //font address
    int fontSize;
    float sizeMultiplier;
    SDL_Color MainColor; //theme main color
    SDL_Color SecColor; //theme second color
    SDL_Color TextColor; //theme text color
    // to be continued...
};

const theme th1 = {0, "", "", "", "", "","", "", {1, 1}, "", 50, 0.5, BLUE, CYAN, WHITE};
const theme Jungle = {1, "assets/Jungle/logo.png", "assets/Jungle/bg.jpg", "assets/Jungle/music.mp3",
                      "assets/Jungle/button.png", "assets/Jungle/buttonHover.png", "assets/Jungle/buttonQuit.png",
                      "",{65, 400, 97, 427, 365, 400, 378, 440, 215, 595, 245, 625, 255, 290, 75, 230, 393, 232, 90, 133, 0, 0, 0, 0, 0},
                      "assets/Jungle/font.ttf", 50, 10.0/29,
                      BROWN, CHOCOLATE, WHITE};
const theme Ocean = {2, "assets/Ocean/logo.png", "assets/Ocean/bg.jpg", "assets/Ocean/music.mp3",
                     "assets/Ocean/button.png", "assets/Ocean/buttonHover.png", "assets/Ocean/buttonQuit.png",
                     "",{65, 400, 87, 440, 365, 400, 378, 453, 215, 580, 245, 625, 255, 290, 75, 245, 393, 245, 90, 133, -10, 10, 0, 0, 0},
                     "assets/Ocean/font.ttf", 50, 17.0/74,
                     BLUE, CYAN, WHITE};
const theme Space = {3, "assets/Space/logo.png", "assets/Space/bg.jpg", "assets/Space/music.mp3",
                     "assets/Space/button.png", "assets/Space/buttonHover.png", "assets/Space/buttonQuit.png",
                     "",{85, 400, 105, 435, 385, 400, 390, 445, 235, 590, 255, 625, 263, 295, 83, 238, 403, 238, 95, 138, -3, 0, 15, 30, 5},
                     "assets/Space/font.ttc", 40, 1.0/3,
                     INDIGO, VIOLET, WHITE};


#endif //BOUNCING_BALL_GAME_THEMES_H
