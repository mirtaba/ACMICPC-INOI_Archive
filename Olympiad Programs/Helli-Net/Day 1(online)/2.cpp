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

const int Maxn = 2*1000 + 125;
const int Mod = 707707703;

//ofstream fout ("greetings.out");
//ifstream fin ("2.in");

//#define cin fin
//#define cout fout

int d[Maxn][Maxn];
string s,f;

int main()
{
	ios::sync_with_stdio(0);
	getline(cin,s,'\n');
	getline(cin,f,'\n');
	//cerr << s << ' ' << f << endl;
	//cerr << "Read done" << endl;
	//cerr << s.size() << endl;
	FOR(i,0,s.size())
	{
	    //cerr << "Doing it on " << i << endl;
	    d[i][0]=d[i-1][0];
        if(f[0]==s[i])
            d[i][0]++;
        d[i][0]%=Mod;
	    FOR(j,1,f.size())
	    {
	        d[i][j]=d[i-1][j];
            if(f[j]==s[i])
            {
                d[i][j]+=(d[i-1][j-1]);
                d[i][j]%=Mod;
            }
	    }
	}
	/**
	FOR(i,0,s.size())
	{
	    FOR(j,0,f.size())
	    {
	        cerr << d[i][j] << ' ';
	    }
	    cerr << endl;
	}
	/**/
	cout << d[s.size()-1][f.size()-1] << endl;
}
