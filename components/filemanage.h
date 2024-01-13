#ifndef BOUNCING_BALL_GAME_FILEMANAGE_H
#define BOUNCING_BALL_GAME_FILEMANAGE_H

void SetTheme(int whatTheme) {
    switch(whatTheme) {
        case 1:
            th = th1;
            break;
    }
}

int scoresReader(string a[]) {

    ifstream scores;
    scores.open(".\\assets\\scores.txt");
    //scores.open("./assets/scores.txt");

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
    scores.open(".\\assets\\scores.txt");
    //scores.open("./assets/scores.txt");

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

void settingReader() {

    ifstream settingfile;
    settingfile.open(".\\assets\\setting.txt");
    //setting.open("./assets/setting.txt");

    if (!settingfile.good()) {
        cout << "error opening scores file...";
        return;
    }

    int whatTheme;
    settingfile >> soundVolume;
    settingfile >> musicVolume;
    settingfile >> whatTheme;
    SetTheme(whatTheme);

    settingfile.close();
}

void settingWriter(int soundVolumeSet, int musicVolumeSet, int whatTheme) {

    ofstream settingfile;
    settingfile.open(".\\assets\\setting.txt");
    //setting.open("./assets/setting.txt");

    if (!settingfile.good()) {
        cout << "error opening scores file...";
        return;
    }

    settingfile << soundVolumeSet << endl;
    settingfile << musicVolumeSet << endl;
    settingfile << whatTheme;
    settingfile.close();
}


#endif //BOUNCING_BALL_GAME_FILEMANAGE_H
