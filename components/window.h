#ifndef BOUNCING_BALL_GAME_WINDOW_H
#define BOUNCING_BALL_GAME_WINDOW_H

// building and destroying

void imageRender(SDL_Surface* &surface, SDL_Texture* &texture,
                 SDL_Rect &src, SDL_Rect &dest,
                 int x, int y, float multiplier, char address[64]) {

    surface = IMG_Load(address);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    src.x = 0;
    src.y = 0;
    src.w = surface->w;
    src.h = surface->h;

    dest.x = x;
    dest.y = y;
    dest.w = surface->w * multiplier;
    dest.h = surface->h * multiplier;
}

void textRender(SDL_Surface* &surface, SDL_Texture* &texture,
                 SDL_Rect &src, SDL_Rect &dest,
                 int x, int y, float multiplier, string text) {

    surface = TTF_RenderText_Solid(font, text.c_str(), th.TextColor);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    src.x = 0;
    src.y = 0;
    src.w = surface->w;
    src.h = surface->h;

    dest.x = x;
    dest.y = y;
    dest.w = surface->w * multiplier;
    dest.h = surface->h * multiplier;
}

bool checkInOut(int x, int y, SDL_Rect rect) {
    return (x >= rect.x && x <= rect.x + rect.w) && (y >= rect.y && y <= rect.y + rect.h);
}

void initializeButtons() {

    //setting button
    imageRender(settingButtonSurface, settingButton,settingButtonRectSrc,
                settingButtonRect, 10, 660, 2, "assets/UiUx/setting.svg");

    //exit button
    imageRender(exitButtonSurface, exitButton,exitButtonRectSrc,
                exitButtonRect, 550, 660, 2, "assets/UiUx/exit.svg");

    //start button
    imageRender(startButtonSurface, startButton,startButtonRectSrc,
                startButtonRect, 100, 300, 0.3, th.button);
    textRender(startTextSurface, startText, startTextRectSrc,
               startTextRect, 163, 364, 0.5, "Start");

    //leader button
    imageRender(leaderButtonSurface, leaderButton,leaderButtonRectSrc,
                leaderButtonRect, 300, 300, 0.3, th.button);
    textRender(leaderTextSurface, leaderText, leaderTextRectSrc,
               leaderTextRect, 345, 370, 0.3, "LeaderBoard");

    //back button
    imageRender(backButtonSurface, backButton,backButtonRectSrc,
                backButtonRect, 220, 580, 0.3, th.button);
    textRender(backTextSurface, backText, backTextRectSrc,
               backTextRect, 280, 645, 0.5, "Back");

}

void destroyButtons() {
    SDL_FreeSurface(settingButtonSurface);
    SDL_DestroyTexture(settingButton);

    SDL_FreeSurface(exitButtonSurface);
    SDL_DestroyTexture(exitButton);

    SDL_FreeSurface(startButtonSurface);
    SDL_DestroyTexture(startButton);
    SDL_FreeSurface(startTextSurface);
    SDL_DestroyTexture(startText);

    SDL_FreeSurface(leaderButtonSurface);
    SDL_DestroyTexture(leaderButton);
    SDL_FreeSurface(leaderTextSurface);
    SDL_DestroyTexture(leaderText);

    SDL_FreeSurface(backButtonSurface);
    SDL_DestroyTexture(backButton);
    SDL_FreeSurface(backTextSurface);
    SDL_DestroyTexture(backText);
}

// Menus

void Main_Menu(bool MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator) {

    // initialing and Drawing background

    SDL_SetRenderDrawColor(renderer, th.MainColor.r, th.MainColor.g, th.MainColor.b, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, bg, NULL, &bgRect);

    // start button

    SDL_RenderCopy(renderer, startButton, &startButtonRectSrc, &startButtonRect);
    SDL_RenderCopy(renderer, startText, &startTextRectSrc, &startTextRect);

    // Leaderboard button

    SDL_RenderCopy(renderer, leaderButton, &leaderButtonRectSrc, &leaderButtonRect);
    SDL_RenderCopy(renderer, leaderText, &leaderTextRectSrc, &leaderTextRect);


    // setting button
    SDL_RenderCopy(renderer, settingButton, &settingButtonRectSrc, &settingButtonRect);

    // exit button
    SDL_RenderCopy(renderer, exitButton, &exitButtonRectSrc, &exitButtonRect);


    // mouse actions

    /*if(x_MouseWhere >= startBtn.x && x_MouseWhere <= startBtn.x + startBtn.w && y_MouseWhere >= startBtn.y && y_MouseWhere <= startBtn.y + startBtn.h){
        void;
    }*/
    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, startButtonRect)){
        Locator["game"] = !Locator["game"];
        Locator["main_menu"] = !Locator["main_menu"];
    }
    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, leaderButtonRect)){
        Locator["leaderboard"] = !Locator["leaderboard"];
        Locator["main_menu"] = !Locator["main_menu"];
    }


}


void leaderboard(bool MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator) {

    // initialing and Drawing background

    SDL_SetRenderDrawColor(renderer, th.MainColor.r, th.MainColor.g, th.MainColor.b, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, bg, NULL, &bgRect);

    // data box
    SDL_Rect fillRect = {50, 50, 500, 500};
    SDL_RenderFillRect(renderer, &fillRect);

    // back button
    SDL_RenderCopy(renderer, backButton, &backButtonRectSrc, &backButtonRect);
    SDL_RenderCopy(renderer, backText, &backTextRectSrc, &backTextRect);

//    // setting button
//    SDL_RenderCopy(renderer, settingButton, &settingButtonRectSrc, &settingButtonRect);
//
//    // exit button
//    SDL_RenderCopy(renderer, exitButton, &exitButtonRectSrc, &exitButtonRect);

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, backButtonRect)){
        Locator["leaderboard"] = !Locator["leaderboard"];
        Locator["main_menu"] = !Locator["main_menu"];
    }
}



#endif //BOUNCING_BALL_GAME_WINDOW_H