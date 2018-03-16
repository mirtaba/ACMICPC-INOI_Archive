/*
ID: ghoolha1
PROG: greetings
LANG: C++
*/
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
#include <fstream>

#define MAX(a,b) (((a) > (b))? (a) : (b))
#define MIN(a,b) (((a) < (b))? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
#define FOR(i,a,b) for(LL i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 5 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int m[Maxn][Maxn],d[Maxn][Maxn],a;
int Ans,tx,ty;


bool ch()
{
    /**/
    FOR(i,0,5)
    {
        FOR(j,0,5)
        {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    /**/
    FOR(i,0,5)
    {
        FOR(j,0,5)
        {
            d[i][j]=Mod;
        }
    }
    d[0][0]=m[0][0];
    FOR(i,0,5)
    {
        FOR(j,0,5)
        {

            if(i>0)
            {
                if (!(m[i][j]==1 && m[i][j]==m[i-1][j]))
                {
                    d[i][j]=min(d[i][j],d[i-1][j]+m[i][j]);
                }
            }
            if(j>0)
            {
                if (!(m[i][j]==1 && m[i][j]==m[i][j-1]))
                {
                    d[i][j]=min(d[i][j],d[i][j-1]+m[i][j]);
                }
            }
        }
    }
    //cerr << d[4][4] << endl;
    if(d[4][4]<3)
    {
        Ans++;
    }

}

void ba(int x,int y)
{
    a++;
    if(x==4 && y==4)
    {
        m[x][y]=0;
        ch();
        m[x][y]=1;
        ch();
    }
    else
    {
        tx=x;
        ty=y;
        tx++;
        if(tx==5)
        {
            tx=0;
            ty++;
        }
        m[x][y]=0;
        ba(tx,ty);
        m[x][y]=1;
        ba(tx,ty);
    }
}

int main()
{
	ios::sync_with_stdio(0);
    ba(0,0);
    cout << a << endl;
    cout << Ans << endl;
}
