#ifndef BOUNCING_BALL_GAME_GAME_H
#define BOUNCING_BALL_GAME_GAME_H

#ifdef _WIN32

#include <windows.h>

#else
#include <unistd.h>
#endif

// variables related to targeter
DOUBLE_POINT center_of_shooting_ball = {
        .x = 300,
        .y = 620,
};
DOUBLE_POINT center_of_reserved_ball = {
        .x = 220,
        .y = 670,
};


BALL thrown_ball;
bool ball_is_being_thrown = false;
double dxOfThrownBall;
double dyOfThrownBall;

int number_of_balls = 0;


BALL sample_ball = {
        .type ='s',
        .color = RED,

        .center = {
                .x = 10000,
                .y = 10000,
        },
};

BALL end_pointer_ball = {
        .type = 'e',
        .color = RED,
        .center = {
                .x = 0.0,
                .y = 0.0,
        },
};


BALL gone_ball = {

        .type ='s',
        .color = PINK,
        .center = {
                .x = 10000,
                .y = 20000,
        },

};


double degree = 180.0;
int targeter_balls_radius = 2;
double targeter_balls_dist = 9.0;

// Flag
ELEMENT flag = {ESCAPE_FOR_BALLS_ARRAY + 2, 0};


// variables related to balls

const int radius_of_balls = 20;
const int width_of_ball_box = 46;
double vertical_speed = 0.2;
double dist_from_left = 14.5;


// event
SDL_Event event;


// Initializing balls

BALL balls[100][12] = {0};


// Page state
string game_page_state;

// buttons coordination
SDL_Rect menu_btn_rect = {
        .x = 20,
        .y = 560,
        .w = 60,
        .h = 60,
};

SDL_Surface *menu_btn_sur;
SDL_Texture *menu_btn_tex;

SDL_Rect main_menu_btn_rect = {
        .x = 80,
        .y = 380,
        .w = 210,
        .h = 210,
};
SDL_Rect main_menu_btn_rect_win = {
        .x = 110,
        .y = 380,
        .w = 220,
        .h = 220,
};


SDL_Surface *main_menu_btn_sur;
SDL_Texture *main_menu_btn_tex;


SDL_Rect play_again_btn_rect = {
        .x = 300,
        .y = 380,
        .w = 220,
        .h = 220,
};


SDL_Surface *play_again_btn_sur;
SDL_Texture *play_again_btn_tex;


// mouse
bool mouse_click = false;
int mouse_x = 0, mouse_y = 0;
int free_mouse_x = 0, free_mouse_y = 0;

// falling balls speed
double falling_balls_speed = 1.9;
double falling_ball_acc = 0.011;

// score
int score = 0;
int fell_balls = 0;
int temp_fell_balls = 0;
SDL_Surface *score_surface;
SDL_Texture *score_texture;
SDL_Rect score_rect_src;
SDL_Rect score_rect;

int score_x = 390;
int score_y = 660;


// color handling
vector<int> balls_recent_color = {1};

// pattern
int pattern[100][12];


// win
SDL_Surface *win_surface;
SDL_Texture *win_texture;
SDL_Rect win_rect_src, win_rect;
ELEMENT win_coor = {
        130,
        300,
};


// loose
SDL_Surface *loose_surface;
SDL_Texture *loose_texture;
SDL_Rect loose_rect_src, loose_rect;
ELEMENT loose_coor = {
        160,
        270,
};

// shooter
SDL_Rect shooter_section = {10, 550, 580, 160};

// Game

string game_state = "running";
string game_mode = "time";
int time_to_wait = 9;
bool throw_is_disabled = false;
bool game_loop;

// Timer mode
auto start_time = std::chrono::high_resolution_clock::now();
int timer = TIMER;


// timer
SDL_Surface *timer_surface;
SDL_Texture *timer_texture;
SDL_Rect timer_rect_src, timer_rect;
ELEMENT timer_coor = {
        30,
        SCREEN_HEIGHT - 60,
};


void handleGameProcess(GAME_INF game_inf);

void setRandomColor(SDL_Color &color);

void initializeBalls();

void initializeShootingBalls(BALL &shooter_ball, BALL &reserved_ball);

void swapShootingBalls(BALL &shooter_ball, BALL &reserved_ball);

void drawShootingBalls(BALL shooter_ball, BALL reserved_ball);

void drawTargeter();

void ballDraw(BALL ball);

void handleTargeterEvent(int type);

bool checkCollTargeterAndBalls(DOUBLE_POINT targeter_point);

void handleShootBall(BALL &shooting_ball, BALL &reserved_ball);

void handleBallShooting();

void Game(BALL &shooter_ball, BALL &reserved_ball);

void checkCollShooterAndBalls();

void handleCollShooterAndBalls(BALL &ball, int i, int j);

vector<ELEMENT> findNeighbors(int i, int j, string type);

void filterByColor(vector<ELEMENT> &elements, BALL ball);

void handleGraphCheck(int i, int j, BALL in_ball);

void handleFallingBalls();

void initializeMenuButtons();

void gameInitialImage(SDL_Surface *&g_button, SDL_Texture *&g_button_tex, char *src);

void handleCheckBtnsClicks();

void gameRenderImage(SDL_Texture *&g_button_tex, SDL_Rect dstRect);

void destroyIt(SDL_Surface *&g_button, SDL_Texture *&g_button_tex);

bool colorsAreTheSame(SDL_Color c1, SDL_Color c2);

void setRandomColorForShootingBall(SDL_Color &color);

void setPattern(int arr[DIMENTION_OF_LEVELS][12]);

int calculateBalls();

void checkColorOfShootingBalls(BALL &ball);

vector<int> getAvailableColorsVector();

int colorToInt(SDL_Color color);

void handleWin();

void drawSomeSections();

void handleGameOver();

void showScore(string type);
// ---------------------------------------------------


