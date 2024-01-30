#ifndef BOUNCING_BALL_GAME_WINDOW_H
#define BOUNCING_BALL_GAME_WINDOW_H

// rendering balls texture

void initializeBallsTexture() {

    redNormalBallSurface = IMG_Load("assets/Game/Balls/red.png");
    redNormalBall = SDL_CreateTextureFromSurface(renderer, redNormalBallSurface);

    blueNormalBallSurface = IMG_Load("assets/Game/Balls/blue.png");
    blueNormalBall = SDL_CreateTextureFromSurface(renderer, blueNormalBallSurface);

    greenNormalBallSurface = IMG_Load("assets/Game/Balls/green.png");
    greenNormalBall = SDL_CreateTextureFromSurface(renderer, greenNormalBallSurface);

    yellowNormalBallSurface = IMG_Load("assets/Game/Balls/yellow.png");
    yellowNormalBall = SDL_CreateTextureFromSurface(renderer, yellowNormalBallSurface);

    purpleNormalBallSurface = IMG_Load("assets/Game/Balls/purple.png");
    purpleNormalBall = SDL_CreateTextureFromSurface(renderer, purpleNormalBallSurface);

    cyanNormalBallSurface = IMG_Load("assets/Game/Balls/cyan.png");
    cyanNormalBall = SDL_CreateTextureFromSurface(renderer, cyanNormalBallSurface);

    silverNormalBallSurface = IMG_Load("assets/Game/Balls/silver.png");
    silverNormalBall = SDL_CreateTextureFromSurface(renderer, silverNormalBallSurface);

    // locked

    redLockedBallSurface = IMG_Load("assets/Game/Balls/redLock.png");
    redLockedBall = SDL_CreateTextureFromSurface(renderer, redLockedBallSurface);

    blueLockedBallSurface = IMG_Load("assets/Game/Balls/blueLock.png");
    blueLockedBall = SDL_CreateTextureFromSurface(renderer, blueLockedBallSurface);

    greenLockedBallSurface = IMG_Load("assets/Game/Balls/greenLock.png");
    greenLockedBall = SDL_CreateTextureFromSurface(renderer, greenLockedBallSurface);

    yellowLockedBallSurface = IMG_Load("assets/Game/Balls/yellowLock.png");
    yellowLockedBall = SDL_CreateTextureFromSurface(renderer, yellowLockedBallSurface);

    purpleLockedBallSurface = IMG_Load("assets/Game/Balls/purpleLock.png");
    purpleLockedBall = SDL_CreateTextureFromSurface(renderer, purpleLockedBallSurface);

    cyanLockedBallSurface = IMG_Load("assets/Game/Balls/cyanLock.png");
    cyanLockedBall = SDL_CreateTextureFromSurface(renderer, cyanLockedBallSurface);

    // two colors

    blueYellowBallSurface = IMG_Load("assets/Game/Balls/blueYellow.png");
    blueYellowBall = SDL_CreateTextureFromSurface(renderer, blueYellowBallSurface);

    redBlueBallSurface = IMG_Load("assets/Game/Balls/redBlue.png");
    redBlueBall = SDL_CreateTextureFromSurface(renderer, redBlueBallSurface);

    yellowRedBallSurface = IMG_Load("assets/Game/Balls/yellowRed.png");
    yellowRedBall = SDL_CreateTextureFromSurface(renderer, yellowRedBallSurface);

}

void initializeSoundSFX() {
    winningSound = Mix_LoadWAV("assets/SFX/win.wav");
    clickSound = Mix_LoadWAV("assets/SFX/click.wav");
    losingSound = Mix_LoadWAV("assets/SFX/lose.wav");

}

