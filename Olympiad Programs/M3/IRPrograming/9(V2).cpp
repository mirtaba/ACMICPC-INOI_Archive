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

LL N,M,a[Maxn],Ans;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M;
	FOR(i,0,N)
	{
	    cin >> a[i];
	}
    //cerr << "Before:" << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
    sort(a,a+N,greater<LL>());
    //cout << a[N-1] << endl;
    //cerr << "After: " << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
	while(a[M-1]!=0)
    {
        Ans+=a[M-1];
        FOR(i,0,M)
        {
            a[i]-=a[M-1];
        }
        //cerr << "Before:" << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
        sort(a,a+N,greater<LL>());
        //cerr << "After: " << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
    }
    cout << Ans << endl;
    FOR(i,0,M)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}
