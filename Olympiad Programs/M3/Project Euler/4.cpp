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

int y,tp,tp1,tmp,maxe;


bool ispal(int x)
{
    tmp=x;
    y=0;
    while(x>0)
    {
        y*=10;
        y+=x%10;
        x/=10;
    }
    return (y==tmp);
}



int main()
{
	ios::sync_with_stdio(0);
	FOR(i,99,1000)
	{
	    FOR(j,99,1000)
	    {
	        tp=(i*j);
	        if (ispal(tp))
            {
                maxe=max(maxe,tp);
            }
	    }
	}
	cout << maxe << endl;
}

