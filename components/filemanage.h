#ifndef BOUNCING_BALL_GAME_FILEMANAGE_H
#define BOUNCING_BALL_GAME_FILEMANAGE_H

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

    return i;
}
/*
void scoresWriter() {

    ofstream shalgham;
    shalgham.open("..\\files\\output.txt", ios::app);
    if (shalgham.good()) {
        for (int i = 0; i < n; i++)
            shalgham << a[i] << "\t";
        shalgham << endl;
        shalgham.close();
    } else {
        cout << "error writing output file...";
    }

}
*/
#endif //BOUNCING_BALL_GAME_FILEMANAGE_H
