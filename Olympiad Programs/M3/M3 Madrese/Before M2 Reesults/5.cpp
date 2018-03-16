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
typedef pair <PLL,PLL> M;

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

vector <long> prime;
bool mark[1000000];
M ans,riz,pr;
long t,j;

M call(M in1,M in2)
{
    ans.X.X=0;
    ans.X.Y=0;
    ans.Y.X=0;
    ans.Y.Y=0;
    ans.X.X=(((in1.X.X)*(in2.X.X))+((in1.X.Y)*(in2.Y.X)))%Mod;
    ans.X.Y=(((in1.X.X)*(in2.X.Y))+((in1.X.Y)*(in2.Y.Y)))%Mod;
    ans.Y.X=(((in1.Y.X)*(in2.X.X))+((in1.Y.Y)*(in2.Y.X)))%Mod;
    ans.Y.Y=(((in1.Y.X)*(in2.X.Y))+((in1.Y.Y)*(in2.Y.Y)))%Mod;
    return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	int n = 1000*1000;
	FOR(i,2,n+1)
	{
	    if (!mark[i])
        {
            prime.pb(i);
            for (int j = 2 * i ; j <= n ; j += i)
                mark[j] = 1;
        }
	}
    riz.X.X=1;
    riz.X.Y=1;
    riz.Y.X=1;
    riz.Y.Y=0;
    pr.X.X=1;
    pr.X.Y=1;
    pr.Y.X=1;
    pr.Y.Y=0;
    prime.pop_back();
    for(int i=(prime[prime.size()-1]);i>=1;i--)
    {
        if(!mark[i])
        {
            riz=call(riz,call(riz,pr));
        }
        else
        {
            riz=call(riz,riz);
        }
    }
    cout << riz.X.Y << endl;
    cout << (riz.X.Y)%13857  << endl;

}
