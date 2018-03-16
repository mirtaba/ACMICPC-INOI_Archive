/*
ID: ghoolha1
PROG: numtri
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <utility>

using namespace std;

ofstream fout ("numtri.out");
ifstream fin ("numtri.in");

#define cin fin
#define cout fout

const int MaxR=(10*100)+50;

int input[MaxR][MaxR],output[MaxR][MaxR],R,answer;

int main()
{
    //ios::sync_with_stdio(0);

    cin >> R;
    for (int i=1;i<(R+1);i++)
    {
        for (int j=1;j<=i;j++)
            cin >> input[i][j];
    }

    /**/

    for (int i=1;i<(R+1);i++)
    {
        for (int j=1;j<=i;j++)
            output[i][j]=max(output[i-1][j]+input[i][j],output[i-1][j-1]+input[i][j]);
    }
    for (int i=1;i<=(R);i++)
    {
        answer = (answer < output[R][i]) ? output[R][i] : answer;
    }

    /**

    for (int i=1;i<(R+1);i++)
    {
        for (int j=1;j<=i;j++)
            cout << input[i][j];
        cout << endl;
    }

    /**

    for (int i=1;i<(R+1);i++)
    {
        for (int j=1;j<=i;j++)
            cout << output[i][j] << ' ';
        cout << endl;
    }

    /**/
    cout << answer << endl;
}