void destroyBallsTexture() {

    SDL_FreeSurface(redNormalBallSurface);
    SDL_DestroyTexture(redNormalBall);

    SDL_FreeSurface(blueNormalBallSurface);
    SDL_DestroyTexture(blueNormalBall);

    SDL_FreeSurface(yellowNormalBallSurface);
    SDL_DestroyTexture(yellowNormalBall);

    SDL_FreeSurface(greenNormalBallSurface);
    SDL_DestroyTexture(greenNormalBall);

    SDL_FreeSurface(cyanNormalBallSurface);
    SDL_DestroyTexture(cyanNormalBall);

    SDL_FreeSurface(purpleNormalBallSurface);
    SDL_DestroyTexture(purpleNormalBall);

    SDL_FreeSurface(silverNormalBallSurface);
    SDL_DestroyTexture(silverNormalBall);

    // locked

    SDL_FreeSurface(redLockedBallSurface);
    SDL_DestroyTexture(redLockedBall);

    SDL_FreeSurface(blueLockedBallSurface);
    SDL_DestroyTexture(blueLockedBall);

    SDL_FreeSurface(yellowLockedBallSurface);
    SDL_DestroyTexture(yellowLockedBall);

    SDL_FreeSurface(greenLockedBallSurface);
    SDL_DestroyTexture(greenLockedBall);

    SDL_FreeSurface(cyanLockedBallSurface);
    SDL_DestroyTexture(cyanLockedBall);

    SDL_FreeSurface(purpleLockedBallSurface);
    SDL_DestroyTexture(purpleLockedBall);

    // two colors

    SDL_FreeSurface(blueYellowBallSurface);
    SDL_DestroyTexture(blueYellowBall);

    SDL_FreeSurface(redBlueBallSurface);
    SDL_DestroyTexture(redBlueBall);

    SDL_FreeSurface(yellowRedBallSurface);
    SDL_DestroyTexture(yellowRedBall);

}

void destroySoundSFX() {
    Mix_FreeChunk(winningSound);
    Mix_FreeChunk(clickSound);
    Mix_FreeChunk(losingSound);
}

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

void inputTextPresent() {
    if (usernameInputBox) {
        SDL_DestroyTexture(usernameInputBox);
        usernameInputBox = NULL;
    }
    usernameInputBoxSurface = TTF_RenderText_Solid(font, inputText.c_str(), BLACK);
    if (usernameInputBoxSurface) {
        usernameInputBox = SDL_CreateTextureFromSurface(renderer, usernameInputBoxSurface);
        usernameInputBoxRect.w = usernameInputBoxSurface->w;
        usernameInputBoxRect.h = usernameInputBoxSurface->h;
        SDL_FreeSurface(usernameInputBoxSurface);
        usernameInputBoxSurface = NULL;
    }
}

