/*
ID: ghoolha1
PROG: cowfind
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

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

ofstream fout ("cowfind.out");
ifstream fin ("cowfind.in");

#define cin fin
#define cout fout

string s;
LL baz,baste,ans;

int main()
{
	ios::sync_with_stdio(0);
	cin >> s;
	FOR(i,1,s.size())
	{
	    if(s[i-1]==s[i] && s[i]=='(')
        {
            baz++;
        }
        if(s[i-1]==s[i] && s[i]==')')
        {
            baste++;
            ans+=baz;
        }
	}
	cout << ans << endl;
}

