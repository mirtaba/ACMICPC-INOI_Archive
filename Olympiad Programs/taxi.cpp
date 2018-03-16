#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN=100*100*10+100;

long long N;
int s[MAXN];
int groper[4];
int counter=0;

int main ()
{
    cin >> N;
    for (int i=0;i<N;i++)
    {
        cin >> s[i];
        if (s[i]==4)
            groper[0]++;
        else
        if (s[i]==3)
            groper[3]++;
        else
        if (s[i]==2)
            groper[2]++;
        else
        if (s[i]==1)
            groper[1]++;
    }
    /**
    for (int i=0;i<4;i++)
        cout << groper[i] << ' ';
    /**/
    counter += ( groper[0]);
    if (groper[3]>groper[1])
    {
        groper[3]=(groper[3]-groper[1]);
        counter+=(groper[1]);
        groper[1]=0;
    }
    else
    {
        groper[1]=(groper[1]-groper[3]);
        counter+=(groper[3]);
        groper[3]=0;
    }
    counter+=groper[3];
    counter+=((groper[2])/2);
    groper[2]=(groper[2]%2);
    if (groper[2]==1)
    if (groper[1]>2)
    {
        counter++;
        groper[2]=0;
        groper[1]=(groper[1]-3);
    }
    else
    {
        counter++;
        groper[2]=0;
        groper[1]=0;

    }
    counter += (groper[1]/4);
    groper[1] = groper[1]-(4*(groper[1]/4));
    if (groper[1] > 0)
        counter ++;
    cout << counter << endl;
}
