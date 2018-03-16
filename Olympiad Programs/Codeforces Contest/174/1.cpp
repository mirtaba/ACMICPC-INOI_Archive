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

const int Maxn = 2*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

bool mark[Maxn*100],flag;
int p,ans;
LL tp;

int main()
{
	ios::sync_with_stdio(0);
	cin >> p;
	FOR(i,1,p)
	{
	    flag=false;
	    tp=1;
	    FOR(j,0,p+10)
	    {
	        mark[j]=false;
	    }
	    FOR(j,1,p)
	    {
	        tp*=i;
	        tp=(tp%p);
            mark[tp]=true;
	    }
	    FOR(j,0,p)
	    {
	        if (mark[j]==false)
	        {
	            //cerr << j << endl;
	            flag=true;
	        }
	    }
	    if (!flag)
	    {
	        ans++;
	    }
	    //cerr << "----------------" << endl;
	}
	cout << ans << endl;
}
