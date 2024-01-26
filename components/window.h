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
                backButtonRect, 200, 580, 0.3, th.button);
    imageRender(backHoverButtonSurface, backHoverButton,backHoverButtonRectSrc,
                backHoverButtonRect, 200, 580, 0.3, th.buttonHover);
    textRender(backTextSurface, backText, backTextRectSrc,
               backTextRect, 260, 645, 0.5, "Back");

    //quit menu
    textRender(DoYouWantToQuitTextSurface, DoYouWantToQuitText, DoYouWantToQuitTextRectSrc,
               DoYouWantToQuitTextRect, 70, 240, 0.5, "Do you Really want to quit the Game? :(");
    imageRender(iWantQuitButtonSurface, iWantQuitButton,iWantQuitButtonRectSrc,
                iWantQuitButtonRect, 200, 260, 0.3, th.buttonQuit);
    textRender(iWantQuitTextSurface, iWantQuitText, iWantQuitTextRectSrc,
               iWantQuitTextRect, 240, 305, 1, "Yes!");

    //normal mode menu
    imageRender(normalModeButtonSurface, normalModeButton,normalModeButtonRectSrc,
                normalModeButtonRect, 100, 200, 0.3, th.button);
    imageRender(normalModeHoverButtonSurface, normalModeHoverButton,normalModeHoverButtonRectSrc,
                normalModeHoverButtonRect, 100, 200, 0.3, th.buttonHover);
    textRender(normalModeTextSurface, normalModeText, normalModeTextRectSrc,
               normalModeTextRect, 163, 270, 0.5, "Normal");

    //timed mode menu
    imageRender(timedModeButtonSurface, timedModeButton,timedModeButtonRectSrc,
                timedModeButtonRect, 300, 200, 0.3, th.button);
    imageRender(timedModeHoverButtonSurface, timedModeHoverButton,timedModeHoverButtonRectSrc,
                timedModeHoverButtonRect, 300, 200, 0.3, th.buttonHover);
    textRender(timedModeTextSurface, timedModeText, timedModeTextRectSrc,
               timedModeTextRect, 345, 270, 0.5, "Timed");

    //random mode menu
    imageRender(randomModeButtonSurface, randomModeButton,randomModeButtonRectSrc,
                randomModeButtonRect, 100, 400, 0.3, th.button);
    imageRender(randomModeHoverButtonSurface, randomModeHoverButton, randomModeHoverButtonRectSrc,
                randomModeHoverButtonRect, 100, 400, 0.3, th.buttonHover);
    textRender(randomModeTextSurface, randomModeText, randomModeTextRectSrc,
               randomModeTextRect, 163, 470, 0.5, "Random");

    //infinite mode menu
    imageRender(infiniteModeButtonSurface, infiniteModeButton,infiniteModeButtonRectSrc,
                infiniteModeButtonRect, 300, 400, 0.3, th.button);
    imageRender(infiniteModeHoverButtonSurface, infiniteModeHoverButton,infiniteModeHoverButtonRectSrc,
                infiniteModeHoverButtonRect, 300, 400, 0.3, th.buttonHover);
    textRender(infiniteModeTextSurface, infiniteModeText, infiniteModeTextRectSrc,
               infiniteModeTextRect, 345, 470, 0.5, "Infinite");

    //level 1 button
    imageRender(level1ButtonSurface, level1Button,level1ButtonRectSrc,
                level1ButtonRect, 200, 80, 0.3, th.button);
    imageRender(level1HoverButtonSurface, level1HoverButton,level1HoverButtonRectSrc,
                level1HoverButtonRect, 200, 80, 0.3, th.buttonHover);
    textRender(level1TextSurface, level1Text, level1TextRectSrc,
               level1TextRect, 260, 145, 0.5, "level 1");

    //level 2 button
    imageRender(level2ButtonSurface, level2Button,level2ButtonRectSrc,
                level2ButtonRect, 200, 180, 0.3, th.button);
    imageRender(level2HoverButtonSurface, level2HoverButton,level2HoverButtonRectSrc,
                level2HoverButtonRect, 200, 180, 0.3, th.buttonHover);
    textRender(level2TextSurface, level2Text, level2TextRectSrc,
               level2TextRect, 260, 245, 0.5, "level 2");

    //level 3 button
    imageRender(level3ButtonSurface, level3Button,level3ButtonRectSrc,
                level3ButtonRect, 200, 280, 0.3, th.button);
    imageRender(level3HoverButtonSurface, level3HoverButton,level3HoverButtonRectSrc,
                level3HoverButtonRect, 200, 280, 0.3, th.buttonHover);
    textRender(level3TextSurface, level3Text, level3TextRectSrc,
               level3TextRect, 260, 345, 0.5, "level 3");

    //level 4 button
    imageRender(level4ButtonSurface, level4Button,level4ButtonRectSrc,
                level4ButtonRect, 200, 380, 0.3, th.button);
    imageRender(level4HoverButtonSurface, level4HoverButton,level4HoverButtonRectSrc,
                level4HoverButtonRect, 200, 380, 0.3, th.buttonHover);
    textRender(level4TextSurface, level4Text, level4TextRectSrc,
               level4TextRect, 260, 445, 0.5, "level 4");

    //level 5 button
    imageRender(level5ButtonSurface, level5Button,level5ButtonRectSrc,
                level5ButtonRect, 200, 480, 0.3, th.button);
    imageRender(level5HoverButtonSurface, level5HoverButton,level5HoverButtonRectSrc,
                level5HoverButtonRect, 200, 480, 0.3, th.buttonHover);
    textRender(level5TextSurface, level5Text, level5TextRectSrc,
               level5TextRect, 260, 545, 0.5, "level 5");

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

    SDL_FreeSurface(normalModeButtonSurface);
    SDL_DestroyTexture(normalModeButton);
    SDL_FreeSurface(normalModeHoverButtonSurface);
    SDL_DestroyTexture(normalModeHoverButton);
    SDL_FreeSurface(normalModeTextSurface);
    SDL_DestroyTexture(normalModeText);

    SDL_FreeSurface(timedModeButtonSurface);
    SDL_DestroyTexture(timedModeButton);
    SDL_FreeSurface(timedModeHoverButtonSurface);
    SDL_DestroyTexture(timedModeHoverButton);
    SDL_FreeSurface(timedModeTextSurface);
    SDL_DestroyTexture(timedModeText);

    SDL_FreeSurface(randomModeButtonSurface);
    SDL_DestroyTexture(randomModeButton);
    SDL_FreeSurface(randomModeHoverButtonSurface);
    SDL_DestroyTexture(randomModeHoverButton);
    SDL_FreeSurface(randomModeTextSurface);
    SDL_DestroyTexture(randomModeText);

    SDL_FreeSurface(infiniteModeButtonSurface);
    SDL_DestroyTexture(infiniteModeButton);
    SDL_FreeSurface(infiniteModeHoverButtonSurface);
    SDL_DestroyTexture(infiniteModeHoverButton);
    SDL_FreeSurface(infiniteModeTextSurface);
    SDL_DestroyTexture(infiniteModeText);

    SDL_FreeSurface(level1ButtonSurface);
    SDL_DestroyTexture(level1Button);
    SDL_FreeSurface(level1HoverButtonSurface);
    SDL_DestroyTexture(level1HoverButton);
    SDL_FreeSurface(level1TextSurface);
    SDL_DestroyTexture(level1Text);

    SDL_FreeSurface(level2ButtonSurface);
    SDL_DestroyTexture(level2Button);
    SDL_FreeSurface(level2HoverButtonSurface);
    SDL_DestroyTexture(level2HoverButton);
    SDL_FreeSurface(level2TextSurface);
    SDL_DestroyTexture(level2Text);

    SDL_FreeSurface(level3ButtonSurface);
    SDL_DestroyTexture(level3Button);
    SDL_FreeSurface(level3HoverButtonSurface);
    SDL_DestroyTexture(level3HoverButton);
    SDL_FreeSurface(level3TextSurface);
    SDL_DestroyTexture(level3Text);

    SDL_FreeSurface(level4ButtonSurface);
    SDL_DestroyTexture(level4Button);
    SDL_FreeSurface(level4HoverButtonSurface);
    SDL_DestroyTexture(level4HoverButton);
    SDL_FreeSurface(level4TextSurface);
    SDL_DestroyTexture(level4Text);

    SDL_FreeSurface(level5ButtonSurface);
    SDL_DestroyTexture(level5Button);
    SDL_FreeSurface(level5HoverButtonSurface);
    SDL_DestroyTexture(level5HoverButton);
    SDL_FreeSurface(level5TextSurface);
    SDL_DestroyTexture(level5Text);

}

