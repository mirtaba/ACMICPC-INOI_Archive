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

const int Maxn = 100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL in[3][3],A,B,tmp[3],maxe,mine;

int main()
{
	ios::sync_with_stdio(0);
	FOR(i,0,3)
	{
	    FOR(j,0,3)
	    {
	        cin >> in[i][j];
	        tmp[i]+=in[i][j];
	    }
	    maxe=max(maxe,tmp[i]);
	}
	FOR(i,0,3)
	{
	    in[i][i]=maxe-tmp[i];
	    A+=(maxe-tmp[i]);
	}
	B=((maxe-A)/2);
	FOR(i,0,3)
	{
	    FOR(j,0,3)
	    {
	        if(i==j)
	        {
	            cout << in[i][i]+B << ' ';
	        }
	        else
	        {
	            cout << in[i][j] << ' ';
	        }
	    }
	    cout << endl;
	}


}
