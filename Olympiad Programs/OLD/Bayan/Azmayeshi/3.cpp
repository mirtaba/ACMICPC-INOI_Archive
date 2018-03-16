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
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second

using namespace std;


ofstream fout ("problem3.out");
ifstream fin ("problem3.in");

#define cin fin
#define cout fout

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 100*100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL a,b,N,sum,ans;
vector <LL> S;
bool mark[Maxn*Maxn+200000];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	while(N--)
	{
	    ans=0;
	    S.clear();
	    cin >> a;
	    MEM(mark,0);
	    FOR(i,0,a)
	    {
            cin >> b;
            S.pb(b);
	    }
	    FOR(i,0,a)
	    {
	        FORE(j,0,i)
	        {
	            sum=0;
	            FORE(k,j,i)
	            {
                    sum+=S[k];
	            }
	            if(!mark[sum])
	            {
                    mark[sum]=true;
                    ans++;
	            }
	        }
	    }
	    cout << ans << endl;
	}
	return 0;
}
