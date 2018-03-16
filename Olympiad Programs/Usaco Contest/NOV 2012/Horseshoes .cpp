/*
ID: ghoolha1
PROG: hshoe
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

const int Maxn = 0 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

ofstream fout ("hshoe.out");
ifstream fin ("hshoe.in");

//#define cin fin
//#define cout fout

string s[Maxn];
LL d[Maxn][Maxn];
LL N,maxe;

LL p (LL a , LL b ,LL w1 , LL w2)
{
    cerr << a << ' ' << b << ' ' ;
    maxe=0;
    cerr << "11" << endl;
    if (b<(N-1))
    if (s[a][b]==s[a][b+1] && w1!=1)
    {
        cerr << '1' << endl;
        maxe=max(maxe,p(a,b+1,-1,0));
    }
    cerr << a << ' ' << b << ' ' ;
    cerr << "22" << endl;
    if (b>0)
    if (s[a][b]==s[a][b-1] && w1!=-1)
    {
        cerr << '2' << endl;
        maxe=max(maxe,p(a,b-1,1,0));
    }
    cerr << a << ' ' << b << ' ' ;
    cerr << "33" << endl;
    if (a>0)
    if (s[a][b]==s[a-1][b] && w2!=-1)
    {
        cerr << '3' << endl;
        maxe=max(maxe,p(a-1,b,0,1));
    }
    cerr << a << ' ' << b << ' ' ;
    cerr << "44" << endl;
    if (a<(N-1))
    if (s[a][b]==s[a+1][b] && w2!=1)
    {
        cerr << '4' << endl;
        maxe=max(maxe,p(a+1,b,0,-1));
    }
    d[a][b]=maxe;
    return maxe;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> N;
    FOR(i,0,N)
    {
        cin >> s[i];
    }
    p(0,0,0,0);
    maxe=0;
    FOR(a,0,N)
    {
        FOR(b,0,N)
        {
            if (s[a][b]!=s[a][b+1])
            {
                maxe=max(maxe,d[a][b]+d[a][b+1]);
            }
            if (s[a][b]!=s[a][b-1] && b>0)
            {
                maxe=max(maxe,d[a][b]+d[a][b-1]);
            }
            if (s[a][b]!=s[a-1][b] && a>0)
            {
                maxe=max(maxe,d[a][b]+d[a-1][b]);
            }
            if (s[a][b]!=s[a+1][b])
            {
                maxe=max(maxe,d[a][b]+d[a+1][b]);
            }
        }
    }
    cout << maxe << endl;
}


