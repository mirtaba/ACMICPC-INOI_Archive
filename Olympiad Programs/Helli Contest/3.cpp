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

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL N,tmp,tmp2,ans;
LL T,zero,one,it;
vector <int> s;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	while(N--)
	{
	    s.clear();
	    ans=0;
	    cin >> T;
	    while(T>0)
	    {
	        s.pb(T%2);
	        T/=2;
	    }
	    s.pb(0);
	    s.pb(0);
	    s.pb(0);
	    s.pb(0);
	    if (s[0] && s[1]==0)
	    {
	        ans++;
	    }
	    FOR(i,1,s.size()+3)
	    {
	        if (s[i]==1 && (s[i-1]==0 && s[i+1]==0))
	        {
	            /*
                FOR(i,0,s.size())
                {
                    cerr << s[i];
                }
                cerr << endl;
                cerr << "------------" << endl;
                */
	            ans++;
	            s[i]=0;
	        }
	        else
	        if (s[i]>1)
	        {
	            s[i]=0;
	            s[i+1]++;
	        }
	        else
	        if (s[i-1]==1 && s[i]==1)
	        {
	            /*
	            FOR(i,0,s.size())
                {
                    cerr << s[i];
                }
                cerr << endl;
                cerr << "------------" << endl;
                */
	            ans++;
	            s[i]=0;
	            s[i-1]=0;
	            s[i+1]++;
	        }
	    }
	    cout << ans << endl;
	}
}