void handleGameProcess(GAME_INF game_inf) {

    game_page_state = "game";

    // Loading all needed buttons
    initializeMenuButtons();

    // time init
    start_time = chrono::high_resolution_clock::now();


    initializeBalls();
    BALL shooter_ball;
    BALL reserved_ball;
    initializeShootingBalls(shooter_ball, reserved_ball);

    game_loop = SDL_TRUE;


    while (game_loop) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                game_loop = SDL_FALSE;
                main_loop = SDL_FALSE;
            } else if (event.type == SDL_KEYDOWN) {
                if (game_page_state == "game") {
                    switch (event.key.keysym.sym) {
                        case SDLK_SPACE:
                            swapShootingBalls(shooter_ball, reserved_ball);
                            drawShootingBalls(shooter_ball, reserved_ball);
                            break;

                        case SDLK_RIGHT :
                            handleTargeterEvent(0);
                            break;

                        case SDLK_s :
                            handleShootBall(shooter_ball, reserved_ball);
                            break;

                        case SDLK_LEFT :
                            handleTargeterEvent(1);
                            break;

                        default:
                            game_loop = SDL_TRUE;
                    }
                }


            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                mouse_click = true;
                mouse_x = event.button.x;
                mouse_y = event.button.y;
            } else if (event.type == SDL_MOUSEBUTTONUP) {
                mouse_click = false;
            }
        }

        SDL_GetMouseState(&free_mouse_x, &free_mouse_y);

        if (game_page_state == "game") {

            Game(shooter_ball, reserved_ball);

        } else if (game_page_state == "pause_menu") {

//            SDL_RenderPresent(renderer);

        } else if (game_page_state == "quit_menu") {


        } else if (game_page_state == "over") {
            handleGameOver();
        } else if (game_page_state == "win") {
            handleWin();
        }


        // checking clicks
        handleCheckBtnsClicks();


        //  Delay and update window
        SDL_RenderPresent(renderer);
        SDL_Delay(DELAY);


        if (!game_loop) {

            // destroy everything
            destroyIt(menu_btn_sur, menu_btn_tex);
            destroyIt(score_surface, score_texture);
            destroyIt(win_surface, win_texture);
            destroyIt(loose_surface, loose_texture);
            destroyIt(timer_surface, timer_texture);
            destroyIt(play_again_btn_sur, play_again_btn_tex);
            destroyIt(main_menu_btn_sur, main_menu_btn_tex);

        }

    }

}


void Game(BALL &shooter_ball, BALL &reserved_ball) {

    if (game_mode == "normal" || game_mode == "time") {

        bool ball_is_falling = false;
        // Blank out the renderer with all black
        SDL_SetRenderDrawColor(renderer, BLACK.r, BLACK.g, BLACK.b, 255);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, bg, NULL, &bgRect);


        // targeter
        drawTargeter();

        // drawing balls

        for (int i = 0; i < FINAL_ROWS; i++) {
            int p = rand() % 2;
            for (int j = 0; j < 12; j++) {
                if (balls[i][j].type != 's') {
                    BALL &ball = balls[i][j];
                    ball.center.y += vertical_speed;
                    if (ball.center.y <= SCREEN_HEIGHT + 30 && ball.center.y >= -40) {
                        //aacircleRGBA(renderer, Sint16(ball.center.x), Sint16(ball.center.y), radius_of_balls,ball.color.r, ball.color.g, ball.color.b, 255);
                        ballDraw(ball);

                    }


                    // updating the flags
                    if (ball.center.y >= -70 && ball.center.y <= -40 && flag.i != i) {

                        flag.i = i;
                        flag.j = j;
                    }


                    // falling balls
                    if (ball.type == 'f') {

                        i % 2 == 0 ? ball.center.x += 0.09 : ball.center.x -= 0.03;
                        ball.center.y += falling_balls_speed * (1000 + 150 - i) / 1000.0;
                        falling_balls_speed += falling_ball_acc;
                        ball_is_falling = true;
                        if (ball.center.y >= SCREEN_HEIGHT + 20) {
                            ball.center = {10000, 10000};
                            ball.type = 's';
                            temp_fell_balls--;
                        }
                    }

                    // checking if game is over or win
                    // c -> also lock and other types
                    if (ball.center.y >= 530 && (ball.type == 'c' || ball.type == 'e' || ball.type == 't')) {
                        game_state = "over";
                        game_page_state = "over";
                    }


                }
            }
        }
        // updating end_pointer_ball center
        for (int j = 0; j < 12; j++) {
            if (balls[FINAL_ROWS][j].type != 's') {
                BALL &ball = balls[FINAL_ROWS][j];
                ball.center.y += vertical_speed;
            }
        }
        end_pointer_ball.center.y += vertical_speed;


        // shooter
        SDL_RenderDrawRect(renderer, &shooter_section);
        drawShootingBalls(shooter_ball, reserved_ball);


        // draw the end section
        if (end_pointer_ball.center.y >= -50) {
            SDL_Rect r;
            r.x = 5;
            r.y = int(end_pointer_ball.center.y - 85);
            r.w = SCREEN_WIDTH - 10;
            r.h = 50;
            SDL_SetRenderDrawColor(renderer, PLUM.r, PLUM.g, PLUM.b, 255);
            SDL_RenderFillRect(renderer, &r);
            flag.i = FINAL_ROWS;
        }

        // draw pause menu button
        gameRenderImage(menu_btn_tex, menu_btn_rect);


        // score

        textRender(score_surface, score_texture, score_rect_src, score_rect,
                   score_x, score_y, 0.7, to_string(score));
        SDL_RenderCopy(renderer, score_texture, &score_rect_src, &score_rect);



        // handle ball shooting
        if (ball_is_being_thrown && game_state == "running") {
            handleBallShooting();
            checkCollShooterAndBalls();
        }

        // cehck the shooting ball color

        if (!throw_is_disabled) {
            checkColorOfShootingBalls(shooter_ball);
            checkColorOfShootingBalls(reserved_ball);
        }

        // set number of balls
        number_of_balls = calculateBalls();

        // Game Over for timer mode
        if (game_mode == "time") {

            // draw timer

            textRender(timer_surface, timer_texture, timer_rect_src, timer_rect,
                       timer_coor.i, timer_coor.j, 0.8, to_string(timer));
            SDL_RenderCopy(renderer, timer_texture, &timer_rect_src, &timer_rect);

            if (timer <= 0) {
                game_state = "over";
                game_page_state = "over";
                return;
            }

            // updating timer
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start_time);
            if (TIMER - duration.count() != timer) {
                timer = TIMER - duration.count();
            }

        }


        if (number_of_balls == 0 && !ball_is_being_thrown) {
            game_state = "win";
            throw_is_disabled = true;

            // deleting the shooting and reserved ball
//        shooter_ball.color = BLACK;
//        reserved_ball.color = BLACK;
//            shooter_ball.center.y = 1000;
//            reserved_ball.center.y = 1000;

        }

        // handle winning state
        if (!ball_is_falling && number_of_balls == 0 && !ball_is_being_thrown) {
            if (time_to_wait == 0) {
                game_page_state = "win";
                cout << "Won!" << endl;
            }
            time_to_wait--;
        }

    } else if (game_mode == "random") {


    } else {


    }


}


