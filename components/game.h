#ifndef BOUNCING_BALL_GAME_GAME_H
#define BOUNCING_BALL_GAME_GAME_H

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

BALL sample_ball = {

        .type ='s',
        .color = RED,

        .center = {
                .x = 0,
                .y = 0,
        },
};

double degree = 180.0;
int targeter_balls_radius = 2;
double targeter_balls_dist = 9.0;



// variables related to balls

const int radius_of_balls = 20;
const int width_of_ball_box = 45;
double vertical_speed = 0.2;
double dist_from_left = 12.5;


// Initializing balls

BALL balls[MAX_NUMBER_OF_COLUMNS][12] = {0};

// Game
void setRandomColor(SDL_Color &color);

void initializeBalls();

void initializeShootingBalls(BALL &shooter_ball, BALL &reserved_ball);

void swapShootingBalls(BALL &shooter_ball, BALL &reserved_ball);

void drawShootingBalls(BALL shooter_ball, BALL reserved_ball);

void drawTargeter();

void handleTargeterEvent(int type);

bool checkCollTargeterAndBalls(DOUBLE_POINT targeter_point);

double calculateDistance(DOUBLE_POINT a, DOUBLE_POINT b);

void handleShootBall(BALL &shooting_ball, BALL &reserved_ball);

void handleBallShooting();

void Game(BALL shooter_ball, BALL reserved_ball);

void checkCollShooterAndBalls();

void handleCollShooterAndBalls(BALL &ball, int i, int j);



// ---------------------------------------------------



void Game(BALL shooter_ball, BALL reserved_ball) {

    // targeter

    drawTargeter();

    // drawing balls

    for (int i = 0; i < FINAL_COLUMNS; i++) {
        for (int j = 0; j < 12; j++) {
            if (balls[i][j].type != 's') {
                BALL &ball = balls[i][j];
                ball.center.y += vertical_speed;
                aacircleRGBA(renderer, Sint16(ball.center.x), Sint16(ball.center.y), radius_of_balls,
                             ball.color.r, ball.color.g, ball.color.b, 255);

            }
        }
    }

    // shooter
    SDL_Rect shooter_section = {10, 510, 580, 200};
    SDL_RenderDrawRect(renderer, &shooter_section);
    drawShootingBalls(shooter_ball, reserved_ball);


    // handle ball shooting

    if (ball_is_being_thrown) {
        handleBallShooting();
        checkCollShooterAndBalls();
    }


    SDL_RenderPresent(renderer);
}


