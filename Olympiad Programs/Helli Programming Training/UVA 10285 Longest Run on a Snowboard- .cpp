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

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL d[Maxn][Maxn],in[Maxn][Maxn],N,M,query,answer;
string str;
int axis[2][4] = {0,1,0,-1,1,0,-1,0};

void init()
{
    MEM(in,0x1f);
	MEM(d,-1);
	answer=0;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			cin >> in[i][j];
		}
	}
}

LL anser(LL i,LL j)
{
    if(i < 1 || i > N || j < 1 || j > M)
        return 0;
	if(d[i][j] >= 0)
        return d[i][j];
    LL tmp = 0;
	for(int k = 0; k < 4; k++)
	{
		LL tx = i + axis[0][k];
		LL ty = j + axis[1][k];
		if(in[i][j] > in[tx][ty])
		{
			tmp = max(tmp,(anser(tx,ty)+1));
		}
	}
	d[i][j] = tmp;
	if(d[i][j] == 0)
        d[i][j] = 1;
	return d[i][j];
}

int main()
{
    cin >> query;
    while (query--)
    {
        cin >> str >> N >> M;
        init();
        for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= M; j++)
			{
				answer = MAX(answer,anser(i,j));
			}
		}
		cout << str << ": " << answer << endl;
    }
    return 0;
}
