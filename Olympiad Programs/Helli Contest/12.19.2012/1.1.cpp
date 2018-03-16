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

LL in[Maxn],mark[Maxn],N,cnt,ans,t=1,maxe,pos[Maxn];
bool flag;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	FOR(i,1,N+1)
	{
	    cin >> in[i];
	    if (in[i]==i)
	    {
            mark[i]=(1e10);
            cnt++;
	    }
	}
    while(cnt<N)
    {
        ans++;
        FOR(j,1,N+1)
        {
            if(mark[j]==0)
            {
                maxe=j;
                t=j;
                break;
            }
        }
        while(mark[t]==0)
        {
            //cerr << t+1 << ' ' << ans <<  endl;
            mark[t]=ans;
            t=in[t];
            cnt++;
        }
    }
    FOR(i,0,N)
    {
        cerr << mark[i] << ' ';
        if (mark[i]==3)
        {
            cout << i <<  ' ' << in[i] << endl;
        }
    }

    cerr << endl;
    cout << ans << endl;
    return 0;
}

