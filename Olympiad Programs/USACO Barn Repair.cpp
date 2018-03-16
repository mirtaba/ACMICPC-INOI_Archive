/*
ID: ghoolha1
PROG: barn1
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

ofstream fout ("barn1.out");
ifstream fin ("barn1.in");

#define cin fin
#define cout fout

const int Maxs=(2*100)+20;
int stall [Maxs],M,S,C,stallans[Maxs];
bool compare (int i,int j) { return (i>j); }

int main()
{
    cin >>  M >> S >> C;
    for (int i=0;i<C;i++)
    {
        cin >> stall[i];
    }
    sort(stall,stall+C);
    for (int i=0;i<(C-1);i++)
    {
        stallans[i]=((stall[i+1]-stall[i])-1);
    }
    sort(stallans,stallans+C-1,compare);
    int answer =stall[C-1]-stall[0]+1;
    for (int i=0;i<(M-1);i++)
    {
        answer-=(stallans[i]);
    }
    cout << answer <<endl;
}
