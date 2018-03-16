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

long long ans,ragam;
long long Ans,N;

int cnt(int n)
{
    ans=0;
    while(n>0)
    {
        N+=(n%10);
        n/=10;
        if(n>0)
            N*=10;
    }
    while(N>0)
    {
        if((N%10)!=0)
            ragam++;
        if(((N%10)%2)==1)
        {
            ans+=ragam;
        }
        N/=10;
    }

    return (ans);
}

int main()
{
	ios::sync_with_stdio(0);
	FOR(i,1,123457)
	{
	    Ans+=cnt(i);
	    Ans=(Ans%(1000007));
        //cerr << Ans << endl;
        //system("pause");
	}
	cout << Ans << endl;
}
