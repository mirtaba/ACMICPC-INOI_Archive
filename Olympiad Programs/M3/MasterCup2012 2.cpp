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
#define FOR(i,a,b) for(LL i=a;i<b;i++)
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


M f[10000000],in1,in2,ans,Ans;
long long t;
M call(long long n)
{
    ans.X.X=0;
    ans.X.Y=0;
    ans.Y.X=0;
    ans.Y.Y=0;
    if(n<10000000)
        if(f[n].X.X!=0)
            return f[n];
    in1=call((n+1)/2);
    in2=call((n)/2);
    ans.X.X=(((in1.X.X)*(in2.X.X))+((in1.X.Y)*(in2.Y.X)))%1000;
    ans.X.Y=(((in1.X.X)*(in2.X.Y))+((in1.X.Y)*(in2.Y.Y)))%1000;
    ans.Y.X=(((in1.Y.X)*(in2.X.X))+((in1.Y.Y)*(in2.Y.X)))%1000;
    ans.Y.Y=(((in1.Y.X)*(in2.X.Y))+((in1.Y.Y)*(in2.Y.Y)))%1000;
    return ans;
}



int main()
{
	ios::sync_with_stdio(0);
	f[1].X.X=1;
	f[1].X.Y=1;
	f[1].Y.X=1;
	f[1].Y.Y=0;
	//Ans=call(4);
	//cout << Ans.X.Y << endl;
	/**/
	for(long long i=2;i<=10000000;i++)
	{
	    //f[i]=call(i);
	    Ans=call(i);
        cout << Ans.X.X <<' ' << Ans.X.Y << endl;
        cout << Ans.Y.X <<' ' << Ans.Y.Y << endl;
	    //cerr << i << ' ' << f[i].X.X << endl;
	    system("pause");
	}
	t=121212;
	//Ans=cal(1);
	//cout << Ans.X.X <<' ' << Ans.X.Y << endl;
	//cout << Ans.Y.X <<' ' << Ans.Y.Y << endl;
	/**/
}

