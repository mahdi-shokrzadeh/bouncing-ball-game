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

BALL end_pointer_ball = {
        .type = 'e',
        .color = RED,
        .center = {
                .x = 0,
                .y = 0,
        },
};


BALL gone_ball = {
        .type ='s',
        .color = RED,

        .center = {
                .x = 10000,
                .y = 20000,
        },
};


double degree = 180.0;
int targeter_balls_radius = 2;
double targeter_balls_dist = 9.0;



// variables related to balls

const int radius_of_balls = 20;
const int width_of_ball_box = 46;
double vertical_speed = 0.2;
double dist_from_left = 14.5;


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

vector<ELEMENT> findNeighbors(int i, int j);

void filterByColor(vector<ELEMENT> &elements, SDL_Color color);

void handleGraphCheck(int i, int j, SDL_Color color);

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
    // updating end_pointer_ball center
    end_pointer_ball.center.y += vertical_speed;


    // shooter
    SDL_Rect shooter_section = {10, 510, 580, 200};
    SDL_RenderDrawRect(renderer, &shooter_section);
    drawShootingBalls(shooter_ball, reserved_ball);


    // draw the end section
    if (end_pointer_ball.center.y >= -50){
        SDL_Rect r;
        r.x = 5;
        r.y = end_pointer_ball.center.y - 85;
        r.w = SCREEN_WIDTH-10;
        r.h = 50;
        SDL_SetRenderDrawColor( renderer, PLUM.r , PLUM.g , PLUM.b, 255 );
        SDL_RenderFillRect(renderer , &r);

    }


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

    //

    for (int j = 0; j < SCREEN_WIDTH / width_of_ball_box - 1; j++){
        end_pointer_ball.center.y = double(-(FINAL_COLUMNS - 5) * (width_of_ball_box));
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
                degree -= TARGETER_SPEED;
            break;
        case 1:
            if (degree <= 260)
                degree += TARGETER_SPEED;
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

                handleCollShooterAndBalls(ball, i, j);
                ball_is_being_thrown = false;
            }

        }

    }
}


