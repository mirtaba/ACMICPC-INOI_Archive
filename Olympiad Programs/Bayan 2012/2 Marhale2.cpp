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
#include <fstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <utility>

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

ofstream fout ("problem2.out");
ifstream fin ("problem2.in");

#define cin fin
#define cout fout

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 3000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL d[Maxn],s[Maxn],dis,ans,bak,N,K,maxe,T;

int main()
{
	ios::sync_with_stdio(0);
	cin >> T;
	while(T--)
	{
	    ans=0;
	    bak=0;
	    dis=0;
	    MEM(d,0);
	    MEM(s,0);
	    N=0;
	    K=0;
	    maxe=0;
	    cin >> N >> K;
	    FOR(i,0,N)
	    {
	        cin >> d[i];
	    }
	    FOR(i,0,N)
	    {
	        cin >> s[i];
	    }
        FOR(i,0,N)
	    {
	        dis+=d[i];
	        if(maxe < s[i])
                maxe=s[i];
            ans+=d[i];
            bak+=s[i];
            while(dis > bak)
            {
                ans+=K;
                bak+=maxe;
            }
            bak-=dis;
            dis=0;
	    }
        cout << ans << endl;
	}
    return 0;
}