void initializeButtonsAndBG() {

    bgSurface = IMG_Load(th.bg);
    bg = SDL_CreateTextureFromSurface(renderer, bgSurface);

    bgRect.x = 0;
    bgRect.y = 0;
    bgRect.w = bgSurface->w;
    bgRect.h = bgSurface->h;

    logoSurface = IMG_Load(th.logo);
    logo = SDL_CreateTextureFromSurface(renderer, logoSurface);

    logoRectSrc.x = 0;
    logoRectSrc.y = 0;
    logoRectSrc.w = logoSurface->w;
    logoRectSrc.h = logoSurface->h;

    logoRect.x = 0;
    logoRect.y = 0;
    logoRect.w = logoSurface->w * 0.7;
    logoRect.h = logoSurface->h * 0.7;

    //setting button
    imageRender(settingButtonSurface, settingButton,settingButtonRectSrc,
                settingButtonRect, 10, 660, 2, "assets/UiUx/setting.svg");

    //exit button
    imageRender(exitButtonSurface, exitButton,exitButtonRectSrc,
                exitButtonRect, 550, 660, 2, "assets/UiUx/exit.svg");

    //music off button
    imageRender(musicOffButtonSurface, musicOffButton,musicOffButtonRectSrc,
                musicOffButtonRect, 60, 120, 2, "assets/UiUx/music_off.svg");

    //music on button
    imageRender(musicOnButtonSurface, musicOnButton,musicOnButtonRectSrc,
                musicOnButtonRect, 60, 120, 2, "assets/UiUx/music_on.svg");

    //volume off button
    imageRender(volumeOffButtonSurface, volumeOffButton,volumeOffButtonRectSrc,
                volumeOffButtonRect, 60, 60, 2, "assets/UiUx/volume_off.svg");

    //volume on button
    imageRender(volumeOnButtonSurface, volumeOnButton,volumeOnButtonRectSrc,
                volumeOnButtonRect, 60, 60, 2, "assets/UiUx/volume_on.svg");

    //mainMenu button
    imageRender(mainMenuButtonSurface, mainMenuButton,mainMenuButtonRectSrc,
                mainMenuButtonRect, 300, 500, 0.3, th.button);
    imageRender(mainMenuHoverButtonSurface, mainMenuHoverButton,mainMenuHoverButtonRectSrc,
                mainMenuHoverButtonRect, 300, 500, 0.3, th.buttonHover);
    textRender(mainMenuTextSurface, mainMenuText, mainMenuTextRectSrc,
               mainMenuTextRect, 363, 564, 0.5, "main menu");

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

    // login button
    imageRender(logInButtonSurface, logInButton,logInButtonRectSrc,
                logInButtonRect, 100, 500, 0.3, th.button);
    imageRender(logInHoverButtonSurface, logInHoverButton,logInHoverButtonRectSrc,
                logInHoverButtonRect, 100, 500, 0.3, th.buttonHover);
    textRender(logInTextSurface, logInText, logInTextRectSrc,
               logInTextRect, 163, 564, 0.5, "Login");

    //sign in button
    imageRender(signInButtonSurface, signInButton,signInButtonRectSrc,
                signInButtonRect, 300, 500, 0.3, th.button);
    imageRender(signInHoverButtonSurface, signInHoverButton,signInHoverButtonRectSrc,
                signInHoverButtonRect, 300, 500, 0.3, th.buttonHover);
    textRender(signInTextSurface, signInText, signInTextRectSrc,
               signInTextRect, 363, 564, 0.5, "Sign in");

    //log out button
    imageRender(logOutButtonSurface, logOutButton,logOutButtonRectSrc,
                logOutButtonRect, 300, 500, 0.3, th.button);
    textRender(logInTextSurface, logInText, logInTextRectSrc,
               logOutTextRect, 363, 564, 0.5, "Logout");

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

    //Jungle theme button
    theme temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess = Jungle;
    imageRender(jungleThemeButtonSurface, jungleThemeButton,jungleThemeButtonRectSrc,
                jungleThemeButtonRect, 200, 280, 0.3, temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess.button);
    imageRender(jungleThemeHoverButtonSurface, jungleThemeHoverButton,jungleThemeHoverButtonRectSrc,
                jungleThemeHoverButtonRect, 200, 280, 0.3, temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess.buttonHover);
    textRender(jungleThemeTextSurface, jungleThemeText, jungleThemeTextRectSrc,
               jungleThemeTextRect, 260, 345, 0.5, "Jungle");

    //Ocean theme button
    temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess = Ocean;
    imageRender(oceanThemeButtonSurface, oceanThemeButton,oceanThemeButtonRectSrc,
                oceanThemeButtonRect, 200, 380, 0.2, temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess.button);
    imageRender(oceanThemeHoverButtonSurface, oceanThemeHoverButton,oceanThemeHoverButtonRectSrc,
                oceanThemeHoverButtonRect, 200, 380, 0.2, temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess.buttonHover);
    textRender(oceanThemeTextSurface, oceanThemeText, oceanThemeTextRectSrc,
               oceanThemeTextRect, 260, 445, 0.5, "Ocean");

    //Space theme button
    temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess = Space;
    imageRender(spaceThemeButtonSurface, spaceThemeButton,spaceThemeButtonRectSrc,
                spaceThemeButtonRect, 200, 480, 0.3, temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess.button);
    imageRender(spaceThemeHoverButtonSurface, spaceThemeHoverButton,spaceThemeHoverButtonRectSrc,
                spaceThemeHoverButtonRect, 200, 480, 0.3, temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess.buttonHover);
    textRender(spaceThemeTextSurface, spaceThemeText, spaceThemeTextRectSrc,
               spaceThemeTextRect, 260, 545, 0.5, "Space");

}

