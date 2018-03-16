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

LL tmp,N,K,ans,s,f,ances,tmp2;
bool flag;
int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> K;
	tmp =( (K*(K-1)) / 2 )+1;
	if (tmp>=N)
	{
	    f=K;s=0;
	    while (f-s>0)
	    {
	        //cerr << "HaHa" << endl;
	        if (flag)
	        {
	            cout << ans+1 << endl;
	            return 0;
	        }
	        ans=(f-((s+f)/2));
	        tmp=((s+f)/2);
	        tmp=(((f*(f+1))-(tmp*(tmp+1)))/2);
	        tmp-=(ans-1);
	        if (tmp==N)
	        {
	            cout << ans << endl;
	            return 0;
	        }
	        if (tmp>N)
	        {
	            s=(s+3*f)/4;
	        }
	        else
	        {
	            s=(3*s+f)/4;
	        }
	        if (tmp2==tmp && ances == ans)
	        {
	            flag=true;
	        }
	        tmp2=tmp;
	        ances=ans;

	    }
	}
	else
	{
	    cout << -1 << endl;
	    return 0;
	}
}
