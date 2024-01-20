#ifndef BOUNCING_BALL_GAME_STRUCTS_H
#define BOUNCING_BALL_GAME_STRUCTS_H

// game structures
typedef struct DOUBLE_POINT {
    double x;
    double y;
} DOUBLE_POINT;


typedef struct BALL {
    char type='s';
    SDL_Color color;
    DOUBLE_POINT center;
} BALL;

typedef struct ELEMENT {
   int i;
   int j;
}ELEMENT;



#endif //BOUNCING_BALL_GAME_STRUCTS_H
