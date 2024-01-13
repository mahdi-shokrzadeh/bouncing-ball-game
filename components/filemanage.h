#ifndef BOUNCING_BALL_GAME_FILEMANAGE_H
#define BOUNCING_BALL_GAME_FILEMANAGE_H

void scoresReader() {

    ifstream scores;
    scores.open("..\\assets\\scores.txt");
    //scores.open("/Users/sina/CLionProjects/bouncing-ball-game/assets/scores.txt");

    int n = 0;
    string a[100];
    if (scores.good()) {
        scores >> n;
        for (int i = 0; i < n; i++)
            getline(scores, a[i]);
        scores.close();

        //bubbleSort(a, n);
    }
    else {
        cout << "error opening scores file...";
    }

    for(int i = 0;i < n;i++)
        cout << a[i] << " ";
    cout << endl;

    /*
    ifstream in("..\\files\\input.txt");
    if(in.good())
    {
        int a[MAX_DIM], i=0;
        while(!in.eof())
        {
            in>>a[i];
            if(in.good())
            {
                cout<<a[i]<<"\t";
                i++;
            }
        }
        in.close();

    }
    else
    {
        cout<<"error...";
    }*/

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
