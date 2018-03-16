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

LL N,in[Maxn],sum[Maxn],esum[Maxn],esumE[Maxn],best[Maxn],ans,maxe;
PLL maxF[Maxn],maxA[Maxn];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	cin >> in[0];
	sum[0]=in[0];
	esum[0]=-in[0];
	maxF[0]=mp(0,-in[0]);
	FOR(i,1,N)
	{
	    cin >> in[i];
	    sum[i]=sum[i-1]+in[i];
	    esum[i]=esum[i-1]-in[i];
	    if (esum[i] > maxF[i-1].Y)
	    {
	        maxF[i].X=i;
	        maxF[i].Y=esum[i];
	    }
	    else
	    {
	        maxF[i]=maxF[i-1];
	    }
	}
	/*
	FOR(i,0,N)
	{
	    cerr << ' ' << maxF[i].Y << endl;
	}
	*/
	esumE[N-1]=-in[N-1];
	maxA[N-1]=mp(N-1,-in[N-1]);
	for(LL i=N-2;i>=0;i--)
	{
	    esumE[i]=esumE[i+1]-in[i];
	    if (esumE[i] > maxA[i+1].Y)
	    {
	        maxA[i].X=i;
	        maxA[i].Y=esumE[i];
	    }
	    else
	    {
	        maxA[i]=maxA[i+1];
	    }
	}
    /*
	cerr << "----------------" << endl;
	for(LL i=N-1;i>=0;i--)
	{
	    cerr << ' ' << maxA[i].Y << ' ' << maxA[i].X <<  endl;
	}
    */
	FOR(i,0,N-1)
	{
	    best[i]=maxF[i].Y+maxA[i+1].Y+(sum[maxA[i+1].X -1]-sum[maxF[i].X]);
	    ans=max(ans,best[i]);
	}
	ans=max(ans,max(esum[N-1],esumE[0]));
	cout << ans << endl;

}
