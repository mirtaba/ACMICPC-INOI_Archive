/*
ID: ghoolha1
PROG: greetings
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

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int N,tp,up,ans;
vector <int>one,two;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	FOR(i,0,N)
	{
	    cin >> tp;
	    if (tp==1)
        {
            cin >> tp;
            one.pb(tp);
            ans++;
        }
        else
        {
            cin >> tp;
            two.pb(tp);
            ans+=2;
        }
	}
	sort(one.begin(),one.end(),greater<int>());
	sort(two.begin(),two.end(),greater<int>());
	for(int i=(two.size()-1);i>=0;i--)
	{
	    if (two[i]<=(one[one.size()-1]+one[one.size()-2]))
        {
            if ((ans-2)>=(two[i]))
            {
                ans-=2;
                two.pop_back();
            }
        }
        else
        {
            if ((ans-(2))>=(one[one.size()-1]+one[one.size()-2]))
            {
                ans-=2;
                one.pop_back();
                one.pop_back();
            }

        }
	}
	while( (ans-1)>=one[one.size()-1] || (ans-2)>=two[two.size()-1] )
    {
        if (two[two.size()-1]<=(one[one.size()-1]))
        {
            if ((ans-2)>=(two[two.size()-1]))
            {
                ans-=2;
                two.pop_back();
            }
        }
        else
        {
            if ((ans-(1))>=(one[one.size()-1]))
            {
                ans-=1;
                one.pop_back();
            }
        }
    }
    cout << ans << endl;
    return 0;
}
