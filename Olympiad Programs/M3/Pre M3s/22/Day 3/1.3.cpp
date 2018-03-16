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

const int Maxn = 1125030;
const int Maxm = 1125030*100;
const int Mod = 1000 * 1000 * 1000 + 7;
const int Del = 12503;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int gcd (int a ,int b)
{
    return b ? gcd(b,a%b) : a ;
}

LL d[Maxm],Ans;

int main()
{
	ios::sync_with_stdio(0);
	FOR(i,1,Maxn)
	{
	    for(int j=i;j<Maxn;j+=i)
	    {
	        d[j]++;
	    }
	}
	cerr << "Divisors Done!!!!" << endl;
	FOR(i,2520,Maxn)
	{
	    cerr << i << endl;
	    if(d[gcd(i,i)]==48)
            Ans++;
	    FOR(j,i+1,Maxn)
	    {
            if(d[gcd(j,i)]==48)
            {
                Ans+=2;
                Ans%=Del;
            }
	    }
	    Ans%=Del;
	}
	cout << Ans << endl;
}
