/*
ID: ghoolha1
PROG: typo
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

ofstream fout ("typo.out");
ifstream fin ("typo.in");

#define cin fin
#define cout fout

string s;
LL baz[Maxn],baste[Maxn],ans,tmp;

int main()
{
	ios::sync_with_stdio(0);
	cin >> s;
	if (s.size()%2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if (s[0]=='(')
    {
        baz[0]=1;
        baste[0]=0;
    }
    else
    {
        baste[0]=1;
        baz[0]=0;
    }
	FOR(i,1,s.size())
	{
        if (s[i]=='(')
        {
            baz[i]=(baz[i-1]+1);
            baste[i]=baste[i-1];
        }
        else
        {
            baste[i]=(baste[i-1]+1);
            baz[i]=baz[i-1];
        }
	}
	if(baz[s.size()-1] == baste[s.size()-1])
	{
	    cout << 0 << endl;
	    return 0;
	}
	if (baz[s.size()-1]>baste[s.size()-1])
	{
	    if (s[0]==')' || s[s.size()-1]=='(')
        {
            cout << 1 << endl;
            return 0;
        }
	    FOR(i,0,s.size())
	    {
	        if(baz[i]-1 >= baste[i]+1 && s[i]=='(')
	        {
	            ans++;
	        }
	        if(baste[i]>baz[i])
                break;
	    }
	}
	else
	{
        if (s[0]==')' || s[s.size()-1]=='(')
        {
            cout << 1 << endl;
            return 0;
        }
	    reverse(s.begin(),s.end());
        if (s[0]=='(')
        {
            s[0]==')';
            baste[0]=1;
            baz[0]=0;
        }
        else
        {
            s[0]=='(';
            baz[0]=1;
            baste[0]=0;
        }
        FOR(i,1,s.size())
	    {
            if (s[i]==')')
            {
                s[i]='(';
                baz[i]=baz[i-1]+1;
                baste[i]=baste[i-1];
            }
            else
            {
                s[i]=')';
                baste[i]=baste[i-1]+1;
                baz[i]=baz[i-1];

            }
	    }
	    FOR(i,0,s.size())
	    {
	        if(baz[i]-1 >= baste[i]+1 && s[i]=='(')
	        {
	            ans++;
	        }
	        if(baste[i]>baz[i])
                break;
	    }
	}
	cout << ans << endl;
	return 0;
}