void destroyButtonsAndBG() {

    SDL_FreeSurface(bgSurface);
    SDL_DestroyTexture(bg);

    SDL_FreeSurface(logoSurface);
    SDL_DestroyTexture(logo);

    SDL_FreeSurface(settingButtonSurface);
    SDL_DestroyTexture(settingButton);

    SDL_FreeSurface(exitButtonSurface);
    SDL_DestroyTexture(exitButton);

    SDL_FreeSurface(musicOnButtonSurface);
    SDL_DestroyTexture(musicOnButton);

    SDL_FreeSurface(musicOffButtonSurface);
    SDL_DestroyTexture(musicOffButton);

    SDL_FreeSurface(volumeOnButtonSurface);
    SDL_DestroyTexture(volumeOnButton);

    SDL_FreeSurface(volumeOffButtonSurface);
    SDL_DestroyTexture(volumeOffButton);

    SDL_FreeSurface(mainMenuButtonSurface);
    SDL_DestroyTexture(mainMenuButton);
    SDL_FreeSurface(mainMenuHoverButtonSurface);
    SDL_DestroyTexture(mainMenuHoverButton);
    SDL_FreeSurface(mainMenuTextSurface);
    SDL_DestroyTexture(mainMenuText);

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

    SDL_FreeSurface(logInButtonSurface);
    SDL_DestroyTexture(logInButton);
    SDL_FreeSurface(logInHoverButtonSurface);
    SDL_DestroyTexture(logInHoverButton);
    SDL_FreeSurface(logInTextSurface);
    SDL_DestroyTexture(logInText);

    SDL_FreeSurface(signInButtonSurface);
    SDL_DestroyTexture(signInButton);
    SDL_FreeSurface(signInHoverButtonSurface);
    SDL_DestroyTexture(signInHoverButton);
    SDL_FreeSurface(signInTextSurface);
    SDL_DestroyTexture(signInText);

    SDL_FreeSurface(logOutButtonSurface);
    SDL_DestroyTexture(logOutButton);
    SDL_FreeSurface(logOutTextSurface);
    SDL_DestroyTexture(logOutText);

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

    SDL_FreeSurface(jungleThemeButtonSurface);
    SDL_DestroyTexture(jungleThemeButton);
    SDL_FreeSurface(jungleThemeHoverButtonSurface);
    SDL_DestroyTexture(jungleThemeHoverButton);
    SDL_FreeSurface(jungleThemeTextSurface);
    SDL_DestroyTexture(jungleThemeText);

    SDL_FreeSurface(oceanThemeButtonSurface);
    SDL_DestroyTexture(oceanThemeButton);
    SDL_FreeSurface(oceanThemeHoverButtonSurface);
    SDL_DestroyTexture(oceanThemeHoverButton);
    SDL_FreeSurface(oceanThemeTextSurface);
    SDL_DestroyTexture(oceanThemeText);


    SDL_FreeSurface(spaceThemeButtonSurface);
    SDL_DestroyTexture(spaceThemeButton);
    SDL_FreeSurface(spaceThemeHoverButtonSurface);
    SDL_DestroyTexture(spaceThemeHoverButton);
    SDL_FreeSurface(spaceThemeTextSurface);
    SDL_DestroyTexture(spaceThemeText);


}

void reInitialingSoundMusic() {
    soundInsideRect.w = soundVolume;
    #ifdef _WIN32
        Mix_Volume(-1, soundVolume * 128 / 100);
    #else
        Mix_VolumeChunk(winningSound, soundVolume * 128 / 100);
        Mix_VolumeChunk(losingSound, soundVolume * 128 / 100);
        Mix_VolumeChunk(clickSound, soundVolume * 128 / 100);
    #endif



    musicInsideRect.w = musicVolume;
    Mix_VolumeMusic(musicVolume * 128 / 100);
}

void themeChanger(theme newTheme) {
    destroyButtonsAndBG();
    Mix_FreeMusic(music);
    TTF_CloseFont(font);

    th = newTheme;
    font = TTF_OpenFont(th.fontLoc, th.fontSize);
    initializeButtonsAndBG();
    music = Mix_LoadMUS(th.music);
    Mix_PlayMusic(music, -1);
    inputTextPresent();

}

// Menus