void handleCollShooterAndBalls(BALL &ball, int i, int j) {
    if (!ball_is_being_thrown)return;
//    cout << balls[15][0].type<<endl;

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

                cout << "Right 2 <45" << endl;
            } else {
                // checking if ball is the last or first item of row
                if (j + 1 != 12) {
                    new_ball.center.x = double((j + 1) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                    new_ball.center.y = double(ball.center.y + width_of_ball_box);
                    balls[i - 1][j + 1] = new_ball;
                    el.i = i - 1;
                    el.j = j + 1;
                    cout << "DSDSF" << endl;

                } else {
                    new_ball.center.x = double((j) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                    new_ball.center.y = double(ball.center.y + width_of_ball_box);
                    balls[i - 1][j] = new_ball;
                    el.i = i - 1;
                    el.j = j;
                    cout << "Right 2" << endl;
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


                cout << "Left 2 <45" << endl;
            } else {
                new_ball.center.x = double((j) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                new_ball.center.y = double(ball.center.y + width_of_ball_box);
                balls[i - 1][j] = new_ball;
                el.i = i - 1;
                el.j = j;
                cout << "Left 2" << endl;
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
                    cout << "Right 1 <45" << endl;

                }


            } else {
                // checking if ball is the last or first item of row
                new_ball.center.x = double((j + 0.5) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                new_ball.center.y = double(ball.center.y + width_of_ball_box);
                balls[i - 1][j] = new_ball;
                el.i = i - 1;
                el.j = j;
                cout << "Right 1 " << endl;

            }

        } else {
            if (collision_degree < 45) {
                new_ball.center.x = double((j - 1) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                new_ball.center.y = ball.center.y;
                balls[i][j - 1] = new_ball;
                el.i = i;
                el.j = j - 1;
                cout << "LEFT 1 <45" << endl;

            } else {
                if (j + 1 != 1) {
                    new_ball.center.x = double((j - 0.5) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                    new_ball.center.y = double(ball.center.y + width_of_ball_box);
                    balls[i - 1][j - 1] = new_ball;
                    el.i = i - 1;
                    el.j = j - 1;
                    cout << "LEFT 1" << endl;

                } else {
                    new_ball.center.x = double((j + 0.5) * (width_of_ball_box) + radius_of_balls + dist_from_left);
                    new_ball.center.y = double(ball.center.y + width_of_ball_box);
                    balls[i - 1][0] = new_ball;
                    el.i = i - 1;
                    el.j = 0;
                    cout << "LEFT 1 ex" << endl;
                }

            }

        }

    }

//    handle graph
    handleGraphCheck(el.i, el.j, thrown_ball.color);
}

vector<ELEMENT> findNeighbors(int i, int j) {

    vector<ELEMENT> neighbors;

    if (i % 2 == 0) {
        if (j + 1 <= 11) {
            // checking the upper line
            if (balls[i + 1][j + 1].type != 's') neighbors.push_back({i + 1, j + 1});
            // checking the line
            if (balls[i][j + 1].type != 's') neighbors.push_back({i, j + 1});
            // checking the downer line
            if (balls[i - 1][j + 1].type != 's') neighbors.push_back({i - 1, j + 1});
        }

        if (balls[i + 1][j].type != 's') neighbors.push_back({i + 1, j});
        if (balls[i - 1][j].type != 's') neighbors.push_back({i - 1, j});

        if (j - 1 >= 0) {
            if (balls[i][j - 1].type != 's') neighbors.push_back({i, j - 1});
        }

    } else {
        if (j - 1 >= 0) {
            // checking the upper line
            if (balls[i + 1][j - 1].type != 's') neighbors.push_back({i + 1, j - 1});
            // checking the line
            if (balls[i][j - 1].type != 's') neighbors.push_back({i, j - 1});
            // checking the downer line
            if (balls[i - 1][j - 1].type != 's') neighbors.push_back({i - 1, j - 1});
        }

        if (balls[i + 1][j].type != 's') neighbors.push_back({i + 1, j});
        if (balls[i - 1][j].type != 's') neighbors.push_back({i - 1, j});

        if (j + 1 <= 11) {
            if (balls[i][j + 1].type != 's') neighbors.push_back({i, j + 1});
        }
    }

    return neighbors;
}


void filterByColor(vector<ELEMENT> &elements, SDL_Color color) {
    for (auto it = elements.begin(); it != elements.end();) {
        if (!(balls[it->i][it->j].color.r == color.r && balls[it->i][it->j].color.g == color.g &&
              balls[it->i][it->j].color.b == color.b)) {
            elements.erase(it);
        } else {
            ++it;
        }
    }
}

bool vectorContainsElement(const vector<ELEMENT> &elements, ELEMENT el) {
    for (ELEMENT e: elements) {
        if (e.i == el.i && e.j == el.j) return true;
    }
    return false;
}


void handleGraphCheck(int i, int j, SDL_Color color) {

//    cout << i << endl << endl;
    vector<ELEMENT> visited;
    vector<ELEMENT> queue;

    ELEMENT zero;
    zero.i = i;
    zero.j = j;

    queue.push_back(zero);

    while (!queue.empty()) {

        ELEMENT el = queue[0];
        vector<ELEMENT> vec = findNeighbors(el.i, el.j);
        filterByColor(vec, color);

        visited.push_back(el);
        for (ELEMENT el2: vec) {
            if (!vectorContainsElement(visited, el2)) queue.push_back(el2);
//            cout << el2.i << " " << el2.j << endl;
        }

        queue.erase(queue.begin());

    }


    if (visited.size() > LEAST_BALLS_NUMBER) {
        for (ELEMENT el: visited) {
            balls[el.i][el.j] = gone_ball;
        }
    }


}


#endif //BOUNCING_BALL_GAME_GAME_H