#ifndef BOUNCING_BALL_GAME_FILEMANAGE_H
#define BOUNCING_BALL_GAME_FILEMANAGE_H

void SetTheme(int whatTheme) {
    switch(whatTheme) {
        case 1:
            th = Jungle;
            break;
        case 2:
            th = Ocean;
            break;
        case 3:
            th = Space;
            break;
        default:
            th = th1;
            break;
    }
}

string locateFile(string mode, int level) {
    if(mode == "normal") {
        switch (level) {
            case 1:
                return "database/scores/normal/lvl1.txt";
                break;
            case 2:
                return "database/scores/normal/lvl2.txt";
                break;
            case 3:
                return "database/scores/normal/lvl3.txt";
                break;
            case 4:
                return "database/scores/normal/lvl4.txt";
                break;
            case 5:
                return "database/scores/normal/lvl5.txt";
                break;
        }
    }
    else if(mode == "timed") {
        switch (level) {
            case 1:
                return "database/scores/timed/lvl1.txt";
                break;
            case 2:
                return "database/scores/timed/lvl2.txt";
                break;
            case 3:
                return "database/scores/timed/lvl3.txt";
                break;
            case 4:
                return "database/scores/timed/lvl4.txt";
                break;
            case 5:
                return "database/scores/timed/lvl5.txt";
                break;
        }
    }
    else if(mode == "random") {
        return "database/scores/random.txt";
    }
    else if(mode == "infinite") {
        return "database/scores/inf.txt";
    }
}

void mergeSort(int a[], int low, int high) {
    if(high-low<1)
        return;
    int mid=(high+low)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    int *b=new int[high-low+1];
    int k=0, i=low, j=mid+1;
    while((i<=mid)&&(j<=high))
    {
        if(a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=high)
        b[k++]=a[j++];
    //copy to main array
    for(k=0;k<high-low+1;k++)
        a[low+k]=b[k];
    delete[] b;
}

void sinaSort(int n, string name[], string score[], string newName, int newScore) {
    int i;
    for(i = 0;i < n;i++) {
        if(stoi(score[i]) < newScore)
            break;
    }
    for(int j = n;j >= i;j--) {
        name[j+1] = name[j];
        score[j+1] = score[j];
    }
    name[i] = newName;
    score[i] = to_string(newScore);
}

void doTrim(int n, char flag, string source, string list[]) {
    for(int i = 0;i < n;i++) {
    }
}

int scoresReader(GAME_INF game,string name[], string score[]) {

    int n = 0;
    string tempNames = "", tempScores = "";
    string address = locateFile(game.mode, game.level);

    ifstream scores;
    scores.open(address);
    if (!scores.good()) {
        cout << "error opening scores file...";
        return 0;
    }

    scores >> n;
//    getline(scores, tempScores);
//    getline(scores, tempNames);
//    doTrim(n, ',', tempScores, score);
//    doTrim(n, ',', tempNames, name);

    for(int i = 0;i < n;i++) {
        scores >> score[i];
    }
    for(int i = 0;i < n;i++) {
        scores >> name[i];
    }

//    while(!scores.eof())
//    {
//        getline(scores, a[i]);
//        if(scores.good())
//            i++;
//    }

    scores.close();

    return n;
}

void scoresWriter(GAME_INF game) {


    int n;
    string name[MAX_ARRAY_SIZE], score[MAX_ARRAY_SIZE];
    n = scoresReader(game, name, score);

    sinaSort(n, name, score, game.user, game.score);
    n++;

    string address = locateFile(game.mode, game.level);
    ofstream scores;
    scores.open(address);

    if (!scores.good()) {
        cout << "error opening scores file...";
        return;
    }

    scores << n << endl;

    for (int i = 0; i < n && i < 10; i++) {
        scores << score[i] << " ";
    }
    scores << endl;
    for (int i = 0; i < n && i < 10; i++) {
        scores << name[i] << " ";
    }

    scores.close();
}

void settingReader() {

    ifstream settingfile;
    settingfile.open("./database/setting.txt");

    if (!settingfile.good()) {
        cout << "error opening setting file...";
        return;
    }

    int whatTheme;
    settingfile >> soundVolume;
    settingfile >> musicVolume;
    settingfile >> whatTheme;
    SetTheme(whatTheme);

    settingfile.close();
}

void settingWriter() {

    ofstream settingfile;
    settingfile.open("./database/setting.txt");

    if (!settingfile.good()) {
        cout << "error opening setting file...";
        return;
    }

    settingfile << soundVolume << endl;
    settingfile << musicVolume << endl;
    settingfile << th.num;
    settingfile.close();
}


#endif //BOUNCING_BALL_GAME_FILEMANAGE_H
