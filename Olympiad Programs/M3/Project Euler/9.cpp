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

vector <int> S;
int tp1,tp2,tp3;
bool flag;

int main()
{
	ios::sync_with_stdio(0);
	FOR(i,1,1000)
	{
	    FOR(j,1,1000)
	    {
	        S.pb(i);
	        S.pb(j);
	        S.pb(1000-(i+j));
	        sort(S.begin(),S.end());
	        tp1=S[0]*S[0];
	        tp2=S[1]*S[1];
	        tp3=S[2]*S[2];
	        if((tp1+tp2)==tp3)
            {
                cout << S[0] << ' ' << S[1] << ' ' << S[2] << endl;
                flag=true;
                break;
            }
            S.clear();
	    }
        if (flag)
            break;
	}

}
