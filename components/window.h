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

    // multi color

    multiColorBallSurface = IMG_Load("assets/Game/Balls/multiColor.png");
    multiColorBall = SDL_CreateTextureFromSurface(renderer, multiColorBallSurface);

    // ice ball

    iceBallSurface = IMG_Load("assets/Game/Balls/ice.png");
    iceBall = SDL_CreateTextureFromSurface(renderer, iceBallSurface);

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

    SDL_FreeSurface(multiColorBallSurface);
    SDL_DestroyTexture(multiColorBall);

    SDL_FreeSurface(iceBallSurface);
    SDL_DestroyTexture(iceBall);

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

    //cout << text << " w: " << src.w << " h: " << src.h << endl;
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

    logoRect.x = 108;
    logoRect.y = 0;
    logoRect.w = logoSurface->w * 0.75;
    logoRect.h = logoSurface->h * 0.75;

    //setting button
    imageRender(settingButtonSurface, settingButton,settingButtonRectSrc,
                settingButtonRect, 10, 638, 3, "assets/UiUx/setting.svg");

    //exit button
    imageRender(exitButtonSurface, exitButton,exitButtonRectSrc,
                exitButtonRect, 518, 638, 3, "assets/UiUx/exit.svg");

    //music off button
    imageRender(musicOffButtonSurface, musicOffButton,musicOffButtonRectSrc,
                musicOffButtonRect, settingBox.x+10, 120, 2, "assets/UiUx/music_off.svg");

    //music on button
    imageRender(musicOnButtonSurface, musicOnButton,musicOnButtonRectSrc,
                musicOnButtonRect, settingBox.x+10, 120, 2, "assets/UiUx/music_on.svg");

    //volume off button
    imageRender(volumeOffButtonSurface, volumeOffButton,volumeOffButtonRectSrc,
                volumeOffButtonRect, settingBox.x+10, 60, 2, "assets/UiUx/volume_off.svg");

    //volume on button
    imageRender(volumeOnButtonSurface, volumeOnButton,volumeOnButtonRectSrc,
                volumeOnButtonRect, settingBox.x+10, 60, 2, "assets/UiUx/volume_on.svg");

    //start button
    imageRender(startButtonSurface, startButton,startButtonRectSrc,
                startButtonRect, th.loc[0], th.loc[1], th.sizeMultiplier, th.button);
    imageRender(startHoverButtonSurface, startHoverButton,startHoverButtonRectSrc,
                startHoverButtonRect, th.loc[0], th.loc[1], th.sizeMultiplier, th.buttonHover);
    textRender(startTextSurface, startText, startTextRectSrc,
               startTextRect, th.loc[2], th.loc[3], 1, "Start");

    //leader button
    imageRender(leaderButtonSurface, leaderButton,leaderButtonRectSrc,
                leaderButtonRect, th.loc[4], th.loc[5], th.sizeMultiplier, th.button);
    imageRender(leaderHoverButtonSurface, leaderHoverButton,leaderHoverButtonRectSrc,
                leaderHoverButtonRect, th.loc[4], th.loc[5], th.sizeMultiplier, th.buttonHover);
    textRender(leaderTextSurface, leaderText, leaderTextRectSrc,
               leaderTextRect, th.loc[6], th.loc[7], 0.5, "LeaderBoard");

    // login button
    imageRender(logInButtonSurface, logInButton,logInButtonRectSrc,
                logInButtonRect, 100, 500, th.sizeMultiplier, th.button);
    imageRender(logInHoverButtonSurface, logInHoverButton,logInHoverButtonRectSrc,
                logInHoverButtonRect, 100, 500, th.sizeMultiplier, th.buttonHover);
    textRender(logInTextSurface, logInText, logInTextRectSrc,
               logInTextRect, 163, 564, 0.5, "Login");

    //sign in button
    imageRender(signInButtonSurface, signInButton,signInButtonRectSrc,
                signInButtonRect, 300, 500, th.sizeMultiplier, th.button);
    imageRender(signInHoverButtonSurface, signInHoverButton,signInHoverButtonRectSrc,
                signInHoverButtonRect, 300, 500, th.sizeMultiplier, th.buttonHover);
    textRender(signInTextSurface, signInText, signInTextRectSrc,
               signInTextRect, 363, 564, 0.5, "Sign in");

    //log out button
    imageRender(logOutButtonSurface, logOutButton,logOutButtonRectSrc,
                logOutButtonRect, 300, 500, th.sizeMultiplier, th.button);
    textRender(logInTextSurface, logInText, logInTextRectSrc,
               logOutTextRect, 363, 564, 0.5, "Logout");

    //back button
    imageRender(backButtonSurface, backButton,backButtonRectSrc,
                backButtonRect, th.loc[8], th.loc[9], th.sizeMultiplier, th.button);
    imageRender(backHoverButtonSurface, backHoverButton,backHoverButtonRectSrc,
                backHoverButtonRect, th.loc[8], th.loc[9], th.sizeMultiplier, th.buttonHover);
    textRender(backTextSurface, backText, backTextRectSrc,
               backTextRect, th.loc[10], th.loc[11], 1, "Back");

    //quit menu
    textRender(DoYouWantToQuitTextSurface, DoYouWantToQuitText, DoYouWantToQuitTextRectSrc,
               DoYouWantToQuitTextRect, 70+th.loc[23], 220, 0.5, "Do you Really want to quit the Game? :(");
    imageRender(iWantQuitButtonSurface, iWantQuitButton,iWantQuitButtonRectSrc,
                iWantQuitButtonRect, th.loc[8], th.loc[9]-330, th.sizeMultiplier, th.buttonQuit);
    textRender(iWantQuitTextSurface, iWantQuitText, iWantQuitTextRectSrc,
               iWantQuitTextRect, th.loc[12], th.loc[13], 1, "Yes!");

    //normal mode menu
    imageRender(normalModeButtonSurface, normalModeButton,normalModeButtonRectSrc,
                normalModeButtonRect, th.loc[0], th.loc[1] - 200, th.sizeMultiplier, th.button);
    imageRender(normalModeHoverButtonSurface, normalModeHoverButton,normalModeHoverButtonRectSrc,
                normalModeHoverButtonRect, th.loc[0], th.loc[1] - 200, th.sizeMultiplier, th.buttonHover);
    textRender(normalModeTextSurface, normalModeText, normalModeTextRectSrc,
               normalModeTextRect, th.loc[14], th.loc[15], 0.8, " Normal");

    //timed mode menu
    imageRender(timedModeButtonSurface, timedModeButton,timedModeButtonRectSrc,
                timedModeButtonRect, th.loc[4], th.loc[5] - 200, th.sizeMultiplier, th.button);
    imageRender(timedModeHoverButtonSurface, timedModeHoverButton,timedModeHoverButtonRectSrc,
                timedModeHoverButtonRect, th.loc[4], th.loc[5] - 200, th.sizeMultiplier, th.buttonHover);
    textRender(timedModeTextSurface, timedModeText, timedModeTextRectSrc,
               timedModeTextRect, th.loc[16], th.loc[17], 0.8, "Timed");

    //random mode menu
    imageRender(randomModeButtonSurface, randomModeButton,randomModeButtonRectSrc,
                randomModeButtonRect, th.loc[0], th.loc[1], th.sizeMultiplier, th.button);
    imageRender(randomModeHoverButtonSurface, randomModeHoverButton, randomModeHoverButtonRectSrc,
                randomModeHoverButtonRect, th.loc[0], th.loc[1], th.sizeMultiplier, th.buttonHover);
    textRender(randomModeTextSurface, randomModeText, randomModeTextRectSrc,
               randomModeTextRect, th.loc[14]-th.loc[20], th.loc[15] + 200, 0.8, "Random");

    //infinite mode menu
    imageRender(infiniteModeButtonSurface, infiniteModeButton,infiniteModeButtonRectSrc,
                infiniteModeButtonRect, th.loc[4], th.loc[5], th.sizeMultiplier, th.button);
    imageRender(infiniteModeHoverButtonSurface, infiniteModeHoverButton,infiniteModeHoverButtonRectSrc,
                infiniteModeHoverButtonRect, th.loc[4], th.loc[5], th.sizeMultiplier, th.buttonHover);
    textRender(infiniteModeTextSurface, infiniteModeText, infiniteModeTextRectSrc,
               infiniteModeTextRect, th.loc[16]+th.loc[20], th.loc[17]+200, 0.8, "Infinite");

    //level 1 button
    imageRender(level1ButtonSurface, level1Button,level1ButtonRectSrc,
                level1ButtonRect, th.loc[0], th.loc[1]-300, th.sizeMultiplier, th.button);
    imageRender(level1HoverButtonSurface, level1HoverButton,level1HoverButtonRectSrc,
                level1HoverButtonRect, th.loc[0], th.loc[1]-300, th.sizeMultiplier, th.buttonHover);
    textRender(level1TextSurface, level1Text, level1TextRectSrc,
               level1TextRect, th.loc[18], th.loc[19]+th.loc[21], 0.9, "level 1");

    //level 2 button
    imageRender(level2ButtonSurface, level2Button,level2ButtonRectSrc,
                level2ButtonRect, th.loc[4], th.loc[5]-300, th.sizeMultiplier, th.button);
    imageRender(level2HoverButtonSurface, level2HoverButton,level2HoverButtonRectSrc,
                level2HoverButtonRect, th.loc[4], th.loc[5]-300, th.sizeMultiplier, th.buttonHover);
    textRender(level2TextSurface, level2Text, level2TextRectSrc,
               level2TextRect, th.loc[18]+300, th.loc[19]+th.loc[21], 0.9, "level 2");

    //level 3 button
    imageRender(level3ButtonSurface, level3Button,level3ButtonRectSrc,
                level3ButtonRect, th.loc[0], th.loc[1]-100, th.sizeMultiplier, th.button);
    imageRender(level3HoverButtonSurface, level3HoverButton,level3HoverButtonRectSrc,
                level3HoverButtonRect, th.loc[0], th.loc[1]-100, th.sizeMultiplier, th.buttonHover);
    textRender(level3TextSurface, level3Text, level3TextRectSrc,
               level3TextRect, th.loc[18], th.loc[19]+200+th.loc[21], 0.9, "level 3");

    //level 4 button
    imageRender(level4ButtonSurface, level4Button,level4ButtonRectSrc,
                level4ButtonRect, th.loc[4], th.loc[5]-100, th.sizeMultiplier, th.button);
    imageRender(level4HoverButtonSurface, level4HoverButton,level4HoverButtonRectSrc,
                level4HoverButtonRect, th.loc[4], th.loc[5]-100, th.sizeMultiplier, th.buttonHover);
    textRender(level4TextSurface, level4Text, level4TextRectSrc,
               level4TextRect, th.loc[18]+300, th.loc[19]+200+th.loc[21], 0.9, "level 4");

    //level 5 button
    imageRender(level5ButtonSurface, level5Button,level5ButtonRectSrc,
                level5ButtonRect, (th.loc[0]+th.loc[4])/2, th.loc[9]-150, th.sizeMultiplier, th.button);
    imageRender(level5HoverButtonSurface, level5HoverButton,level5HoverButtonRectSrc,
                level5HoverButtonRect, (th.loc[0]+th.loc[4])/2, th.loc[9]-150, th.sizeMultiplier, th.buttonHover);
    textRender(level5TextSurface, level5Text, level5TextRectSrc,
               level5TextRect, th.loc[18]+150, th.loc[19]+345, 0.9, "level 5");

    //restart button
    imageRender(restartButtonSurface, restartButton,restartButtonRectSrc,
                restartButtonRect, th.loc[8], th.loc[9]-520, th.sizeMultiplier, th.button);
    imageRender(restartHoverButtonSurface, restartHoverButton,restartHoverButtonRectSrc,
                restartHoverButtonRect, th.loc[8], th.loc[9]-520, th.sizeMultiplier, th.buttonHover);
    textRender(restartTextSurface, restartText, restartTextRectSrc,
               restartTextRect, th.loc[10]-13, th.loc[11]-520+th.loc[24], 0.8, "Restart");

    //setting button
    imageRender(settingMenuButtonSurface, settingMenuButton,settingMenuButtonRectSrc,
                settingMenuButtonRect, th.loc[8], th.loc[9]-330, th.sizeMultiplier, th.button);
    imageRender(settingMenuHoverButtonSurface, settingMenuHoverButton,settingMenuHoverButtonRectSrc,
                settingMenuHoverButtonRect, th.loc[8], th.loc[9]-330, th.sizeMultiplier, th.buttonHover);
    textRender(settingMenuTextSurface, settingMenuText, settingMenuTextRectSrc,
               settingMenuTextRect, th.loc[10]-5, th.loc[11]-330+th.loc[24], 0.8, "Setting");

    //mainMenu button
    imageRender(mainMenuButtonSurface, mainMenuButton,mainMenuButtonRectSrc,
                mainMenuButtonRect, th.loc[8], th.loc[9]-145, th.sizeMultiplier, th.button);
    imageRender(mainMenuHoverButtonSurface, mainMenuHoverButton,mainMenuHoverButtonRectSrc,
                mainMenuHoverButtonRect, th.loc[8], th.loc[9]-145, th.sizeMultiplier, th.buttonHover);
    textRender(mainMenuTextSurface, mainMenuText, mainMenuTextRectSrc,
               mainMenuTextRect, th.loc[10]-3, th.loc[11]-140+th.loc[24], 0.5, "Main Menu");



    //Jungle theme button
    theme temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess = Jungle;
    imageRender(jungleThemeButtonSurface, jungleThemeButton,jungleThemeButtonRectSrc,
                jungleThemeButtonRect, 219, 185, 0.33, temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess.button);
    imageRender(jungleThemeHoverButtonSurface, jungleThemeHoverButton,jungleThemeHoverButtonRectSrc,
                jungleThemeHoverButtonRect, 219, 185, 0.33, temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess.buttonHover);
    textRender(jungleThemeTextSurface, jungleThemeText, jungleThemeTextRectSrc,
               jungleThemeTextRect, 230+th.loc[22], 215, 0.8, " Jungle");

    //Ocean theme button
    temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess = Ocean;
    imageRender(oceanThemeButtonSurface, oceanThemeButton,oceanThemeButtonRectSrc,
                oceanThemeButtonRect, 226, 305, 0.2, temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess.button);
    imageRender(oceanThemeHoverButtonSurface, oceanThemeHoverButton,oceanThemeHoverButtonRectSrc,
                oceanThemeHoverButtonRect, 226, 305, 0.2, temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess.buttonHover);
    textRender(oceanThemeTextSurface, oceanThemeText, oceanThemeTextRectSrc,
               oceanThemeTextRect, 230+th.loc[22], 345, 0.8, " Ocean");

    //Space theme button
    temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess = Space;
    imageRender(spaceThemeButtonSurface, spaceThemeButton,spaceThemeButtonRectSrc,
                spaceThemeButtonRect, 236, 440, 0.33, temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess.button);
    imageRender(spaceThemeHoverButtonSurface, spaceThemeHoverButton,spaceThemeHoverButtonRectSrc,
                spaceThemeHoverButtonRect, 236, 440, 0.33, temporaryVariableJustBecauseCppIsStupidInMemoryManagementIGuess.buttonHover);
    textRender(spaceThemeTextSurface, spaceThemeText, spaceThemeTextRectSrc,
               spaceThemeTextRect, 235+th.loc[22], 480, 0.8, " Space");

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


    SDL_FreeSurface(mainMenuButtonSurface);
    SDL_DestroyTexture(mainMenuButton);
    SDL_FreeSurface(mainMenuHoverButtonSurface);
    SDL_DestroyTexture(mainMenuHoverButton);
    SDL_FreeSurface(mainMenuTextSurface);
    SDL_DestroyTexture(mainMenuText);

    SDL_FreeSurface(restartButtonSurface);
    SDL_DestroyTexture(restartButton);
    SDL_FreeSurface(restartHoverButtonSurface);
    SDL_DestroyTexture(restartHoverButton);
    SDL_FreeSurface(restartTextSurface);
    SDL_DestroyTexture(restartText);

    SDL_FreeSurface(settingMenuButtonSurface);
    SDL_DestroyTexture(settingMenuButton);
    SDL_FreeSurface(settingMenuHoverButtonSurface);
    SDL_DestroyTexture(settingMenuHoverButton);
    SDL_FreeSurface(settingMenuTextSurface);
    SDL_DestroyTexture(settingMenuText);


}