void initializeBalls() {

    setPattern(level_1);

    for (int i = 1; i <= FINAL_ROWS; i++) {
        for (int j = 0; j < SCREEN_WIDTH / width_of_ball_box - 1; j++) {
            if (i <= ESCAPE_FOR_BALLS_ARRAY) {
                balls[i - 1][j] = sample_ball;
            } else {
                if (pattern[i - 1][j] == 0) {
                    balls[i - 1][j] = sample_ball;
                } else {
                    BALL ball = {
                            .type='s',
                            .color = {
                                    .r=0,
                                    .g=0,
                                    .b=0,
                            },
                            .center = {
                                    .x = double(j * (width_of_ball_box) + radius_of_balls + dist_from_left),
                                    .y = double(-(i - 5) * (width_of_ball_box)),
                            },
                    };

                    if (pattern[i - 1][j] == 1 || pattern[i - 1][j] == 2) {

                        ball.type = 'c';

                        // lock
                        if (pattern[i - 1][j] == 2) {
                            ball.level = 1;
                        }

                        setRandomColor(ball.color);
                        if (i == FINAL_ROWS) {
                            while (colorsAreTheSame(ball.color, WHEAT)) setRandomColor(ball.color);
                        }

                    } else if (pattern[i - 1][j] == 3) {

                        ball.type = 't';
                        int k = rand() % 3;
                        switch (k) {
                            case 0:
                                ball.color = BLUE;
                                ball.second_color = YELLOW;
                                break;
                            case 1:
                                ball.color = RED;
                                ball.second_color = BLUE;
                                break;

                            default:
                                ball.color = YELLOW;
                                ball.second_color = RED;

                        }
                    }


                    if (i % 2 == 0) {
                        balls[i - 1][j] = ball;
                    } else {
                        ball.center.x += 0.5 * width_of_ball_box;
                        balls[i - 1][j] = ball;
                    }


                }
            }


        }
    }

    //

    for (int j = 0; j < SCREEN_WIDTH / width_of_ball_box - 1; j++) {
        BALL ball;
        ball.type = 'e';
        // color of end balls must be unique
        ball.color = DARK_ORANGE;
        ball.center.y = double(-(FINAL_ROWS - 4) * (width_of_ball_box));
        ball.center.x = double(j * (width_of_ball_box) + radius_of_balls + dist_from_left);
        if ((FINAL_ROWS + 1) % 2 == 0) {
            balls[FINAL_ROWS][j] = ball;
        } else {
            ball.center.x += 0.5 * width_of_ball_box;
            balls[FINAL_ROWS][j] = ball;
        }
    }
    end_pointer_ball.center.y = double(-(FINAL_ROWS - 5) * (width_of_ball_box));
}


void setPattern(int arr[DIMENTION_OF_LEVELS][12]) {
    for (int i = 0; i < DIMENTION_OF_LEVELS; i++) {
        for (int j = 0; j <= 11; j++) {
            pattern[i + ESCAPE_FOR_BALLS_ARRAY][j] = arr[i][j];
        }
    }
}


void setRandomColor(SDL_Color &color) {

    int i = rand() % 6;
    switch (i) {
        case (0):
            color = RED;
            break;
        case (1):
            color = CYAN;
            break;
        case (2) :
            color = BLUE;
            break;
        case (3) :
            color = PURPLE;
            break;
        case (4) :
            color = GREEN;
            break;
        case (5):
            if (!contains(balls_recent_color, 5)) {
                color = WHEAT;
                break;
            }
        default :
            color = YELLOW;
    }
    balls_recent_color.push_back(i);

    if (balls_recent_color.size() > 6) {
        balls_recent_color.erase(balls_recent_color.begin());
    }
}


void initializeShootingBalls(BALL &shooter_ball, BALL &reserved_ball) {
    shooter_ball.type = 'c';
    reserved_ball.type = 'c';
    shooter_ball.center.x = center_of_shooting_ball.x;
    shooter_ball.center.y = center_of_shooting_ball.y;

    reserved_ball.center.x = center_of_reserved_ball.x;
    reserved_ball.center.y = center_of_reserved_ball.y;

    setRandomColorForShootingBall(shooter_ball.color);
    setRandomColorForShootingBall(reserved_ball.color);
    while (colorsAreTheSame(reserved_ball.color, shooter_ball.color)) {
        setRandomColorForShootingBall(reserved_ball.color);
    }

}


