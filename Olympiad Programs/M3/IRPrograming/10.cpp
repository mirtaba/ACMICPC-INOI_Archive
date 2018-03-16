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
#define FOR(i,a,b) for(long i=a;i<b;i++)
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

const int Maxn = 1000*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
ifstream fin ("10.in");

#define cin fin
//#define cout fout

LL LtR[Maxn],RtL[Maxn],in[Maxn],out[Maxn];
LL N,M,k,tmp,tp,tp1,tp2,tp3,Ans;


int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M >> k;
	FOR(i,0,M)
	{
	    cin >> tmp;tmp--;
	    cin >> in[tmp];
	    in[tmp]=in[tmp]%7777777;
	}
	LtR[0]=in[0]%7777777;
	FOR(i,1,N)
	{
	    LtR[i]=max(in[i],LtR[i-1]-k);
	    LtR[i]=LtR[i]%7777777;
	}
	RtL[N-1]=in[N-1];
	for(long i=(N-2);i>=0;i--)
    {
        RtL[i]=max(in[i],RtL[i+1]-k);
    }
    FOR(i,0,N)
    {
        out[i]=max(LtR[i],RtL[i]);
        //cerr << out[i] << ' ';
    }
    //cerr << endl;
    FOR(i,0,N)
    {
        Ans+=(LL)(((LL)(out[i]*(i+1)))%7777777);
        Ans=(Ans%7777777);
    }
    cout << Ans << endl;


}
