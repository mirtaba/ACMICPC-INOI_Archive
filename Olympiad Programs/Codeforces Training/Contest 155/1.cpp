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


ofstream fout ("output.txt");
ifstream fin ("input.txt");

#define cin fin
#define cout fout


vector <LL> in[5000+200];
LL N,tmp,maxe;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	FOR(i,0,2*N)
	{
	    cin >> tmp;
	    in[tmp].pb(i+1);
	    maxe=(maxe<tmp) ? tmp : maxe;
	}
	FOR(i,0,maxe)
	{
        if (in[i].size()%2 == 1)
        {
            cout << -1 << endl;
            return 0;
        }
	}
	FOR(i,0,maxe+1)
	{
	    FOR(j,0,in[i].size())
	    {
	        cout << in[i][j];
	        if (j%2==0)
	        {
	            cout << ' ';
	        }
	        else
	        {
	            cout << endl;
	        }
	    }
	}

}