void swapShootingBalls(BALL &shooter_ball, BALL &reserved_ball) {
    swap(shooter_ball.color, reserved_ball.color);
}


void drawShootingBalls(BALL shooter_ball, BALL reserved_ball) {
    ballDraw(shooter_ball);
    ballDraw(reserved_ball);
}


void drawTargeter() {

    DOUBLE_POINT targeter_point = {
            .x = center_of_shooting_ball.x,
            .y = center_of_shooting_ball.y,
    };

    double dx = sin(degree * M_PI / 180.0) * targeter_balls_dist;
    double dy = cos(degree * M_PI / 180.0) * targeter_balls_dist;


    while (true) {

        if (targeter_point.y + dy <= 0 || checkCollTargeterAndBalls(targeter_point)) {
            break;
        }

        if (targeter_point.x + dx >= SCREEN_WIDTH) {
            dx *= -1;
        }
        if (targeter_point.x + dx <= 0) {
            dx *= -1;
        }


        if (calculateDistance(targeter_point, center_of_shooting_ball) >= 25) {

            filledCircleRGBA(renderer, Sint16(targeter_point.x), Sint16(targeter_point.y),
                             Sint16(targeter_balls_radius), WHITE.r, WHITE.g, WHITE.b, 255);
        }

        targeter_point.y += dy;
        targeter_point.x += dx;
    }

}


void ballDraw(BALL ball) {

    int xCom = ball.center.x, yCom = ball.center.y, radius = radius_of_balls;
    SDL_Color color = ball.color;

    SDL_Rect src, dest;

    src.x = 0;
    src.y = 0;
    src.w = 400;
    src.h = 400;

    dest.x = xCom - radius;
    dest.y = yCom - radius;
    dest.w = 400 * 0.11;
    dest.h = 400 * 0.11;


    if (ball.type == 'c' || ball.type == 'f') {
        if (ball.level == 1) {
            if (colorsAreTheSame(color, RED))
                SDL_RenderCopy(renderer, redLockedBall, &src, &dest);
            else if (colorsAreTheSame(color, CYAN))
                SDL_RenderCopy(renderer, cyanLockedBall, &src, &dest);
            else if (colorsAreTheSame(color, BLUE))
                SDL_RenderCopy(renderer, blueLockedBall, &src, &dest);
            else if (colorsAreTheSame(color, PURPLE))
                SDL_RenderCopy(renderer, purpleLockedBall, &src, &dest);
            else if (colorsAreTheSame(color, GREEN))
                SDL_RenderCopy(renderer, greenLockedBall, &src, &dest);
            else if (colorsAreTheSame(color, WHEAT))
                SDL_RenderCopy(renderer, silverLockedBall, &src, &dest);
            else if (colorsAreTheSame(color, YELLOW))
                SDL_RenderCopy(renderer, yellowLockedBall, &src, &dest);

        } else if (ball.level == 0) {

            if (colorsAreTheSame(color, RED))
                SDL_RenderCopy(renderer, redNormalBall, &src, &dest);
            else if (colorsAreTheSame(color, CYAN))
                SDL_RenderCopy(renderer, cyanNormalBall, &src, &dest);
            else if (colorsAreTheSame(color, BLUE))
                SDL_RenderCopy(renderer, blueNormalBall, &src, &dest);
            else if (colorsAreTheSame(color, PURPLE))
                SDL_RenderCopy(renderer, purpleNormalBall, &src, &dest);
            else if (colorsAreTheSame(color, GREEN))
                SDL_RenderCopy(renderer, greenNormalBall, &src, &dest);
            else if (colorsAreTheSame(color, WHEAT))
                SDL_RenderCopy(renderer, silverNormalBall, &src, &dest);
            else if (colorsAreTheSame(color, YELLOW))
                SDL_RenderCopy(renderer, yellowNormalBall, &src, &dest);

        }

    } else if (ball.type == 't') {
        if (colorsAreTheSame(ball.color, RED) && colorsAreTheSame(ball.second_color, BLUE))
            SDL_RenderCopy(renderer, redBlueBall, &src, &dest);
        else if (colorsAreTheSame(ball.color, YELLOW) && colorsAreTheSame(ball.second_color, RED))
            SDL_RenderCopy(renderer, yellowRedBall, &src, &dest);
        else if (colorsAreTheSame(ball.color, BLUE) && colorsAreTheSame(ball.second_color, YELLOW))
            SDL_RenderCopy(renderer, blueYellowBall, &src, &dest);
    }


}


void handleTargeterEvent(int type) {
    switch (type) {
        case 0:
            if (degree >= 110)
                degree -= TARGETER_SPEED;
            break;
        case 1:
            if (degree <= 250)
                degree += TARGETER_SPEED;
            break;
        default:
            break;
    }
}


bool checkCollTargeterAndBalls(DOUBLE_POINT targeter_point) {

    for (int i = 0; i < FINAL_ROWS; i++) {
        for (int j = NUMBER_OF_BALLS_IN_EACH_COL - 1; j >= 0; j--) {
            BALL &ball = balls[i][j];
//            if (ball.center.y <= -10) return false;
            if (calculateDistance(ball.center, targeter_point) <= radius_of_balls + 15) return true;
        }
        // collision to end section
        if (targeter_point.y - 10 <= end_pointer_ball.center.y) return true;

    }
    return false;

}


void handleShootBall(BALL &shooting_ball, BALL &reserved_ball) {

    Mix_PlayChannel(-1, clickSound, 0);


    if (!ball_is_being_thrown) {

        ball_is_being_thrown = true;
        thrown_ball = shooting_ball;
        shooting_ball = reserved_ball;
        shooting_ball.center = center_of_shooting_ball;
        reserved_ball.center = center_of_reserved_ball;
        shooting_ball.type = 'c';
        reserved_ball.type = 'c';
//        setRandomColor(reserved_ball.color);
//        while (reserved_ball.color.r == shooting_ball.color.r) setRandomColor(reserved_ball.color);
        setRandomColorForShootingBall(reserved_ball.color);
        dxOfThrownBall = sin(degree * M_PI / 180.0) * SPEED_OF_THROWN_BALL;
        dyOfThrownBall = cos(degree * M_PI / 180.0) * SPEED_OF_THROWN_BALL;
        drawShootingBalls(shooting_ball, reserved_ball);
    }


}


