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

const LL Maxn = 100*1000*10 + 250;
const LL Mod = 1000 * 1000 * 1000 + 7;
const LL abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

pair < LL , PLL > data[Maxn];
LL n , k;

LL cal(LL t)
{
    LL ans = 0;
    FOR(i,0,n)
    {
        if(data[i].X < t)
        {
            ans += ((data[i].Y.X * t) - data[i].Y.Y);
        }
        else
        {
            break;
        }
    }
    return ans;
}

LL ttmp = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> k;
	FOR(i,0,n)
	{
	    cin >> data[i].Y.X;
	    ttmp += data[i].Y.X;
	}
    FOR(i,0,n)
	{
	    cin >> data[i].Y.Y;
	    data[i].X = (data[i].Y.Y / data[i].Y.X) ;
	}
	sort(data,data+n);
	LL a = data[0].X;
	LL b = data[n-1].X;
	bool flag = false;
	while(a<(b-1) || b>(a+1))
    {
        LL mid = (a+b)/2;
        LL calAns = cal(mid);
        LL calAns2 = cal(mid +1);
        if(calAns <= k && calAns2 > k)
        {
            cout << mid << endl;
            flag = true;
            break;
        }
        //cerr << a << ' ' << b << ' ' << mid << ' ' << calAns << endl;
        if(k<calAns)
        {
            b = mid;
        }
        else
        {
            a = mid;

        }
    }
    if(!flag)
    {
        LL calAns = cal(data[0].X+1);
        if(calAns > k )
        {
            cout << data[0].X << endl;
            flag = true;
        }
    }
    if(!flag)
    {
        LL calAns = cal(data[n-1].X);
        LL calAns2 = cal(data[n-1].X+1);
        //cerr << calAns2 << endl;
        if(calAns <= k && calAns2 > k)
        {
            cout << data[n-1].X << endl;
            flag = true;
        }
        else
        {
            k -=calAns2;
            cout << data[n-1].X + 1 + (k/ttmp) << endl;
        }
    }


}
