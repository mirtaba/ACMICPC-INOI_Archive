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

const int Maxn = 1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

string S;
char t;
int score[Maxn],k=2,ans;

int main()
{
	ios::sync_with_stdio(0);
	FOR(i,65,80)
	{
	    if (i%3==2)
	    {
	        k++;
	    }
	    score[i]=k;
	}
	k++;
	FOR(i,80,84)
	{
	    score[i]=k;
	}
	k++;
	FOR(i,84,87)
	{
	    score[i]=k;
	}
	k++;
	FOR(i,87,91)
	{
	    score[i]=k;
	}
	cin >> S;
	FOR(i,0,S.size())
	{
	    t=S[i];
	    ans+=score[int(t)];
	}
	cout << ans << endl;
}