void handleBallShooting() {

    if (throw_is_disabled) return;

    if (thrown_ball.center.y + dyOfThrownBall <= 0) {
        ball_is_being_thrown = false;
    } else {
        if (thrown_ball.center.x + radius_of_balls + dxOfThrownBall >= SCREEN_WIDTH ||
            thrown_ball.center.x + dxOfThrownBall - radius_of_balls <= 0) {
            dxOfThrownBall *= -1;
        }
    }
    thrown_ball.center.x += dxOfThrownBall;
    thrown_ball.center.y += dyOfThrownBall;

    //aacircleRGBA(renderer, Sint16(thrown_ball.center.x), Sint16(thrown_ball.center.y),Sint16(radius_of_balls), thrown_ball.color.r, thrown_ball.color.g, thrown_ball.color.b, 255);
    ballDraw(thrown_ball);

}


void checkCollShooterAndBalls() {
    for (int i = 0; i < FINAL_ROWS + 1; i++) {
        for (int j = NUMBER_OF_BALLS_IN_EACH_COL - 1; j >= 0; j--) {
            BALL &ball = balls[i][j];
            if (calculateDistance(ball.center, thrown_ball.center) <= radius_of_balls * 2 && ball.type != 'f') {
                // ball is being thrown
                handleCollShooterAndBalls(ball, i, j);
                ball_is_being_thrown = false;
            }
        }
    }
}