void reInitialingSoundMusic() {
    soundInsideRect.w = soundVolume;
    #ifdef _WIN32
        Mix_Volume(-1, soundVolume * 128 / soundOutsideRect.w);
    #else
        Mix_VolumeChunk(winningSound, soundVolume * 128 / soundOutsideRect.w);
        Mix_VolumeChunk(losingSound, soundVolume * 128 / soundOutsideRect.w);
        Mix_VolumeChunk(clickSound, soundVolume * 128 / soundOutsideRect.w);
    #endif



    musicInsideRect.w = musicVolume;
    Mix_VolumeMusic(musicVolume * 128 / soundOutsideRect.w);
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

void leaderTextDestroy(int n, SDL_Surface *surface[MAX_ARRAY_SIZE], SDL_Texture *text[MAX_ARRAY_SIZE]) {
    for(int i = 0;i< n;i++) {
        SDL_FreeSurface(surface[i]);
        SDL_DestroyTexture(text[i]);
    }
}

void leaderTextConfig(int n, SDL_Surface *surface[MAX_ARRAY_SIZE], SDL_Texture *text[MAX_ARRAY_SIZE], SDL_Rect rectSrc[MAX_ARRAY_SIZE], SDL_Rect rect[MAX_ARRAY_SIZE], string list[MAX_ARRAY_SIZE], int pos, bool flag) {

    //leaderTextDestroy(n, surface, text);

    SDL_SetRenderDrawColor(renderer, WHITE.r, WHITE.g, WHITE.b, WHITE.a);

    for(int i = 0;i < n;i++) {
        string txt = list[i];
        if(flag)
            while(txt.size() < 7)
                txt = ' ' + txt;
        textRender(surface[i], text[i], rectSrc[i],rect[i], pos, 60 + i * 50, 0.5, txt);
        SDL_RenderCopy(renderer, text[i], &rectSrc[i], &rect[i]);
        SDL_RenderDrawLine(renderer, 50, (i+2) * 50, 550, (i+2) * 50);
    }

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

//    // login button
//    if(!checkInOut(x_MouseWhere, y_MouseWhere, logInButtonRect))
//        SDL_RenderCopy(renderer, logInButton, &logInButtonRectSrc, &logInButtonRect);
//    else
//        SDL_RenderCopy(renderer, logInHoverButton, &logInHoverButtonRectSrc, &logInHoverButtonRect);
//    SDL_RenderCopy(renderer, logInText, &logInTextRectSrc, &logInTextRect);
//
//    // sign in button
//    if(!checkInOut(x_MouseWhere, y_MouseWhere, signInButtonRect))
//        SDL_RenderCopy(renderer, signInButton, &signInButtonRectSrc, &signInButtonRect);
//    else
//        SDL_RenderCopy(renderer, signInHoverButton, &signInHoverButtonRectSrc, &signInHoverButtonRect);
//    SDL_RenderCopy(renderer, signInText, &signInTextRectSrc, &signInTextRect);

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
        Locator["leaderStart"] = !Locator["leaderStart"];
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

void leader_start_Menu(bool &MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator, GAME_INF &gameInfo) {

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
        Locator["leaderStart"] = !Locator["leaderStart"];
        Locator["leaderLevel"] = !Locator["leaderLevel"];
        gameInfo.mode = "normal";
    }

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, timedModeButtonRect)) {
        Locator["leaderStart"] = !Locator["leaderStart"];
        Locator["leaderLevel"] = !Locator["leaderLevel"];
        gameInfo.mode = "timed";
    }

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, randomModeButtonRect)) {
        Locator["leaderStart"] = !Locator["leaderStart"];
        Locator["leaderboard"] = !Locator["leaderboard"];
        gameInfo.mode = "random";
    }

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, infiniteModeButtonRect)) {
        Locator["leaderStart"] = !Locator["leaderStart"];
        Locator["leaderboard"] = !Locator["leaderboard"];
        gameInfo.mode = "infinite";
    }

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, backButtonRect)) {
        Locator["leaderStart"] = !Locator["leaderStart"];
        Locator["main_menu"] = !Locator["main_menu"];
    }

    if(MouseClicked)
        MouseClicked = !MouseClicked;


}

