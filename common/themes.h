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
                      "",{65, 400, 97, 427, 365, 400, 378, 440, 215, 595, 245, 625, 255, 310, 75, 230, 393, 232, 90, 133},
                      "assets/Jungle/font.ttf", 50, 10.0/29,
                      BROWN, CHOCOLATE, WHITE};
const theme Ocean = {2, "assets/Ocean/logo.png", "assets/Ocean/bg.jpg", "assets/Ocean/music.mp3",
                     "assets/Ocean/button.png", "assets/Ocean/buttonHover.png", "assets/Ocean/buttonQuit.png",
                     "",{65, 400, 97, 427, 365, 400, 378, 440, 215, 595, 245, 625, 255, 310, 75, 230, 393, 232, 90, 133},
                     "assets/Ocean/font.ttc", 50, 17.0/74,
                     GREEN, FOREST_GREEN, BLACK};
const theme Space = {3, "assets/Space/logo.png", "assets/Space/bg.jpg", "assets/Space/music.mp3",
                     "assets/Space/button.png", "assets/Space/buttonHover.png", "assets/Space/buttonQuit.png",
                     "",{65, 400, 97, 427, 365, 400, 378, 440, 215, 595, 245, 625, 255, 310, 75, 230, 393, 232, 90, 133},
                     "assets/Space/font.ttc", 50, 4.0/10,
                     BLUE, CYAN, WHITE};


#endif //BOUNCING_BALL_GAME_THEMES_H
