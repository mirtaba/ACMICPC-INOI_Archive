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

string S;
vector <int> in;
bool flag=false,flag2=false,flag3=false;

int main()
{
	ios::sync_with_stdio(0);
	cin >> S;
	FOR(i,0,S.size())
	{
	    if(S[i]=='1')
	    {
	        flag2=true;
	        in.pb(1);
	    }
	    else
	    {
	        flag3=true;
	        if (flag2)
	        {
                if(!flag)
                {
                    flag=true;
                    continue;
                }
                else
                {
                    in.pb(0);
                }
	        }
	    }
	}
	if(flag3)
	{
        FOR(i,0,in.size())
        {
            cout << in[i];
        }
	}
	else
	{
	    FOR(i,0,in.size()-1)
        {
            cout << in[i];
        }
	}
    cout << endl;
	return 0;
}
