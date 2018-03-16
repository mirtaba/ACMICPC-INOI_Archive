/*
ID: ghoolha1
PROG: greetings
LANG: C++
*/

//0HFx7PLqzGxSfN59j3UHmR

/*
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
*/

#include <bits/stdc++.h>

#define MAX(a,b) (((a) > (b))? (a) : (b))
#define MIN(a,b) (((a) < (b))? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define RFOR(i,a,b) for(int i=a;i>b;i--)
#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second
#define Traxe(X) cerr << #X << " = " << X << endl
#define _ << " _ " <<


using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100 +5;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");
//#define cin fin
//#define cout fout

int mat[Maxn][Maxn];
int d[Maxn][Maxn][Maxn][Maxn];
int n , m , tmp1 , tmp2;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	MEM(mat,0);
	FOR(i,0,m)
	{
	    cin >> tmp1 >> tmp2;
        mat[tmp1][tmp2]++;
	}
	int ans = n*n + 10;
    RFOR(x,n-1,-1)
    {
        RFOR(y,n-1,-1)
        {
            FOR(i,x,n)
            {
                FOR(j,y,n)
                {
                    if(x == i && y == j)
                        d[x][y][i][j] = ( (mat[i][j]>0)? 1 : 0);
                    else
                    {
                        d[x][y][i][j] = d[x][y][i-1][j-1]+d[i][y][i][j-1]+d[x][j][i-1][j]+d[i][j][i][j];
                        if((m) == ((i-x+1)*(j-y+1)))
                        {
                            ans = min (ans , m-d[x][y][i][j]);
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;


}
