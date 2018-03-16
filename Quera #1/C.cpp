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

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

LL S,F , n , a,b;

vector <PLL> fr , la ;
vector <long double> is ;

int main()
{
	ios::sync_with_stdio(0);
	cin >> S >> F;
	cin >> n;
	FOR(tt,0,n)
	{
	    cin >> a >> b;
	    if(b < S || a > F )
            continue;
        fr.pb(mp(a,b));
        la.pb(mp(b,a));
        is.pb(a);
        is.pb(a-1);
        is.pb(a+1);
        is.pb(a-0.4);
        is.pb(a+0.4);
        is.pb(b);
        is.pb(b-1);
        is.pb(b+1);
        is.pb(b-0.4);
        is.pb(b+0.4);
	}
	is.pb(S);
	is.pb(F);
    sort(is.begin(),is.end());
	sort(fr.begin(),fr.end());
	sort(la.begin(),la.end());

	int i = 0;
	int j = 0;

	multiset <PLL> who;
    LL minAns = abMax;
    LL maxAns = 0;

	FOR(t,0,is.size())
    {
        if(t>0 && is[t-1] == is[t])
            continue;
        //cerr << t << endl;
        while(i<n && fr[i].X == is[t])
        {
            who.insert(fr[i]);
            i++;
        }
        while(j<n && la[j].X<is[t])
        {
            who.erase(mp(la[j].Y,la[j].X));
            j++;
        }
        //cerr << 'S' << (LL)(who.size()) << endl;
        if(is[t]>=S && is[t]<=F)
        {
            minAns = min(minAns,(LL)(who.size()));
            maxAns = max(maxAns,(LL)(who.size()));
        }
    }
    if(minAns == abMax)
        minAns = 0;
    cout << minAns << ' ' << maxAns << endl;


}
