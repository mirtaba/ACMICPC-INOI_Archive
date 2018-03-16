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

const int Maxn = 150 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

vector <int> mark,Ans;
int tp,N,tmp,Rez;
PII maxe;
bool m;

int main()
{
	ios::sync_with_stdio(0);
    mark.resize(2*Maxn);
	FOR(i,1,Maxn)
	{
	    for(int j=i;j<Maxn;j+=i)
	    {
	        mark[j]++;
	    }
	}
	N=50;
	FOR(i,1,Maxn)
    {
        tp=i;
        cerr << i+N << endl;
        while(tp<(i+N))
        {
            if(maxe.X<mark[tp])
            {
                maxe.X=mark[tp];
                maxe.Y=tp;
            }
            tp++;
        }
        Ans.pb(maxe.X);
        i=(maxe.Y+1);
        N-=(tp-i);
        if (N<=0)
        {
            FOR(j,maxe.Y+1,Maxn)
            {
                Ans.pb(mark[j]);
            }
            break;
        }
    }
    FOR(i,0,Ans.size())
    {
        Rez+=Ans[i];
    }
    cout << Rez;
}

