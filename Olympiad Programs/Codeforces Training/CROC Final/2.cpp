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
#include <iostream>
#include <algorithm>
#include <vector>

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

string s,str[8];
LL N;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	while (N--)
	{
	    FOR(i,0,8)
        str[i].clear();
        cin>>s;
        LL j=0, i=0;
        while(i<s.size())
        {
            if (i!=(s.size()-1))
                if (s[i]==s[i+1] && s[i]==':')
                    break;
            if (s[i]!=':')
            {
                str[j]+=s[i];
            }
            else
            {
                j++;
            }
            i++;
        }
        if (i<s.size())
        {
            i=s.size()-1;
            j=7;
            while(i>=0)
            {
                if (s[i]==s[i-1] && s[i]==':')
                {
                    reverse(str[j].begin(),str[j].end());
                    break;
                }
                if (s[i]!=':')
                {
                    str[j]+=s[i];
                }
                else
                {
                    reverse(str[j].begin(),str[j].end());
                    j--;
                }
                i--;
            }
        }
        FOR(i,0,8)
        {
            if (i>0)
                cout << ':';
            if (str[i].size()<4)
            {
                FOR(t,0,(4-str[i].size()))
                    cout << 0;
            }
            cout << str[i]  ;
        }
        cout << endl;
    }
}
