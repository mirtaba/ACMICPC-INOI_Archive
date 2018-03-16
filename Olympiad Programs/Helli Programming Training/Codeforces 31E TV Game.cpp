#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

const int Maxn=18+2;

long long worth[2*Maxn],N,d[Maxn][Maxn];
//d[number of choices of first player][number of choices of second player]=the must worth with these number of choices
string S;

int main()
{
    cin >> N;
    worth[1]=1;
    for (int i=2;i<=(N);i++)
        worth[i]=10*worth[i-1];
    cin >> S;
    for(int i=0;i<=N;i++)
    {
        for (int j=0;j<=N;j++)
        {
            if(i>0)
                d[i][j]=max(d[i][j],d[i-1][j]+((S[2*N-i-j]-'0')*worth[i]));
            if(j>0)
                d[i][j]=max(d[i][j],d[i][j-1]+((S[2*N-i-j]-'0')*worth[j]));
        }
    }
    cerr << d[1][1] << endl;
    /*for (int i=1;i<=N;i++)
        cerr << worth[i] << ' ';
    cerr << endl;*/
    /*for(int i=0;i<=N;i++)
    {
        for (int j=0;j<=N;j++)
        {
            cerr << d[i][j] << ' ';
        }
        cerr << endl;
    }*/
    unsigned long long chfihomer=N;
    unsigned long long chfimarge=N;
    for(int i=0;i<2*N;i++)
    {
        if(chfihomer>0 && (d[chfihomer][chfimarge]==(d[chfihomer-1][chfimarge]+(worth[chfihomer]*(S[2*N-chfihomer-chfimarge]-'0')))))
        {
            cout <<'H';
            chfihomer--;
        }
        else
        {
            cout <<'M';
            chfimarge--;
        }
    }
    cout<<endl;
}
