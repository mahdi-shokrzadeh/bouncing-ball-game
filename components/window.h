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
    imageRender(startHoverButtonSurface, startHoverButton,startHoverButtonRectSrc,
                startHoverButtonRect, 100, 300, 0.3, th.buttonHover);
    textRender(startTextSurface, startText, startTextRectSrc,
               startTextRect, 163, 364, 0.5, "Start");

    //leader button
    imageRender(leaderButtonSurface, leaderButton,leaderButtonRectSrc,
                leaderButtonRect, 300, 300, 0.3, th.button);
    imageRender(leaderHoverButtonSurface, leaderHoverButton,leaderHoverButtonRectSrc,
                leaderHoverButtonRect, 300, 300, 0.3, th.buttonHover);
    textRender(leaderTextSurface, leaderText, leaderTextRectSrc,
               leaderTextRect, 345, 370, 0.3, "LeaderBoard");

    //back button
    imageRender(backButtonSurface, backButton,backButtonRectSrc,
                backButtonRect, 220, 580, 0.3, th.button);
    imageRender(backHoverButtonSurface, backHoverButton,backHoverButtonRectSrc,
                backHoverButtonRect, 220, 580, 0.3, th.buttonHover);
    textRender(backTextSurface, backText, backTextRectSrc,
               backTextRect, 280, 645, 0.5, "Back");

    //quit menu
    textRender(DoYouWantToQuitTextSurface, DoYouWantToQuitText, DoYouWantToQuitTextRectSrc,
               DoYouWantToQuitTextRect, 70, 240, 0.5, "Do you Really want to quit the Game? :(");
    imageRender(iWantQuitButtonSurface, iWantQuitButton,iWantQuitButtonRectSrc,
                iWantQuitButtonRect, 220, 260, 0.3, th.buttonQuit);
    textRender(iWantQuitTextSurface, iWantQuitText, iWantQuitTextRectSrc,
               iWantQuitTextRect, 260, 305, 1, "Yes!");

}

void destroyButtons() {
    SDL_FreeSurface(settingButtonSurface);
    SDL_DestroyTexture(settingButton);

    SDL_FreeSurface(exitButtonSurface);
    SDL_DestroyTexture(exitButton);

    SDL_FreeSurface(startButtonSurface);
    SDL_DestroyTexture(startButton);
    SDL_FreeSurface(startHoverButtonSurface);
    SDL_DestroyTexture(startHoverButton);
    SDL_FreeSurface(startTextSurface);
    SDL_DestroyTexture(startText);

    SDL_FreeSurface(leaderButtonSurface);
    SDL_DestroyTexture(leaderButton);
    SDL_FreeSurface(leaderHoverButtonSurface);
    SDL_DestroyTexture(leaderHoverButton);
    SDL_FreeSurface(leaderTextSurface);
    SDL_DestroyTexture(leaderText);

    SDL_FreeSurface(backButtonSurface);
    SDL_DestroyTexture(backButton);
    SDL_FreeSurface(backHoverButtonSurface);
    SDL_DestroyTexture(backHoverButton);
    SDL_FreeSurface(backTextSurface);
    SDL_DestroyTexture(backText);

    SDL_FreeSurface(DoYouWantToQuitTextSurface);
    SDL_DestroyTexture(DoYouWantToQuitText);
    SDL_FreeSurface(iWantQuitButtonSurface);
    SDL_DestroyTexture(iWantQuitButton);
    SDL_FreeSurface(iWantQuitTextSurface);
    SDL_DestroyTexture(iWantQuitText);
}

// Menus