void leader_level_selector(bool &MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator, GAME_INF &gameInfo) {

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
        Locator["leaderLevel"] = !Locator["leaderLevel"];
        Locator["leaderboard"] = !Locator["leaderboard"];
        gameInfo.level = 1;
    }

    if (MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, level2ButtonRect)) {
        Locator["leaderLevel"] = !Locator["leaderLevel"];
        Locator["leaderboard"] = !Locator["leaderboard"];
        gameInfo.level = 2;
    }

    if (MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, level3ButtonRect)) {
        Locator["leaderLevel"] = !Locator["leaderLevel"];
        Locator["leaderboard"] = !Locator["leaderboard"];
        gameInfo.level = 3;
    }

    if (MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, level4ButtonRect)) {
        Locator["leaderLevel"] = !Locator["leaderLevel"];
        Locator["leaderboard"] = !Locator["leaderboard"];
        gameInfo.level = 4;
    }

    if (MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, level5ButtonRect)) {
        Locator["leaderLevel"] = !Locator["leaderLevel"];
        Locator["leaderboard"] = !Locator["leaderboard"];
        gameInfo.level = 5;
    }

    if (MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, backButtonRect)) {
        Locator["leaderStart"] = !Locator["leaderStart"];
        Locator["leaderLevel"] = !Locator["leaderLevel"];
    }

    if(MouseClicked)
        MouseClicked = !MouseClicked;

}