// Menus

void Main_Menu(bool &MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator) {

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
        Locator["start_menu"] = !Locator["start_menu"];
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
    if(MouseClicked)
        MouseClicked = !MouseClicked;


}

void start_Menu(bool &MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator, bool &normal_or_timed) {

    // initialing and Drawing background

    SDL_SetRenderDrawColor(renderer, th.MainColor.r, th.MainColor.g, th.MainColor.b, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, bg, NULL, &bgRect);

    // normal mode button
    if(!checkInOut(x_MouseWhere, y_MouseWhere, normalModeButtonRect))
        SDL_RenderCopy(renderer, normalModeButton, &normalModeButtonRectSrc, &normalModeButtonRect);
    else
        SDL_RenderCopy(renderer, normalModeHoverButton, &normalModeHoverButtonRectSrc, &normalModeHoverButtonRect);
    SDL_RenderCopy(renderer, normalModeText, &normalModeTextRectSrc, &normalModeTextRect);

    // timed mode button
    if(!checkInOut(x_MouseWhere, y_MouseWhere, timedModeButtonRect))
        SDL_RenderCopy(renderer, timedModeButton, &timedModeButtonRectSrc, &timedModeButtonRect);
    else
        SDL_RenderCopy(renderer, timedModeHoverButton, &timedModeHoverButtonRectSrc, &timedModeHoverButtonRect);
    SDL_RenderCopy(renderer, timedModeText, &timedModeTextRectSrc, &timedModeTextRect);

    // random mode button
    if(!checkInOut(x_MouseWhere, y_MouseWhere, randomModeButtonRect))
        SDL_RenderCopy(renderer, randomModeButton, &randomModeButtonRectSrc, &randomModeButtonRect);
    else
        SDL_RenderCopy(renderer, randomModeHoverButton, &randomModeHoverButtonRectSrc, &randomModeHoverButtonRect);
    SDL_RenderCopy(renderer, randomModeText, &randomModeTextRectSrc, &randomModeTextRect);

    // infinite mode button
    if(!checkInOut(x_MouseWhere, y_MouseWhere, infiniteModeButtonRect))
        SDL_RenderCopy(renderer, infiniteModeButton, &infiniteModeButtonRectSrc, &infiniteModeButtonRect);
    else
        SDL_RenderCopy(renderer, infiniteModeHoverButton, &infiniteModeHoverButtonRectSrc, &infiniteModeHoverButtonRect);
    SDL_RenderCopy(renderer, infiniteModeText, &infiniteModeTextRectSrc, &infiniteModeTextRect);

    // back button
    if(!checkInOut(x_MouseWhere, y_MouseWhere, backButtonRect))
        SDL_RenderCopy(renderer, backButton, &backButtonRectSrc, &backButtonRect);
    else
        SDL_RenderCopy(renderer, backHoverButton, &backHoverButtonRectSrc, &backHoverButtonRect);
    SDL_RenderCopy(renderer, backText, &backTextRectSrc, &backTextRect);


    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, normalModeButtonRect)) {
        Locator["start_menu"] = !Locator["start_menu"];
        Locator["level_selector"] = !Locator["level_selector"];
        normal_or_timed = true;
    }

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, timedModeButtonRect)) {
        Locator["start_menu"] = !Locator["start_menu"];
        Locator["level_selector"] = !Locator["level_selector"];
        normal_or_timed = false;
    }

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, randomModeButtonRect)) {
        Locator["start_menu"] = !Locator["start_menu"];
        //Locator["random_mode"] = !Locator["random_mode"];
        Locator["main_menu"] = !Locator["main_menu"];
    }

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, infiniteModeButtonRect)) {
        Locator["start_menu"] = !Locator["start_menu"];
        //Locator["infinite_mode"] = !Locator["infinite_mode"];
        Locator["main_menu"] = !Locator["main_menu"];
    }

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, backButtonRect)) {
        Locator["start_menu"] = !Locator["start_menu"];
        Locator["main_menu"] = !Locator["main_menu"];
    }

    if(MouseClicked)
        MouseClicked = !MouseClicked;


}

