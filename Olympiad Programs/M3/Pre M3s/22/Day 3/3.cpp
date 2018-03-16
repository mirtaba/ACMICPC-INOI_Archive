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
const int Del = 12503;
const int N=48;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

bool mark[(1<<(N/2))+225];
vector <bool> tp;
LL tmp,Ans;

void cal(int x)
{
    //cerr << x << endl;
    tp.clear();
    tmp=x;
    while(tmp>0)
    {
        tp.pb(tmp%2);
        tmp/=2;
    }
    reverse(tp.begin(),tp.end());
    /**
    FOR(i,0,tp.size())
    {
        cerr << tp[i];
    }
    cerr << endl;
    /**/
    tmp=x;
    FOR(tt,1,(48/tp.size()))
    {
        FOR(j,0,tp.size())
        {
            tmp=(tmp<<1);
            tmp+=tp[j];
        }
        if(tmp<0)
            cerr << x << ' ' << tmp << endl;
        if(tmp<(LL)(1LL<<(N/2)))
        {
            mark[tmp]=true;
            Ans++;
            Ans%=Del;
        }
        else
        {
            Ans++;
            Ans%=Del;
        }
        //system("pause");
    }
}

LL a;

int main()
{
	ios::sync_with_stdio(0);
	FOR(i,1,(1LL<<(N/2)))
	{
	    if((i%10000)==0)
            cerr << i << endl;
	    if(!mark[i])
        {
            cal(i);
        }
	}
	cout << Ans%Del << endl;
}