void leaderboard(bool &MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, map<string, bool>& Locator, GAME_INF gameInfo) {

    // initialing and Drawing background

    SDL_SetRenderDrawColor(renderer, th.MainColor.r, th.MainColor.g, th.MainColor.b, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, bg, NULL, &bgRect);

    // data box
    SDL_Rect fillRect = {50, 50, 500, 500};
    SDL_RenderFillRect(renderer, &fillRect);

    // info variables
    string scores[MAX_ARRAY_SIZE];
    string names[MAX_ARRAY_SIZE];
    int n = scoresReader(gameInfo, names, scores);

    SDL_Surface *namesTextSurface[n];
    SDL_Texture *namesText[n];
    SDL_Rect namesTextRectSrc[n];
    SDL_Rect namesTextRect[n];
    SDL_Surface *scoresTextSurface[n];
    SDL_Texture *scoresText[n];
    SDL_Rect scoresTextRectSrc[n];
    SDL_Rect scoresTextRect[n];

    leaderTextConfig(n, namesTextSurface, namesText, namesTextRectSrc, namesTextRect, names, 60, false);
    leaderTextConfig(n, scoresTextSurface, scoresText, scoresTextRectSrc, scoresTextRect, scores, 460, true);


    // back button
    if(!checkInOut(x_MouseWhere, y_MouseWhere, backButtonRect))
        SDL_RenderCopy(renderer, backButton, &backButtonRectSrc, &backButtonRect);
    else
        SDL_RenderCopy(renderer, backHoverButton, &backHoverButtonRectSrc, &backHoverButtonRect);
    SDL_RenderCopy(renderer, backText, &backTextRectSrc, &backTextRect);

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, backButtonRect)){
        Locator["leaderboard"] = !Locator["leaderboard"];
        Locator["leaderStart"] = !Locator["leaderStart"];
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
        else soundVolume = soundOutsideRect.w;
        reInitialingSoundMusic();
    }

    if(MouseClicked && checkInOut(x_MouseClicked, y_MouseClicked, musicOnButtonRect)){
        if(musicVolume) musicVolume = 0;
        else musicVolume = soundOutsideRect.w;
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