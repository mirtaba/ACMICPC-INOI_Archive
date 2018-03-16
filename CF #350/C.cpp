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

const int Maxn = 1000*1000 * 10 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int in[Maxn] , n , m , tmp;
pair < PII , int >  movies[Maxn];

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	FOR(i,0,n)
	{
	    cin >> in[i];
	}
	sort(in,in+n);
	cin >> m;
	FOR(i,0,m)
	{
	    movies[i].Y = i+1;
	    cin >> tmp;
        movies[i].X.X = (int)(upper_bound(in,in+n,tmp) - lower_bound(in,in+n,tmp) );
	}
    FOR(i,0,m)
	{
	    cin >> tmp;
        movies[i].X.Y = (int)(upper_bound(in,in+n,tmp) - lower_bound(in,in+n,tmp) );
	}
	sort(movies,movies+m);
	/**
	FOR(i,0,m)
	{
	    cerr << movies[i].Y << ' ' << movies[i].X.X << ' ' << movies[i].X.Y << endl;
	}
	/**/
	cout << movies[m-1].Y << endl;

}
