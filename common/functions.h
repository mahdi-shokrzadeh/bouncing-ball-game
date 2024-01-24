#ifndef BOUNCING_BALL_GAME_FUNCTIONS_H
#define BOUNCING_BALL_GAME_FUNCTIONS_H


double calculateDistance(DOUBLE_POINT a, DOUBLE_POINT b);

bool checkInOut(int x, int y, SDL_Rect rect);




// ------------------------------------



bool checkInOut(int x, int y, SDL_Rect rect) {
    return (x >= rect.x && x <= rect.x + rect.w) && (y >= rect.y && y <= rect.y + rect.h);
}


double calculateDistance(DOUBLE_POINT a, DOUBLE_POINT b) {
    return sqrt((a.y - b.y) * (a.y - b.y) +
                (a.x - b.x) * (a.x - b.x));
}


#endif //BOUNCING_BALL_GAME_FUNCTIONS_H