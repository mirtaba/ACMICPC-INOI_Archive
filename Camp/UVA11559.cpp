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

int n,B,H,w,p;

int main()
{
	ios::sync_with_stdio(0);
	while(cin >> n >> B >> H >> w)
    {
        int ansi = abMax;
        FOR(i,0,H)
        {
            cin >> p;
            int tmp , maxi = 0;
            FOR(j,0,w)
            {
                cin >> tmp;
                maxi = max (maxi,tmp);
            }
            if( (p*n) > B )
                continue;
            else
            {
                if(maxi >= n)
                    ansi = min(ansi,(p*n));
            }
        }
        if(ansi <=B)
            cout << ansi << endl;
        else
            cout << "stay home" << endl;
	}
}
