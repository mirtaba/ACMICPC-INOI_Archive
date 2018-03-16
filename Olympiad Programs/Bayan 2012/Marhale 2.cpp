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
#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second

using namespace std;

ofstream fout ("problem1.out");
ifstream fin ("problem1.in");

#define cin fin
#define cout fout

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

char ch;
LL T,N;
bool in[Maxn];
LL op,cl,ans;

int main()
{
	ios::sync_with_stdio(0);
	cin >> T;
	while(T--)
	{
	    ans=0;
	    op=0;
	    cin >> N;
	    FOR(i,0,N)
	    {
	        cin >> ch;
	        if (ch==')')
	        {
                if (op==0)
                    ans++;
                else
                    op--;
	        }
	        else
	        {
	            op++;
	        }
	    }
	    ans+=op;
	    cout << ans << endl;
	}

}
