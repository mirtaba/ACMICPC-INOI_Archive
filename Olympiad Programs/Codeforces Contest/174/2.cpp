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
string S;
LL A,F,I,tp;


int main()
{
	ios::sync_with_stdio(0);
	cin >> tp >> S;
	FOR(i,0,S.size())
	{
	    if (S[i]=='A')
	    {
	        A++;
	    }
	    else
	    if (S[i]=='F')
	    {
	        F++;
	    }
	    else
	    {
	        I++;
	    }
	}
	if (I>1)
	{
	    cout << 0 << endl;
	    return 0;
	}
	if (I==1)
	{
	    cout << I << endl;
	    return 0;
	}
	else
	{
	    cout << A << endl;
	    return 0;
	}



}

