#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
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

const int Maxn = 3*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL N,K,in[Maxn],tmp,tmp2,sum[Maxn],sumE[Maxn],ans,maxe,aval[Maxn],akhar[Maxn];
PLL maxF[Maxn],maxA[Maxn];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> K;
	cin >> in[0];
	sum[0]=in[0];
	esum[0]=-in[0];
	FOR(i,1,N)
	{
	    cin >> in[i];
	    sum[i]=sum[i-1]+in[i];
	}
	sumE[N-1]=in[N-1];
	for(LL i=N-2;i>=0;i--)
	{
	    sumE[i]=sumE[i+1]+in[i];
	}
	tmp=sum[N-1];
	if(tmp%3!=0)
	{
	    cout << 0 << endl;
	}
	else
	{
	    tmp/=3;
        FOR(i,0,N)
        {
            aval[i]=aval[i-1];
            if (sum[i]==tmp)
            {
                aval[i];
            }
        }
        for(LL j=N-1;j>aval;j--)
        {
            akhar[j]=akhar[j+1];
            if(sum[j]==tmp)
            {
                akhar[j]++;
            }
        }
        FOR(i,0,N)
        {

        }
	}


}
