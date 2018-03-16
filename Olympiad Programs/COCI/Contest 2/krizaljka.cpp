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

const int Maxn = 100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;


map <string,LL> in;
string tmp,inp[Maxn],tmp1,tmp2,tmp3;


int main()
{
	ios::sync_with_stdio(0);
	FOR(i,0,6)
	{
	    cin >> tmp;
	    in[tmp]++;
	    inp[i]=tmp;
	}
	FOR(i,0,6)
	{
	    FOR(j,0,6)
	    {
	        if (i != j)
	        FOR(t,0,6)
	        {
	            if (i==t || j==t)
                    continue;
	            in[inp[i]]--;
	            in[inp[j]]--;
	            in[inp[t]]--;
	            tmp1.erase();tmp2.erase();tmp3.erase();
	            tmp1+=inp[i][0];
	            tmp1+=inp[j][0];
	            tmp1+=inp[t][0];
	            tmp2+=inp[i][1];
	            tmp2+=inp[j][1];
	            tmp2+=inp[t][1];
	            tmp3+=inp[i][2];
	            tmp3+=inp[j][2];
	            tmp3+=inp[t][2];
	            if (in[tmp1] && (in[tmp2] &&in[tmp3]))
	            {
                    cout << inp[i] << endl;
                    cout << inp[j] << endl;
                    cout << inp[t] << endl;
                    return 0;
	            }
	            in[inp[i]]++;
	            in[inp[j]]++;
	            in[inp[t]]++;
	        }
	    }
	}
	cout << 0 << endl;
	return 0;

}
