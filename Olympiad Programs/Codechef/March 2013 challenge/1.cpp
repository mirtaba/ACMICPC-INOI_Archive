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

int N,tmp;
string S,t,k,A;
char tp;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	cin >> S;
	FOR(i,0,N)
	{
	    t.clear();
	    cin >> t;
	    FOR(j,0,t.size())
	    {
	        tp=t[j];
	        tmp=isalpha(tp);
	        tp=tolower(tp);
	        if (tmp==0)
	        {
                if (tp=='_')
                {
                    cout << ' ';
                }
                else
                    cout << tp;
	        }
	        else
	        {
                if (tmp == 2)
                {
                    cout << S[int(tp)-97];
                }
                else
                {
                    cout << char(toupper(S[int(tp)-97]));
                }
	        }
	    }
	    cout << endl;
	}
}
