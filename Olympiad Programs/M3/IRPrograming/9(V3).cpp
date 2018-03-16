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
#define FOR(i,a,b) for(LL i=a;i<b;i++)
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

const int Maxn = 500 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
ifstream fin ("9(1).in");

#define cin fin
//#define cout fout

LL N,M,a[Maxn],Ans,it=0;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M;
	FOR(i,0,N)
	{
	    cin >> a[i];
	}
    sort(a,a+N);
    while(a[it]==0 && it<N)
    {
        it++;
    }
	while(a[it]!=0)
    {
        Ans+=a[it];
        FOR(i,it+1,it+M)
        {
            a[i]-=a[it];
        }
        a[it]=0;
        //cerr << a[0] << a[1] << a[2] << a[3] << endl;
        while(a[it]==0 && it<N)
        {
            it++;
        }
        sort(a+it,a+N);
        //system("pause");
    }
    cout << Ans << endl;
    FOR(i,it,it+M)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}