void Main_Menu(bool &MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator) {

    // initialing and Drawing background

    SDL_SetRenderDrawColor(renderer, th.MainColor.r, th.MainColor.g, th.MainColor.b, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, bg, NULL, &bgRect);

    // logo

    SDL_RenderCopy(renderer, logo, &logoRectSrc, &logoRect);


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

    // login button
    if(!checkInOut(x_MouseWhere, y_MouseWhere, logInButtonRect))
        SDL_RenderCopy(renderer, logInButton, &logInButtonRectSrc, &logInButtonRect);
    else
        SDL_RenderCopy(renderer, logInHoverButton, &logInHoverButtonRectSrc, &logInHoverButtonRect);
    SDL_RenderCopy(renderer, logInText, &logInTextRectSrc, &logInTextRect);

    // sign in button
    if(!checkInOut(x_MouseWhere, y_MouseWhere, signInButtonRect))
        SDL_RenderCopy(renderer, signInButton, &signInButtonRectSrc, &signInButtonRect);
    else
        SDL_RenderCopy(renderer, signInHoverButton, &signInHoverButtonRectSrc, &signInHoverButtonRect);
    SDL_RenderCopy(renderer, signInText, &signInTextRectSrc, &signInTextRect);

//    // logout button
//    SDL_RenderCopy(renderer, logOutButton, &logOutButtonRectSrc, &logOutButtonRect);
//    SDL_RenderCopy(renderer, logOutText, &logOutTextRectSrc, &logOutTextRect);


    // setting button
    SDL_RenderCopy(renderer, settingButton, &settingButtonRectSrc, &settingButtonRect);

    // exit button
    SDL_RenderCopy(renderer, exitButton, &exitButtonRectSrc, &exitButtonRect);


    // mouse click actions

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, startButtonRect)){
        Locator["username_getter"] = !Locator["username_getter"];
        Locator["main_menu"] = !Locator["main_menu"];
        inputText = "Enter Your Name";
        inputTextPresent();
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

void username_getter(bool &MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator) {

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, bg, NULL, &bgRect);

    //username getter
    SDL_SetRenderDrawColor(renderer, WHITE.r, WHITE.g, WHITE.b, 255);
    SDL_Rect temp = {50, 100, 500, 50};
    SDL_RenderFillRect(renderer, &temp);
    SDL_SetRenderDrawColor(renderer, th.MainColor.r, th.MainColor.g, th.MainColor.b, 255);
    //SDL_RenderDrawRect(renderer, &usernameInputBoxRect);
    SDL_RenderCopy(renderer, usernameInputBox, NULL, &usernameInputBoxRect);

    // back button
    if(!checkInOut(x_MouseWhere, y_MouseWhere, backButtonRect))
        SDL_RenderCopy(renderer, backButton, &backButtonRectSrc, &backButtonRect);
    else
        SDL_RenderCopy(renderer, backHoverButton, &backHoverButtonRectSrc, &backHoverButtonRect);
    SDL_RenderCopy(renderer, backText, &backTextRectSrc, &backTextRect);


    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, backButtonRect)) {
        Locator["username_getter"] = !Locator["username_getter"];
        Locator["main_menu"] = !Locator["main_menu"];
        inputText = "Enter Your Name";
    }

    if(MouseClicked)
        MouseClicked = !MouseClicked;


}

void start_Menu(bool &MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator, GAME_INF &gameInfo) {

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
        gameInfo.mode = "normal";
    }

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, timedModeButtonRect)) {
        Locator["start_menu"] = !Locator["start_menu"];
        Locator["level_selector"] = !Locator["level_selector"];
        gameInfo.mode = "timed";
    }

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, randomModeButtonRect)) {
        Locator["start_menu"] = !Locator["start_menu"];
        Locator["game"] = !Locator["game"];
        gameInfo.mode = "random";
    }

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, infiniteModeButtonRect)) {
        Locator["start_menu"] = !Locator["start_menu"];
        Locator["game"] = !Locator["game"];
        gameInfo.mode = "infinite";
    }

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, backButtonRect)) {
        Locator["start_menu"] = !Locator["start_menu"];
        Locator["main_menu"] = !Locator["main_menu"];
    }

    if(MouseClicked)
        MouseClicked = !MouseClicked;


}

