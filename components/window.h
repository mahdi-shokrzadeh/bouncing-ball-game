#ifndef BOUNCING_BALL_GAME_WINDOW_H
#define BOUNCING_BALL_GAME_WINDOW_H

// building and destroying

void buttonMaker(SDL_Surface *surface, SDL_Texture *texture, SDL_Rect &src, SDL_Rect &dest, char address[64]) {
    surface = IMG_Load(address);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

        src.x = 0;
        src.y = 0;
        src.w = surface->w;
        src.h = surface->h;

    dest.x = 10;
    dest.y = 660;
    dest.w = surface->w * 2;
    dest.h = surface->h * 2;
}

void initializeButtons() {

    //setting button

    settingButtonSurface = IMG_Load("assets/UiUx/setting.svg");
    settingButton = SDL_CreateTextureFromSurface(renderer, settingButtonSurface);
    settingButtonRectSrc.x = 0;
    settingButtonRectSrc.y = 0;
    settingButtonRectSrc.w = settingButtonSurface->w;
    settingButtonRectSrc.h = settingButtonSurface->h;
    settingButtonRect.x = 10;
    settingButtonRect.y = 660;
    settingButtonRect.w = settingButtonSurface->w * 2;
    settingButtonRect.h = settingButtonSurface->h * 2;


    //buttonMaker(settingButtonSurface, settingButton, settingButtonRectSrc, settingButtonRect, "assets/UiUx/setting.svg");

    //exit button
    exitButtonSurface = IMG_Load("assets/UiUx/exit.svg");
    exitButton = SDL_CreateTextureFromSurface(renderer, exitButtonSurface);
    exitButtonRectSrc.x = 0;
    exitButtonRectSrc.y = 0;
    exitButtonRectSrc.w = exitButtonSurface->w;
    exitButtonRectSrc.h = exitButtonSurface->h;
    exitButtonRect.x = 550;
    exitButtonRect.y = 660;
    exitButtonRect.w = exitButtonSurface->w * 2;
    exitButtonRect.h = exitButtonSurface->h * 2;



}

void destroyButtons() {
    SDL_FreeSurface(settingButtonSurface);
    SDL_DestroyTexture(settingButton);

    SDL_FreeSurface(exitButtonSurface);
    SDL_DestroyTexture(exitButton);

//    SDL_DestroyTexture(startText);
//    SDL_FreeSurface(startSurf);
//    SDL_DestroyTexture(leaderText);
//    SDL_FreeSurface(leaderSurf);
}

// Menus

void Main_Menu(bool MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator) {

    // initialing and Drawing background

    SDL_SetRenderDrawColor(renderer, th.MainColor.r, th.MainColor.g, th.MainColor.b, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, bg, NULL, &bgRect);

    // start button
    SDL_Rect startBtn = {100, 300, 400, 80};
    SDL_Surface *startSurf = TTF_RenderText_Solid(font, "Start", WHITE);
    SDL_Texture *startText = SDL_CreateTextureFromSurface(renderer, startSurf);
    SDL_Rect textStart = {250, 300, startSurf->w, startSurf->h};

    SDL_SetRenderDrawColor(renderer, th.SecColor.r, th.SecColor.g, th.SecColor.b, 255);
    SDL_RenderFillRect(renderer, &startBtn);
    SDL_RenderCopy(renderer, startText, NULL, &textStart);

    // Leaderboard button
    SDL_Rect leaderBtn = {100, 400, 400, 80};
    SDL_Surface *leaderSurf = TTF_RenderText_Solid(font, "Leaderboard", WHITE);
    SDL_Texture *leaderText = SDL_CreateTextureFromSurface(renderer, leaderSurf);
    SDL_Rect textLeader = {170, 400, leaderSurf->w, leaderSurf->h};

    SDL_SetRenderDrawColor(renderer, th.SecColor.r, th.SecColor.g, th.SecColor.b, 255);
    SDL_RenderFillRect(renderer, &leaderBtn);
    SDL_RenderCopy(renderer, leaderText, NULL, &textLeader);


    // setting button
    SDL_RenderCopy(renderer, settingButton, &settingButtonRectSrc, &settingButtonRect);

    // exit button
    SDL_RenderCopy(renderer, exitButton, &exitButtonRectSrc, &exitButtonRect);


    // mouse actions

    // start actions
    /*if(x_MouseWhere >= startBtn.x && x_MouseWhere <= startBtn.x + startBtn.w && y_MouseWhere >= startBtn.y && y_MouseWhere <= startBtn.y + startBtn.h){
        void;
    }*/
    if(MouseClicked && (x_MouseClicked >= startBtn.x && x_MouseClicked <= startBtn.x + startBtn.w) && (y_MouseClicked >= startBtn.y && y_MouseClicked <= startBtn.y + startBtn.h)){
        Locator["game"] = !Locator["game"];
        Locator["main_menu"] = !Locator["main_menu"];
    }

}





#endif //BOUNCING_BALL_GAME_WINDOW_H