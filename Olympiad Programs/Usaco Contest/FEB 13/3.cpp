/*
ID: ghoolha1
PROG: perimeter
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
#define FOR(i,a,b) for(int i=a;i<b;i++)
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

const int Maxn = 100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

ofstream fout ("perimeter.out");
ifstream fin ("perimeter.in");

#define cin fin
#define cout fout

long mat[Maxn][Maxn],N,ans;

int fill(int x,int y)
{
    mat[x][y]=1;
    if (x>0)
    {
        if (mat[x-1][y]==2)
        {
            ans++;
        }
        else
        if (mat[x-1][y]==0)
            fill(x-1,y);
    }
    if (x<101)
    {
        if (mat[x+1][y]==2)
        {
            ans++;
        }
        else
        if (mat[x+1][y]==0)
            fill(x+1,y);
    }
    if(y>0)
    {
        if (mat[x][y-1]==2)
        {
            ans++;
        }
        else
        if (mat[x][y-1]==0)
            fill(x,y-1);
    }
    if(y<101)
    {
        if (mat[x][y+1]==2)
        {
            ans++;
        }
        else
        if (mat[x][y+1]==0)
            fill(x,y+1);
    }
    return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	long tmp1,tmp2;
	FOR(i,0,N)
	{
	    cin >> tmp1 >> tmp2;
	    mat[tmp1][tmp2]=2;
	}
	fill(0,0);
	cout << ans << endl;
}
