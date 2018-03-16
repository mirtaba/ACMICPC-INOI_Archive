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

const int Maxn = 100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int d[Maxn];
int c[Maxn],N;
int mark[Maxn];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	FOR(i,0,N)
	{
	    cin >> c[i];
	    mark[c[i]]=max(mark[c[i]],1);
	    for(int j=(2*c[i]);j<Maxn;j+=c[i])
        {
            mark[j]=2;
        }
	}
	FOR(i,0,N)
	{
        FOR(j,c[i]+1,Maxn)
        {
            if(mark[j])
            {
                for(int t=(j+c[i]);t<Maxn;t+=c[i])
                {
                    mark[t]=2;
                }
            }
        }
	}
	/**
	FOR(i,0,Maxn)
	{
	    if(mark[i]==2)
        {

        }
	}
	FOR(i,0,Maxn)
	{
	    cout << mark[i] << ' ';
	}
	cout << endl;
	/**/
	FOR(i,0,N)
	{
	    if(mark[c[i]]==2)
        {
            cout << c[i] << ' ';
        }
	}
	cout << endl;
}
