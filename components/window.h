#ifndef BOUNCING_BALL_GAME_WINDOW_H
#define BOUNCING_BALL_GAME_WINDOW_H




// SDL Window
SDL_Window *window;

// SDL Renderer to draw to
SDL_Renderer *renderer;

// SDL font
TTF_Font *font = NULL;

// theme
theme th = th1;



// where are we?
bool main_menu = true, start_menu = false, leaderboard = false, setting = false, quit_menu = false, game = false;


// Menus

void Main_Menu(bool MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, bool &game, bool &main_menu);

void Main_Menu(bool MouseClicked, int x_MouseClicked, int y_MouseClicked, int x_MouseWhere, int y_MouseWhere, bool &game, bool &main_menu) {

    // Draw buttons

    SDL_SetRenderDrawColor(renderer, th.MainColor.r, th.MainColor.g, th.MainColor.b, 255);
    SDL_RenderClear(renderer);


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
    SDL_Rect settingBtn = {100, 500, 400, 80};
    SDL_SetRenderDrawColor(renderer, th.SecColor.r, th.SecColor.g, th.SecColor.b, 255);
    SDL_RenderFillRect(renderer, &settingBtn);

    // quit button
    SDL_Rect quitBtn = {100, 600, 400, 80};
    SDL_SetRenderDrawColor(renderer, th.SecColor.r, th.SecColor.g, th.SecColor.b, 255);
    SDL_RenderFillRect(renderer, &quitBtn);

    // mouse actions
    /*if(x_MouseWhere >= startBtn.x && x_MouseWhere <= startBtn.x + startBtn.w && y_MouseWhere >= startBtn.y && y_MouseWhere <= startBtn.y + startBtn.h){
        void;
    }*/
    if(MouseClicked && (x_MouseClicked >= startBtn.x && x_MouseClicked <= startBtn.x + startBtn.w) && (y_MouseClicked >= startBtn.y && y_MouseClicked <= startBtn.y + startBtn.h)){
        game = !game;
        main_menu = !main_menu;
    }

    // destroyer
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(startText);
    SDL_FreeSurface(startSurf);
    SDL_DestroyTexture(leaderText);
    SDL_FreeSurface(leaderSurf);
}





#endif //BOUNCING_BALL_GAME_WINDOW_H