void Main_Menu(bool MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator) {

    // initialing and Drawing background

    SDL_SetRenderDrawColor(renderer, th.MainColor.r, th.MainColor.g, th.MainColor.b, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, bg, NULL, &bgRect);

    // start button
    if(!checkInOut(x_MouseWhere, y_MouseWhere, startButtonRect))
        SDL_RenderCopy(renderer, startButton, &startButtonRectSrc, &startButtonRect);
    else
        SDL_RenderCopy(renderer, startHoverButton, &startHoverButtonRectSrc, &startHoverButtonRect);
    SDL_RenderCopy(renderer, startText, &startTextRectSrc, &startTextRect);

    // Leaderboard button
    if(!checkInOut(x_MouseWhere, y_MouseWhere, leaderButtonRect))
        SDL_RenderCopy(renderer, leaderButton, &leaderButtonRectSrc, &leaderButtonRect);
    else
        SDL_RenderCopy(renderer, leaderHoverButton, &leaderHoverButtonRectSrc, &leaderHoverButtonRect);
    SDL_RenderCopy(renderer, leaderText, &leaderTextRectSrc, &leaderTextRect);

    // setting button
    SDL_RenderCopy(renderer, settingButton, &settingButtonRectSrc, &settingButtonRect);

    // exit button
    SDL_RenderCopy(renderer, exitButton, &exitButtonRectSrc, &exitButtonRect);


    // mouse click actions

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, startButtonRect)){
        Locator["game"] = !Locator["game"];
        Locator["main_menu"] = !Locator["main_menu"];
    }
    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, leaderButtonRect)){
        Locator["leaderboard"] = !Locator["leaderboard"];
        Locator["main_menu"] = !Locator["main_menu"];
    }
    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, settingButtonRect)){
        Locator["setting_menu"] = !Locator["setting_menu"];
        Locator["main_menu"] = !Locator["main_menu"];
    }
    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, exitButtonRect)){
        Locator["quit_menu"] = !Locator["quit_menu"];
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
    if(!checkInOut(x_MouseWhere, y_MouseWhere, backButtonRect))
        SDL_RenderCopy(renderer, backButton, &backButtonRectSrc, &backButtonRect);
    else
        SDL_RenderCopy(renderer, backHoverButton, &backHoverButtonRectSrc, &backHoverButtonRect);
    SDL_RenderCopy(renderer, backText, &backTextRectSrc, &backTextRect);

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, backButtonRect)){
        Locator["leaderboard"] = !Locator["leaderboard"];
        Locator["main_menu"] = !Locator["main_menu"];
    }
}

void settingMenu(bool MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator) {

}

void quitMenu(bool MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator) {

    // initialing and Drawing background

    SDL_SetRenderDrawColor(renderer, th.SecColor.r, th.SecColor.g, th.SecColor.b, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, bg, NULL, &bgRect);

    // question box
    SDL_Rect questionBox = {50, 200, 500, 200};
    SDL_RenderFillRect(renderer, &questionBox);
    SDL_RenderCopy(renderer, DoYouWantToQuitText, &DoYouWantToQuitTextRectSrc, &DoYouWantToQuitTextRect);

    // yes box
    SDL_RenderCopy(renderer, iWantQuitButton, &iWantQuitButtonRectSrc, &iWantQuitButtonRect);
    SDL_RenderCopy(renderer, iWantQuitText, &iWantQuitTextRectSrc, &iWantQuitTextRect);


    // back button
    if(!checkInOut(x_MouseWhere, y_MouseWhere, backButtonRect))
        SDL_RenderCopy(renderer, backButton, &backButtonRectSrc, &backButtonRect);
    else
        SDL_RenderCopy(renderer, backHoverButton, &backHoverButtonRectSrc, &backHoverButtonRect);
    SDL_RenderCopy(renderer, backText, &backTextRectSrc, &backTextRect);

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, backButtonRect)){
        Locator["quit_menu"] = !Locator["quit_menu"];
        Locator["main_menu"] = !Locator["main_menu"];
    }

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, iWantQuitButtonRect)){
        Locator["quit_menu"] = !Locator["quit_menu"];
        main_loop = SDL_FALSE;
    }

}


#endif //BOUNCING_BALL_GAME_WINDOW_H