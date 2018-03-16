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

long long mx,p,t,h1,h2,t1,t2,hh,tt;
bool flag=false;

LL f(LL n)
{
    /**/
    mx=0;
    p=0;
    t=0;
    /**/
    for(LL i=2; i<n; i++)
    {
        mx=max(i,mx);
        p+= (n/mx) + 1;
    }
    for(LL j=5; j<n; j+=3)
    {
        p+=((n-j)*2);
    }
    //cerr << endl;
    return p;
}


int main()
{
	ios::sync_with_stdio(0);
	/**/
	//cerr << f(100000000) << endl;
	h1=10000000;
	h2=100000000;
	cin >> t1;
	while((h2-h1)>1)
    {
        hh=(h1+h2)/2;
        tt=f(hh);
        //cerr << t1 << endl;
        if(tt>(t1))
        {
            h2=hh;
        }
        else
        {
            h1=hh;
        }
    }
    cerr << h1 << h2 << endl;
    cout << (LL)((h1)%13857) << ' ' << (LL)((h2)%13857) << endl;
	/**
	FOR(i,0,100000)
	{
	    cerr << f(i) << endl;
	    if(i%10==0)
            system("pause");
	}
	/**/
}