void level_selector(bool &MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator, int &levelNum) {

    // initialing and Drawing background

    SDL_SetRenderDrawColor(renderer, th.MainColor.r, th.MainColor.g, th.MainColor.b, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, bg, NULL, &bgRect);


    // level1 button
    if (!checkInOut(x_MouseWhere, y_MouseWhere, level1ButtonRect))
        SDL_RenderCopy(renderer, level1Button, &level1ButtonRectSrc, &level1ButtonRect);
    else
        SDL_RenderCopy(renderer, level1HoverButton, &level1HoverButtonRectSrc, &level1HoverButtonRect);
    SDL_RenderCopy(renderer, level1Text, &level1TextRectSrc, &level1TextRect);

    // level2 button
    if (!checkInOut(x_MouseWhere, y_MouseWhere, level2ButtonRect))
        SDL_RenderCopy(renderer, level2Button, &level2ButtonRectSrc, &level2ButtonRect);
    else
        SDL_RenderCopy(renderer, level2HoverButton, &level2HoverButtonRectSrc, &level2HoverButtonRect);
    SDL_RenderCopy(renderer, level2Text, &level2TextRectSrc, &level2TextRect);

    // level3 button
    if (!checkInOut(x_MouseWhere, y_MouseWhere, level3ButtonRect))
        SDL_RenderCopy(renderer, level3Button, &level3ButtonRectSrc, &level3ButtonRect);
    else
        SDL_RenderCopy(renderer, level3HoverButton, &level3HoverButtonRectSrc, &level3HoverButtonRect);
    SDL_RenderCopy(renderer, level3Text, &level3TextRectSrc, &level3TextRect);

    // level4 button
    if (!checkInOut(x_MouseWhere, y_MouseWhere, level4ButtonRect))
        SDL_RenderCopy(renderer, level4Button, &level4ButtonRectSrc, &level4ButtonRect);
    else
        SDL_RenderCopy(renderer, level4HoverButton, &level4HoverButtonRectSrc, &level4HoverButtonRect);
    SDL_RenderCopy(renderer, level4Text, &level4TextRectSrc, &level4TextRect);

    // level5 button
    if (!checkInOut(x_MouseWhere, y_MouseWhere, level5ButtonRect))
        SDL_RenderCopy(renderer, level5Button, &level5ButtonRectSrc, &level5ButtonRect);
    else
        SDL_RenderCopy(renderer, level5HoverButton, &level5HoverButtonRectSrc, &level5HoverButtonRect);
    SDL_RenderCopy(renderer, level5Text, &level5TextRectSrc, &level5TextRect);


    // back button
    if (!checkInOut(x_MouseWhere, y_MouseWhere, backButtonRect))
        SDL_RenderCopy(renderer, backButton, &backButtonRectSrc, &backButtonRect);
    else
        SDL_RenderCopy(renderer, backHoverButton, &backHoverButtonRectSrc, &backHoverButtonRect);
    SDL_RenderCopy(renderer, backText, &backTextRectSrc, &backTextRect);


    if (MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, level1ButtonRect)) {
        Locator["level_selector"] = !Locator["level_selector"];
        levelNum = 1;
    }

    if (MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, level2ButtonRect)) {
        Locator["level_selector"] = !Locator["level_selector"];
        levelNum = 2;
    }

    if (MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, level3ButtonRect)) {
        Locator["level_selector"] = !Locator["level_selector"];
        levelNum = 3;
    }

    if (MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, level4ButtonRect)) {
        Locator["level_selector"] = !Locator["level_selector"];
        levelNum = 4;
    }

    if (MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, level5ButtonRect)) {
        Locator["level_selector"] = !Locator["level_selector"];
        levelNum = 5;
    }

    if (MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, backButtonRect)) {
        Locator["start_menu"] = !Locator["start_menu"];
        Locator["level_selector"] = !Locator["level_selector"];
    }

    if(MouseClicked)
        MouseClicked = !MouseClicked;

}

void leaderboard(bool &MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator) {

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

    if(MouseClicked)
        MouseClicked = !MouseClicked;


}

void settingMenu(bool &MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator) {

}

void quitMenu(bool &MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator) {

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

    if(MouseClicked)
        MouseClicked = !MouseClicked;


}


#endif //BOUNCING_BALL_GAME_WINDOW_H