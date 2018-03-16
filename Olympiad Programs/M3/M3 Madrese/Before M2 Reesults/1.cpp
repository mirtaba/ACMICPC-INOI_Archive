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

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

pair <long long ,long long> p[10010],m[10010];
long long cal=1,cal3=1,cal5=1,tmp,tmp2,S=0;

int main()
{
	ios::sync_with_stdio(0);
	FOR(i,1,10001)
	{
	    cal*=2;
	    cal=(cal%(1000000000+7));
	    p[i].X=(LL)(cal+35)%1000;
	    p[i].Y=(LL)((LL)((cal*cal)%(1000000000+7))+50)%1000;
	}
	FOR(i,1,10001)
	{
        cal3*=3;
        cal5*=5;
        cal3=(cal3%(1000000000+7));
        cal5=(cal5%(1000000000+7));
        m[i].X=(LL)(cal3+73)%1000;
        m[i].Y=(LL)(cal5+62)%1000;
        tmp=((m[i].X*m[i].Y));
	    FOR(j,1,10001)
        {
            tmp2=((p[j].Y*m[i].X)+(p[j].X*m[i].Y));
            if(tmp>=tmp2)
            {
                S++;
                break;
            }
        }
	}
	cerr << S << endl;
	cout << (LL)(((S*S*S)%(1000000000+7))%13857) << endl;
}