void initializeBalls() {
    for (int i = 1; i <= FINAL_COLUMNS; i++) {
        for (int j = 0; j < SCREEN_WIDTH / width_of_ball_box - 1; j++) {
            if (i <= ESCAPE_FOR_BALLS_ARRAY) {
                balls[i - 1][j] = sample_ball;
            } else {
                BALL ball = {
                        .type='c',
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
                setRandomColor(ball.color);

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
            color = AQUA;
            break;
        default :
            color = YELLOW;
    }
}


void initializeShootingBalls(BALL &shooter_ball, BALL &reserved_ball) {
    shooter_ball.type = 'c';
    reserved_ball.type = 'c';
    shooter_ball.center.x = center_of_shooting_ball.x;
    shooter_ball.center.y = center_of_shooting_ball.y;

    reserved_ball.center.x = center_of_reserved_ball.x;
    reserved_ball.center.y = center_of_reserved_ball.y;

    setRandomColor(shooter_ball.color);
    setRandomColor(reserved_ball.color);
    while (reserved_ball.color.r == shooter_ball.color.r) setRandomColor(reserved_ball.color);

}


void swapShootingBalls(BALL &shooter_ball, BALL &reserved_ball) {
    swap(shooter_ball.color, reserved_ball.color);
//    cout << shooter_ball.color.r << " " ;
}


void drawShootingBalls(BALL shooter_ball, BALL reserved_ball) {

    aacircleRGBA(renderer, Sint16(shooter_ball.center.x),
                 Sint16(shooter_ball.center.y),
                 radius_of_balls, shooter_ball.color.r,
                 shooter_ball.color.g, shooter_ball.color.b, 255);

    aacircleRGBA(renderer, Sint16(reserved_ball.center.x), Sint16(reserved_ball.center.y), radius_of_balls,
                 reserved_ball.color.r, reserved_ball.color.g, reserved_ball.color.b, 255);
//    SDL_RenderPresent(renderer);
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

            aacircleRGBA(renderer, Sint16(targeter_point.x), Sint16(targeter_point.y),
                         Sint16(targeter_balls_radius),
                         SILVER.r, SILVER.g, SILVER.b, 255);
        }

        targeter_point.y += dy;
        targeter_point.x += dx;
    }

}

void handleTargeterEvent(int type) {
    switch (type) {
//        case 0:
//            targeter_vertical_speed -= 0.5;
//            break;
//        case 1:
//            targeter_vertical_speed += 0.5;
//        break;
        case 0:
            if (degree >= 100)
                degree -= 0.5;
            break;
        case 1:
            if (degree <= 260)
                degree += 0.5;
            break;
        default:
            break;
    }
}

bool checkCollTargeterAndBalls(DOUBLE_POINT targeter_point) {

    for (int i = 0; i < FINAL_COLUMNS; i++) {
        for (int j = NUMBER_OF_BALLS_IN_EACH_COL - 1; j >= 0; j--) {
            BALL &ball = balls[i][j];
            if (ball.center.y <= -10) return false;
            if (calculateDistance(ball.center, targeter_point) <= radius_of_balls + 15) return true;

        }

    }

}


double calculateDistance(DOUBLE_POINT a, DOUBLE_POINT b) {
    return sqrt((a.y - b.y) * (a.y - b.y) +
                (a.x - b.x) * (a.x - b.x));
}


void handleShootBall(BALL &shooting_ball, BALL &reserved_ball) {

    if (!ball_is_being_thrown) {
        ball_is_being_thrown = true;
        thrown_ball = shooting_ball;
        shooting_ball = reserved_ball;
        shooting_ball.center = center_of_shooting_ball;
        reserved_ball.center = center_of_reserved_ball;
        shooting_ball.type = 'c';
        reserved_ball.type = 'c';
        setRandomColor(reserved_ball.color);
        while (reserved_ball.color.r == shooting_ball.color.r) setRandomColor(reserved_ball.color);
        dxOfThrownBall = sin(degree * M_PI / 180.0) * SPEED_OF_THROWN_BALL;
        dyOfThrownBall = cos(degree * M_PI / 180.0) * SPEED_OF_THROWN_BALL;
        drawShootingBalls(shooting_ball, reserved_ball);
    }


}

void handleBallShooting() {

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

    aacircleRGBA(renderer, Sint16(thrown_ball.center.x), Sint16(thrown_ball.center.y),
                 Sint16(radius_of_balls), thrown_ball.color.r, thrown_ball.color.g, thrown_ball.color.b, 255);

}


void checkCollShooterAndBalls() {
    for (int i = 0; i < FINAL_COLUMNS; i++) {
        for (int j = NUMBER_OF_BALLS_IN_EACH_COL - 1; j >= 0; j--) {
            BALL &ball = balls[i][j];
            if (calculateDistance(ball.center, thrown_ball.center) <= radius_of_balls * 2) {
                // ball is being thrown
                ball_is_being_thrown = false;
                handleCollShooterAndBalls(ball, i, j);
            }

        }

    }
}


void handleCollShooterAndBalls(BALL &ball, int i, int j) {

    BALL new_ball;

    // only positioning
    if (i % 2 == 0) {
        if(atan((ball.center.x-thrown_ball.center.x)/(ball.center.y-thrown_ball.center.y))* 180 / M_PI < 90){
            new_ball.type='c';
            new_ball.center.x = double((j) * (width_of_ball_box) + radius_of_balls + dist_from_left);
            new_ball.center.y =  double(ball.center.y + width_of_ball_box);
            new_ball.color = thrown_ball.color;
            balls[i-1][j-1] = new_ball;
        }

    } else {

    }

}

#endif //BOUNCING_BALL_GAME_GAME_H