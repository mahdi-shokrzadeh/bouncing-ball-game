#ifndef BOUNCING_BALL_GAME_FILEMANAGE_H
#define BOUNCING_BALL_GAME_FILEMANAGE_H

int scoresReader(string a[]) {

    ifstream scores;
    //scores.open(".\\assets\\scores.txt");
    scores.open("./assets/scores.txt");

    int i = 0;
    if (!scores.good()) {
        cout << "error opening scores file...";
        return 0;
    }

    while(!scores.eof())
    {
        getline(scores, a[i]);
        if(scores.good())
            i++;
    }

    scores.close();

    return i + 1;
}

void scoresWriter(string name, int score) {

    int n;
    string a[100];
    n = scoresReader(a);

    ofstream scores;
    //scores.open(".\\assets\\scores.txt");
    scores.open("./assets/scores.txt");

    if (!scores.good()) {
        cout << "error opening scores file...";
        return;
    }

    for (int i = 0; i < n; i++) {
        scores << a[i] << endl;
    }
    scores << score << " " << name;
    scores.close();
}

void settingReader(int &soundVolume, int &musicVolume, string &whatTheme) {

    ifstream setting;
    //scores.open(".\\assets\\setting.txt");
    setting.open("./assets/setting.txt");

    int i = 0;
    if (!setting.good()) {
        cout << "error opening scores file...";
        return;
    }

    setting >> soundVolume;
    setting >> musicVolume;
    setting >> whatTheme;

    setting.close();
}

void settingWriter(int soundVolume, int musicVolume, string whatTheme) {

    ofstream setting;
    //scores.open(".\\assets\\setting.txt");
    setting.open("./assets/setting.txt");

    if (!setting.good()) {
        cout << "error opening scores file...";
        return;
    }

    setting << soundVolume << endl;
    setting << musicVolume << endl;
    setting << whatTheme;
    setting.close();
}


#endif //BOUNCING_BALL_GAME_FILEMANAGE_H
