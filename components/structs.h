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
    SDL_Color color{};
    DOUBLE_POINT center{};
    SDL_Color second_color = BLACK;
    int level = 0;
    double dx = 0.0;

} BALL;

typedef struct ELEMENT {
   int i;
   int j;
}ELEMENT;

// file structures
struct USER {
    //int id;
    string name;
    //string password;
};

//struct SCORE {
//    // int user_id;
//    int level_id;
//    //int time_created;
//    int score;
//};
//
//struct LEVEL {
//    string mode;
//    int number_of_possible_throwing_balls;
//    int difficulty_level;
//};


typedef struct GAME_INF {
    string user;
    string mode;
    int level;
    int score;
} GAME_INF;


#endif //BOUNCING_BALL_GAME_STRUCTS_H
