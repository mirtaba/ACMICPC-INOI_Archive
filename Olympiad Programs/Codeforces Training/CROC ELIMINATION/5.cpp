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

LL ans;
string s;
set <LL> in , out;

int main()
{
	ios::sync_with_stdio(0);
	cin >> s;
	FOR(i,0,s.size())
	{
        if (s[i]=='+')
        {
            if ( out.size())
            {
                in.insert(*out.begin());
                out.erase(out.begin());
            }
            else
            {
                in.insert(i);
                ans++;
            }
        }
        else
        {
            if ( in.size())
            {
                out.insert(*in.begin());
                in.erase(in.begin());
            }
            else
            {
                out.insert(i);
                ans++;
            }

        }
	}
	cout << ans << endl;
}
