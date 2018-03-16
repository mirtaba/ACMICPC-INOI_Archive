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

const int Maxn = 50*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

ofstream fout ("greetings.out");
ifstream fin ("greetings.in");

#define cin fin
#define cout fout

LL B,M,b,m,tmp,ans,bb[Maxn],mm[Maxn],tb,te;
char ch;
bool flag;

int main()
{
	ios::sync_with_stdio(0);
	cin >> b >> m;
	FOR(i,0,b)
	{
	    cin >> tmp >> ch;
	    if (ch=='L')
	    {
	        bb[i]=-tmp;
	    }
	    else
	    {
	        bb[i]=tmp;
	    }
	}
	FOR(i,0,m)
	{
	    cin >> tmp >> ch;
	    if (ch=='L')
	    {
	        mm[i]=-tmp;
	    }
	    else
	    {
	        mm[i]=+tmp;
	    }
	}
	LL i=0,j=0;
	while(i<b || j<m)
	{
	    if (B==M)
        {
            if(tb<te )
            {
                if (i==b)
                {
                    te+=max(mm[j],-mm[j]);
                    M+=mm[j];
                    j++;
                }
                else
                {
                    tb+=max(bb[i],-bb[i]);
                    B+=bb[i];
                    i++;
                }
            }
            else
            {
                if (j==m)
                {
                    tb+=max(bb[i],-bb[i]);
                    B+=bb[i];
                    i++;
                }
                else
                {
                    te+=max(mm[j],-mm[j]);
                    M+=mm[j];
                    j++;
                }
            }
	    }
	    else
	    {
	        if(B<M)
	        {
	            flag=true;
	        }
	        if(tb<te )
            {
                if (i==b)
                {
                    te+=max(mm[j],-mm[j]);
                    M+=mm[j];
                    j++;
                }
                else
                {
                    tb+=max(bb[i],-bb[i]);
                    B+=bb[i];
                    i++;
                }
            }
            else
            {
                if (j==m)
                {
                    tb+=max(bb[i],-bb[i]);
                    B+=bb[i];
                    i++;
                }
                else
                {
                    te+=max(mm[j],-mm[j]);
                    M+=mm[j];
                    j++;
                }
            }
            if (B>M && flag)
            {
                ans++;
            }
            else
            if(B<M && !flag)
            {
                ans++;
            }
	    }
	    flag=false;
	}
	cout << ans << endl;
}
