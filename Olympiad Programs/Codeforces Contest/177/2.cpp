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

const int Maxn = 100*10 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;


int n,m,in[Maxn][Maxn],d,tp1,tp2,sub[Maxn][Maxn],call,f,e,one,two;
bool flag;

LL cal(int t)
{
    call=0;
    FOR(i,0,n)
    {
        FOR(j,0,m)
        {
            call+=(abs(sub[i][j]-t));
        }
    }
    return call;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m >> d;
	if (d==0)
    {
        cout << -1 << endl;
        return 0;
    }
    FOR(i,0,n)
    {
        FOR(j,0,m)
        {
            cin >> in[i][j];
            sub[i][j]=in[i][j]/d;
            if (i==0 && j==0)
            {
                tp1=in[i][j]%d;
                tp2=tp1;
            }
            tp2=tp1;
            tp1=in[i][j]%d;
            if (tp1 != tp2)
            {
                flag=true;
            }
            e=max(in[i][j]/d,e);
        }
    }
    if (flag)
    {
        cout << -1 << endl;
    }
    else
    {
        f=0;
        while(e-f>3)
        {
            one=(f+e)/3;
            two=(2*(f+e))/3;
            tp1=cal(one);
            tp2=cal(two);
            if (tp1 <= tp2)
            {
                e=two;
            }
            else
            {
                f=one;
            }
        }
        cout << min(tp1,tp2) << endl;
    }
}
