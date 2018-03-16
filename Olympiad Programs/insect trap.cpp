#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

const int Maxn=100*10+100;
int n,chob[Maxn],Max,Maxi,add;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> chob[i];
        if (chob[i] > Max)
        {
            Max=chob[i];
            Maxi=i;
        }
    }
    for (int i=0;i<n;i++)
    {
        if (i!=Maxi)
        {
            add+=chob[i];
        }
    }
    if (add > chob[Maxi])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