void handleCollShooterAndBalls(BALL &ball, int i, int j) {
    if (!ball_is_being_thrown)return;

    ELEMENT el;

    BALL new_ball;
    new_ball.color = thrown_ball.color;
    new_ball.type = 'c';

    double collision_degree;
    string dir;
    collision_degree =
            atan2(abs(ball.center.y - thrown_ball.center.y), abs(thrown_ball.center.x - ball.center.x)) * 180 /
            M_PI;

    if (thrown_ball.center.x >= ball.center.x) {
        dir = "right";
    } else {
        dir = "left";
    }

    // positioning
    if (i % 2 == 0) {
        if (dir == "right") {
            if (collision_degree < 45) {
                new_ball.center.x = double((j + 1.5) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                new_ball.center.y = ball.center.y;
                balls[i][j + 1] = new_ball;
                el.i = i;
                el.j = j + 1;

//                cout << "Right 2 <45" << endl;
            } else {
                // checking if ball is the last or first item of row
                if (j + 1 != 12) {
                    new_ball.center.x = double((j + 1) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                    new_ball.center.y = double(ball.center.y + width_of_ball_box);
                    balls[i - 1][j + 1] = new_ball;
                    el.i = i - 1;
                    el.j = j + 1;
//                    cout << "DSDSF" << endl;

                } else {
                    new_ball.center.x = double((j) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                    new_ball.center.y = double(ball.center.y + width_of_ball_box);
                    balls[i - 1][j] = new_ball;
                    el.i = i - 1;
                    el.j = j;
//                    cout << "Right 2" << endl;
                }

            }

        } else {
            if (collision_degree < 45) {
                if (j + 1 == 1) {
                    new_ball.center.x = double((j) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                    new_ball.center.y = ball.center.y + width_of_ball_box;
                    balls[i - 1][j] = new_ball;
                    el.i = i - 1;
                    el.j = j;

                } else {
                    new_ball.center.x = double((j - 0.5) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                    new_ball.center.y = ball.center.y;
                    balls[i][j - 1] = new_ball;
                    el.i = i;
                    el.j = j - 1;
                }


//                cout << "Left 2 <45" << endl;
            } else {
                new_ball.center.x = double((j) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                new_ball.center.y = double(ball.center.y + width_of_ball_box);
                balls[i - 1][j] = new_ball;
                el.i = i - 1;
                el.j = j;
//                cout << "Left 2" << endl;
            }


        }
    } else {
        if (dir == "right") {
            if (collision_degree < 45) {
                if (j + 1 == 12) {
                    new_ball.center.x = double((j + 0.5) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                    new_ball.center.y = ball.center.y + width_of_ball_box;
                    balls[i - 1][j] = new_ball;
                    el.i = i - 1;
                    el.j = j;
                } else {
                    new_ball.center.x = double((j + 1) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                    new_ball.center.y = ball.center.y;
                    balls[i][j + 1] = new_ball;
                    el.i = i;
                    el.j = j + 1;
//                    cout << "Right 1 <45" << endl;

                }


            } else {
                // checking if ball is the last or first item of row
                new_ball.center.x = double((j + 0.5) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                new_ball.center.y = double(ball.center.y + width_of_ball_box);
                balls[i - 1][j] = new_ball;
                el.i = i - 1;
                el.j = j;
//                cout << "Right 1 " << endl;

            }

        } else {
            if (collision_degree < 45) {
                new_ball.center.x = double((j - 1) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                new_ball.center.y = ball.center.y;
                balls[i][j - 1] = new_ball;
                el.i = i;
                el.j = j - 1;
//                cout << "LEFT 1 <45" << endl;

            } else {
                if (j + 1 != 1) {
                    new_ball.center.x = double((j - 0.5) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                    new_ball.center.y = double(ball.center.y + width_of_ball_box);
                    balls[i - 1][j - 1] = new_ball;
                    el.i = i - 1;
                    el.j = j - 1;
//                    cout << "LEFT 1" << endl;

                } else {
                    new_ball.center.x = double((j + 0.5) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                    new_ball.center.y = double(ball.center.y + width_of_ball_box);
                    balls[i - 1][0] = new_ball;
                    el.i = i - 1;
                    el.j = 0;
//                    cout << "LEFT 1 ex" << endl;
                }

            }

        }

    }

    //    handle graph
    handleGraphCheck(el.i, el.j, thrown_ball);
    // handle balls falling
    handleFallingBalls();

}


vector<ELEMENT> findNeighbors(int i, int j, string type) {

    vector<ELEMENT> neighbors;
    if (type == "all") {
        if (i % 2 == 0) {
            if (j + 1 <= 11) {
                // checking the upper line
                if (balls[i + 1][j + 1].type != 's' && balls[i + 1][j + 1].type != 'f')
                    neighbors.push_back({i + 1, j + 1});
                // checking the line
                if (balls[i][j + 1].type != 's' && balls[i][j + 1].type != 'f') neighbors.push_back({i, j + 1});
                // checking the downer line
                if (balls[i - 1][j + 1].type != 's' && balls[i - 1][j + 1].type != 'f')
                    neighbors.push_back({i - 1, j + 1});
            }

            if (balls[i + 1][j].type != 's' && balls[i + 1][j].type != 'f')
                neighbors.push_back({i + 1, j});
            if (balls[i - 1][j].type != 's' && balls[i - 1][j].type != 'f') neighbors.push_back({i - 1, j});

            if (j - 1 >= 0) {
                if (balls[i][j - 1].type != 's' && balls[i][j - 1].type != 'f') neighbors.push_back({i, j - 1});
            }

        } else {
            if (j - 1 >= 0) {
                // checking the upper line
                if (balls[i + 1][j - 1].type != 's' && balls[i + 1][j - 1].type != 'f')
                    neighbors.push_back({i + 1, j - 1});
                // checking the line
                if (balls[i][j - 1].type != 's' && balls[i][j - 1].type != 'f') neighbors.push_back({i, j - 1});
                // checking the downer line
                if (balls[i - 1][j - 1].type != 's' && balls[i - 1][j - 1].type != 'f')
                    neighbors.push_back({i - 1, j - 1});
            }

            if (balls[i + 1][j].type != 's' && balls[i + 1][j].type != 'f')
                neighbors.push_back({i + 1, j});
            if (balls[i - 1][j].type != 's' && balls[i - 1][j].type != 'f') neighbors.push_back({i - 1, j});

            if (j + 1 <= 11) {
                if (balls[i][j + 1].type != 's' && balls[i][j + 1].type != 'f') neighbors.push_back({i, j + 1});
            }
        }
    } else {
        if (i % 2 == 0) {
            if (j + 1 <= 11) {
                // checking the upper line
                if (balls[i + 1][j + 1].type != 's' && balls[i + 1][j + 1].type != 'f' && i != flag.i)
                    neighbors.push_back({i + 1, j + 1});
                // checking the line
                if (balls[i][j + 1].type != 's' && balls[i][j + 1].type != 'f') neighbors.push_back({i, j + 1});
                // checking the downer line
                if (balls[i - 1][j + 1].type != 's' && balls[i - 1][j + 1].type != 'f')
                    neighbors.push_back({i - 1, j + 1});
            }

            if (balls[i + 1][j].type != 's' && balls[i + 1][j].type != 'f' && i != flag.i)
                neighbors.push_back({i + 1, j});
            if (balls[i - 1][j].type != 's' && balls[i - 1][j].type != 'f') neighbors.push_back({i - 1, j});

            if (j - 1 >= 0) {
                if (balls[i][j - 1].type != 's' && balls[i][j - 1].type != 'f') neighbors.push_back({i, j - 1});
            }

        } else {
            if (j - 1 >= 0) {
                // checking the upper line
                if (balls[i + 1][j - 1].type != 's' && balls[i + 1][j - 1].type != 'f' && i != flag.i)
                    neighbors.push_back({i + 1, j - 1});
                // checking the line
                if (balls[i][j - 1].type != 's' && balls[i][j - 1].type != 'f') neighbors.push_back({i, j - 1});
                // checking the downer line
                if (balls[i - 1][j - 1].type != 's' && balls[i - 1][j - 1].type != 'f')
                    neighbors.push_back({i - 1, j - 1});
            }

            if (balls[i + 1][j].type != 's' && balls[i + 1][j].type != 'f' && i != flag.i)
                neighbors.push_back({i + 1, j});
            if (balls[i - 1][j].type != 's' && balls[i - 1][j].type != 'f') neighbors.push_back({i - 1, j});

            if (j + 1 <= 11) {
                if (balls[i][j + 1].type != 's' && balls[i][j + 1].type != 'f') neighbors.push_back({i, j + 1});
            }
        }
    }


    return neighbors;
}


void filterByColor(vector<ELEMENT> &elements, BALL ball) {
    for (auto it = elements.begin(); it != elements.end();) {
        if (balls[it->i][it->j].type == 't') {
            cout << it->i << " " << it->j << endl;
            if (!colorsAreTheSame(balls[it->i][it->j].color, ball.color) &&
                !colorsAreTheSame(balls[it->i][it->j].second_color, ball.color)) {
                elements.erase(it);
            } else {
                ++it;
            }
        } else if (balls[it->i][it->j].type == 'c') {
            if (!colorsAreTheSame(balls[it->i][it->j].color, ball.color)) {
                elements.erase(it);
            } else {
                ++it;
            }
        }

    }
}


bool vectorContainsElement(const vector<ELEMENT> &elements, ELEMENT el) {
    for (ELEMENT e: elements) {
        if (e.i == el.i && e.j == el.j) return true;
    }
    return false;
}


void handleGraphCheck(int i, int j, BALL in_ball) {

    vector<ELEMENT> visited;
    vector<ELEMENT> queue;

    ELEMENT zero;
    zero.i = i;
    zero.j = j;

    queue.push_back(zero);

    while (!queue.empty()) {
        ELEMENT el = queue[0];
        vector<ELEMENT> vec = findNeighbors(el.i, el.j, "all");
        filterByColor(vec, in_ball);

        visited.push_back(el);
        for (ELEMENT el2: vec) {
            if (!vectorContainsElement(visited, el2)) queue.push_back(el2);
        }

        queue.erase(queue.begin());
    }


    if (visited.size() > LEAST_BALLS_NUMBER) {
        // clearing balls
        for (ELEMENT el: visited) {
            // important condition!
            if (balls[el.i][el.j].center.y >= -20) {
                // checking if ball has lock or no
                if (balls[el.i][el.j].level == 1) {
                    balls[el.i][el.j].level = 0;
                } else {
                    balls[el.i][el.j] = gone_ball;
                    // Adding up score
                    score += 10;
                }

            }

        }
    }

}


void handleFallingBalls() {

    //    Vector type , enhanced version -> array
    vector<ELEMENT> visited;
    vector<ELEMENT> queue;
    ELEMENT element;

    if (end_pointer_ball.center.y >= -50) {
        element = {FINAL_ROWS, 0};
    } else {
        element = flag;
    }


    // Initializing the queue

    for (int j = 0; j <= 11; j++) {
        queue.push_back({element.i, j});
    }
//    cout << element.i << endl;

    while (!queue.empty()) {

        ELEMENT el = queue[0];
        vector<ELEMENT> vec = findNeighbors(el.i, el.j, "down");
        visited.push_back(el);
        for (ELEMENT el2: vec) {
            if (!vectorContainsElement(visited, el2)) queue.push_back(el2);
        }
        queue.erase(queue.begin());

    }

    // removing the other balls
    falling_balls_speed = 1.9;
    for (int i = 0; i < element.i; i++) {
        for (int j = 0; j < 12; j++) {
            if (balls[i][j].type != 's' && balls[i][j].center.y >= -20 && !vectorContainsElement(visited, {i, j})) {
                balls[i][j].type = 'f';
                fell_balls++;
                temp_fell_balls++;

            }
        }
    }
}


void gameInitialImage(SDL_Surface *&g_button, SDL_Texture *&g_button_tex, char *src) {
    g_button = IMG_Load(src);
    if (g_button == NULL) {
        cout << "Error loading image: " << IMG_GetError() << std::endl;
    } else {
        g_button_tex = SDL_CreateTextureFromSurface(renderer, g_button);
        if (g_button_tex == NULL) {
            cout << "Error creating texture";
        }
    }
}


void initializeMenuButtons() {
    gameInitialImage(menu_btn_sur, menu_btn_tex, "assets/Game/menu2.png");
    gameInitialImage(main_menu_btn_sur, main_menu_btn_tex, "assets/Game/others/main_menu.png");
    gameInitialImage(play_again_btn_sur, play_again_btn_tex, "assets/Game/others/play_again.png");
}


void gameRenderImage(SDL_Texture *&g_button_tex, SDL_Rect dstRect) {
    SDL_RenderCopy(renderer, g_button_tex, NULL, &dstRect);
}


void destroyIt(SDL_Surface *&g_button, SDL_Texture *&g_button_tex) {
    SDL_FreeSurface(g_button);
    SDL_DestroyTexture(g_button_tex);
}


void handleCheckBtnsClicks() {

    if (!mouse_click) return;
    if (game_page_state == "game") {
        bool menu_is_clicked = checkInOut(mouse_x, mouse_y, menu_btn_rect);
        if (menu_is_clicked) game_page_state = "pause_menu";
    } else if (game_page_state == "pause_menu") {
        bool menu_is_clicked = checkInOut(mouse_x, mouse_y, menu_btn_rect);
        if (menu_is_clicked) game_page_state = "game";
    } else if (game_page_state == "over") {
        bool main_menu_is_clicked = checkInOut(mouse_x, mouse_y, main_menu_btn_rect);
        bool play_again_is_clicked = checkInOut(mouse_x, mouse_y, play_again_btn_rect);
        if (main_menu_is_clicked) {
            cout << "Main is clicked!!" << endl;
        } else if (play_again_is_clicked) {
            cout << "Play again is clicked!!" << endl;
        }
    } else if (game_page_state == "win") {

    }

    mouse_click = false;
}


bool colorsAreTheSame(SDL_Color c1, SDL_Color c2) {
    return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b);
}


void setRandomColorForShootingBall(SDL_Color &color) {


    vector<int> available_colors = getAvailableColorsVector();
    if (available_colors.empty()) {
        cout << "ZERO!" << endl;
        return;
    }

    int i = rand() % available_colors.size();
    int random_number = available_colors[i];

    if (random_number == 0) {
        color = RED;
    } else if (random_number == 1) {
        color = CYAN;
    } else if (random_number == 2) {
        color = BLUE;
    } else if (random_number == 3) {
        color = PURPLE;
    } else if (random_number == 4) {
        color = GREEN;
    } else {
        color = YELLOW;
    }

}


int calculateBalls() {
    int n = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 12; j++) {
            // other types must be added
            if (balls[i][j].type == 'c' || balls[i][j].type == 't') {
                n++;
            }
        }
    }
    return n;
}


vector<int> getAvailableColorsVector() {

    vector<int> available_colors;
    int k = 0;
    bool l = true;
    while (l) {
        for (int j = 0; j <= 11; j++) {
            if (balls[k][j].type == 'c' || balls[k][j].type == 't') {
                l = false;
            }
        }
        k++;
    }
    k--;
    for (int i = k; i <= flag.i; i++) {
        for (int j = 0; j <= 11; j++) {
            if (available_colors.size() == 6) break;
            BALL ball = balls[i][j];

            if (ball.type != 'e' && ball.type != 's' && ball.type != 'f') {

                if (colorsAreTheSame(ball.color, RED)) {
                    if (!contains(available_colors, 0)) available_colors.push_back(0);
                } else if (colorsAreTheSame(ball.color, CYAN)) {
                    if (!contains(available_colors, 1)) available_colors.push_back(1);
                } else if (colorsAreTheSame(ball.color, BLUE)) {
                    if (!contains(available_colors, 2)) available_colors.push_back(2);
                } else if (colorsAreTheSame(ball.color, PURPLE)) {
                    if (!contains(available_colors, 3)) available_colors.push_back(3);
                } else if (colorsAreTheSame(ball.color, GREEN)) {
                    if (!contains(available_colors, 4)) available_colors.push_back(4);
                } else if (colorsAreTheSame(ball.color, YELLOW)) {
                    if (!contains(available_colors, 5)) available_colors.push_back(5);
                }
//                now only doing for first color , second color also can be added!
//                if(ball.type == 't'){
//                    if (colorsAreTheSame(ball.second_color, RED)) {
//                        if (!contains(available_colors, 0)) available_colors.push_back(0);
//                    } else if (colorsAreTheSame(ball.second_color, CYAN)) {
//                        if (!contains(available_colors, 1)) available_colors.push_back(1);
//                    } else if (colorsAreTheSame(ball.second_color, BLUE)) {
//                        if (!contains(available_colors, 2)) available_colors.push_back(2);
//                    } else if (colorsAreTheSame(ball.second_color, PURPLE)) {
//                        if (!contains(available_colors, 3)) available_colors.push_back(3);
//                    } else if (colorsAreTheSame(ball.second_color, GREEN)) {
//                        if (!contains(available_colors, 4)) available_colors.push_back(4);
//                    } else if (colorsAreTheSame(ball.second_color, YELLOW)) {
//                        if (!contains(available_colors, 5)) available_colors.push_back(5);
//                    }
//                }
            }

        }
    }

    return available_colors;
}


int colorToInt(SDL_Color color) {
    int i = 0;
    if (colorsAreTheSame(color, CYAN)) {
        i = 1;
    } else if (colorsAreTheSame(color, BLUE)) {
        i = 2;
    } else if (colorsAreTheSame(color, PURPLE)) {
        i = 3;
    } else if (colorsAreTheSame(color, GREEN)) {
        i = 4;
    } else if (colorsAreTheSame(color, YELLOW)) {
        i = 5;
    }
    return i;
}


void checkColorOfShootingBalls(BALL &ball) {

    vector<int> available_colors = getAvailableColorsVector();
    if (contains(available_colors, colorToInt(ball.color)) || flag.i <= 10) return;
    if (available_colors.empty()) {
        cout << "Problem!" << endl;
        return;
    }
    setRandomColorForShootingBall(ball.color);
    cout << "Changed!" << endl;

}


void drawSomeSections() {
    // shooter
    SDL_RenderDrawRect(renderer, &shooter_section);

    // draw pause menu button
    gameRenderImage(menu_btn_tex, menu_btn_rect);

}


void handleWin() {

    static bool run = false;
    if (run) return;
    // Blank out the renderer with all black
    SDL_SetRenderDrawColor(renderer, BLACK.r, BLACK.g, BLACK.b, 255);
    SDL_RenderClear(renderer);

    // drawing some parts
    // drawSomeSections();

    Mix_PlayChannel(-1, winningSound, 0);

    SDL_RenderCopy(renderer, bg, NULL, &bgRect);

    textRender(win_surface, win_texture, win_rect_src, win_rect,
               win_coor.i, win_coor.j, 0.6, "You popped all bubbles!");
    SDL_RenderCopy(renderer, win_texture, &win_rect_src, &win_rect);
    SDL_RenderPresent(renderer);

#ifdef _WIN32
    Sleep(3000);
#else
    sleep(3);
#endif


    showScore("win");


    run = true;
}


void handleGameOver() {

    static bool run = false;
    if (run) return;
    // Blank out the renderer with all black
    SDL_SetRenderDrawColor(renderer, BLACK.r, BLACK.g, BLACK.b, 255);
    SDL_RenderClear(renderer);

    // drawing some parts
    // drawSomeSections();

    Mix_PlayChannel(-1, losingSound, 0);

    SDL_RenderCopy(renderer, bg, NULL, &bgRect);


    textRender(loose_surface, loose_texture, loose_rect_src, loose_rect,
               loose_coor.i, loose_coor.j, 1.0, "Game Over!");
    SDL_RenderCopy(renderer, loose_texture, &loose_rect_src, &loose_rect);
    SDL_RenderPresent(renderer);

#ifdef _WIN32
    Sleep(3000);
#else
    sleep(3);
#endif

    showScore("loose");

    run = true;
}


void showScore(string type) {

    while (fell_balls > 0) {
        SDL_SetRenderDrawColor(renderer, BLACK.r, BLACK.g, BLACK.b, 255);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, bg, NULL, &bgRect);

        score += 15;
        textRender(score_surface, score_texture, score_rect_src, score_rect,
                   60, 300, 1.0, "Your final score: " + to_string(score));
        SDL_RenderCopy(renderer, score_texture, &score_rect_src, &score_rect);
#ifdef _WIN32
        Sleep(30);
#else
        usleep(30000);
#endif
        fell_balls--;
        SDL_RenderPresent(renderer);

    }


    // drawing buttons based on loose ore win state


//    if (type == "win") {
//        gameRenderImage(main_menu_btn_tex, main_menu_btn_rect_win);
//
//    } else {
//        gameRenderImage(main_menu_btn_tex, main_menu_btn_rect);
//        gameRenderImage(play_again_btn_tex, play_again_btn_rect);
//
//    }
//
//
//    SDL_RenderPresent(renderer);

}


#endif //BOUNCING_BALL_GAME_GAME_H