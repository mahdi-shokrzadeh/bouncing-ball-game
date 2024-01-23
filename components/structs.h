#ifndef BOUNCING_BALL_GAME_STRUCTS_H
#define BOUNCING_BALL_GAME_STRUCTS_H

// game structures
typedef struct DOUBLE_POINT {
    double x;
    double y;
} DOUBLE_POINT;

// s -> sample ball which will not be rendered.

typedef struct BALL {
    char type='s';
    SDL_Color color;
    DOUBLE_POINT center;
} BALL;

typedef struct ELEMENT {
   int i;
   int j;
}ELEMENT;

// file structures
struct user {
    int id;
    string name;
    string password;
};

struct score {
    int user_id;
    int level_id;
    int time_created;
    int score;
};

struct level {
    string mode;
    int difficulty_level;
};



#endif //BOUNCING_BALL_GAME_STRUCTS_H
