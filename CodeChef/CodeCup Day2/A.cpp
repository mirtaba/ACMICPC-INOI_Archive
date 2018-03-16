/*
ID: ghoolha1
PROG: greetings
LANG: C++
*/
/*
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
*/

#include <bits/stdc++.h>

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
#define Traxe(X) cerr << #X << " = " << X << endl
#define _ << " _ " <<


using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 1000*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout


PLL c[Maxn];
pair < PLL , LL> l[Maxn];

string ch[Maxn];

LL n , m , r;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m >> r;
	FOR(i,0,n)
	{
	    cin >> c[i].X >> c[i].Y;
	}
	FOR(i,0,m)
	{
        cin >> l[i].X.X >> l[i].X.Y >> l[i].Y ;
	}
	FOR(i,0,n)
	{
	    stringstream tmp;
	    FOR(j,0,m)
	    {
            LL tp = l[j].X.X*c[i].X;
            tp += l[j].X.Y*c[i].Y;
            tp += l[j].Y;
            if(tp<0)
            {
                tmp << 0;
            }
            else
            {
                tmp << 1;
            }
	    }
	    ch[i] = tmp.str();
	}
	sort(ch,ch+n);
	LL ans = 1;
	bool ansf = false;
	FOR(i,0,n-1)
	{
	    if(ch[i] == ch[i+1])
        {
            ansf = true;
        }
        else
        {
            ans++;7
        }
	}
	if(ansf)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    cout << ans << endl;



}