void level_selector(bool &MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator, GAME_INF &gameInfo) {

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
        Locator["game"] = !Locator["game"];
        gameInfo.level = 1;
    }

    if (MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, level2ButtonRect)) {
        Locator["level_selector"] = !Locator["level_selector"];
        Locator["game"] = !Locator["game"];
        gameInfo.level = 2;
    }

    if (MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, level3ButtonRect)) {
        Locator["level_selector"] = !Locator["level_selector"];
        Locator["game"] = !Locator["game"];
        gameInfo.level = 3;
    }

    if (MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, level4ButtonRect)) {
        Locator["level_selector"] = !Locator["level_selector"];
        Locator["game"] = !Locator["game"];
        gameInfo.level = 4;
    }

    if (MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, level5ButtonRect)) {
        Locator["level_selector"] = !Locator["level_selector"];
        Locator["game"] = !Locator["game"];
        gameInfo.level = 5;
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

    // initialing and Drawing background

    SDL_SetRenderDrawColor(renderer, th.SecColor.r, th.SecColor.g, th.SecColor.b, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, bg, NULL, &bgRect);

    // setting box
    SDL_RenderFillRect(renderer, &settingBox);

    // volume off on button
    if(soundVolume)
        SDL_RenderCopy(renderer, volumeOnButton, &volumeOnButtonRectSrc, &volumeOnButtonRect);
    else
        SDL_RenderCopy(renderer, volumeOffButton, &volumeOffButtonRectSrc, &volumeOffButtonRect);

    // music off on button
    if(musicVolume)
        SDL_RenderCopy(renderer, musicOnButton, &musicOnButtonRectSrc, &musicOnButtonRect);
    else
        SDL_RenderCopy(renderer, musicOffButton, &musicOffButtonRectSrc, &musicOffButtonRect);

    // bars
    SDL_SetRenderDrawColor(renderer, WHITE.r, WHITE.g, WHITE.b, 255);
    SDL_RenderFillRect(renderer, &soundOutsideRect) ;
    SDL_RenderFillRect(renderer, &musicOutsideRect) ;

    SDL_SetRenderDrawColor(renderer, th.MainColor.r, th.MainColor.g, th.MainColor.b, 255);
    SDL_RenderFillRect(renderer, &soundInsideRect) ;
    SDL_RenderFillRect(renderer, &musicInsideRect) ;

    // jungle theme button
    if(!checkInOut(x_MouseWhere, y_MouseWhere, jungleThemeButtonRect))
        SDL_RenderCopy(renderer, jungleThemeButton, &jungleThemeButtonRectSrc, &jungleThemeButtonRect);
    else
        SDL_RenderCopy(renderer, jungleThemeHoverButton, &jungleThemeHoverButtonRectSrc, &jungleThemeHoverButtonRect);
    SDL_RenderCopy(renderer, jungleThemeText, &jungleThemeTextRectSrc, &jungleThemeTextRect);

    // ocean theme button
    if(!checkInOut(x_MouseWhere, y_MouseWhere, oceanThemeButtonRect))
        SDL_RenderCopy(renderer, oceanThemeButton, &oceanThemeButtonRectSrc, &oceanThemeButtonRect);
    else
        SDL_RenderCopy(renderer, oceanThemeHoverButton, &oceanThemeHoverButtonRectSrc, &oceanThemeHoverButtonRect);
    SDL_RenderCopy(renderer, oceanThemeText, &oceanThemeTextRectSrc, &oceanThemeTextRect);

    // space theme button
    if(!checkInOut(x_MouseWhere, y_MouseWhere, spaceThemeButtonRect))
        SDL_RenderCopy(renderer, spaceThemeButton, &spaceThemeButtonRectSrc, &spaceThemeButtonRect);
    else
        SDL_RenderCopy(renderer, spaceThemeHoverButton, &spaceThemeHoverButtonRectSrc, &spaceThemeHoverButtonRect);
    SDL_RenderCopy(renderer, spaceThemeText, &spaceThemeTextRectSrc, &spaceThemeTextRect);

    // back button
    if(!checkInOut(x_MouseWhere, y_MouseWhere, backButtonRect))
        SDL_RenderCopy(renderer, backButton, &backButtonRectSrc, &backButtonRect);
    else
        SDL_RenderCopy(renderer, backHoverButton, &backHoverButtonRectSrc, &backHoverButtonRect);
    SDL_RenderCopy(renderer, backText, &backTextRectSrc, &backTextRect);


    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, volumeOnButtonRect)){
        if(soundVolume) soundVolume = 0;
        else soundVolume = 100;
        reInitialingSoundMusic();
    }

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, musicOnButtonRect)){
        if(musicVolume) musicVolume = 0;
        else musicVolume = 100;
        reInitialingSoundMusic();
    }

    if (MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, soundOutsideRect)) {
        soundVolume = (x_MouseClicked - soundOutsideRect.x);
        reInitialingSoundMusic();
    }

    if (MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, musicOutsideRect)) {
        musicVolume = (x_MouseClicked - musicOutsideRect.x);
        reInitialingSoundMusic();
    }

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, jungleThemeButtonRect)) {
        themeChanger(Jungle);
    }
    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, oceanThemeButtonRect)) {
        themeChanger(Ocean);
    }
    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, spaceThemeButtonRect)) {
        themeChanger(Space);
    }

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, backButtonRect)) {
        Locator["setting_menu"] = !Locator["setting_menu"];
        Locator["main_menu"] = !Locator["main_menu"];
        settingWriter();
    }


    if(MouseClicked)
        MouseClicked = !MouseClicked;


}

void quitMenu(bool &MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator) {

    // initialing and Drawing background

    SDL_SetRenderDrawColor(renderer, th.SecColor.r, th.SecColor.g, th.SecColor.b, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, bg, NULL, &bgRect);

    // question box
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