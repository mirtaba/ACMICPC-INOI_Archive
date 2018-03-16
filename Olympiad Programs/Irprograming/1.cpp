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


deque <int> in;
int ted=50,fil;
string s;

int fily()
{
    fil=*max_element(in.begin(),in.begin()+ted);
    cerr << "Max is: " << fil << endl;
	FOR(i,1,1+ted)
	{
	    if(in[i]==fil)
        {
            return (i-1);
        }
	}
}

int main()
{
	ios::sync_with_stdio(0);
	in.resize(155,1);
	FOR(i,2,151)
	{
	    FOR(j,1,150/i)
	    {
	        in[i*j]++;
	    }
	}
	in.pop_front();
	FOR(i,0,in.size())
	{
       s+=(in[i]+48);
	}
	cout << s << endl;
}

