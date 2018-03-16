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

const int Maxn = 500 + 25;
const int Mod = 100;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

bool ma[Maxn][Maxn],d[Maxn][Maxn],flag,flag1,flag2;
int tmp1,tmp2,tp,Ans,tmp,N;

int main()
{
	ios::sync_with_stdio(0);
	FOR(i,1,501)
	{
	    FOR(j,1,501)
	    {
	        (tp=(LL)(i*j)) %= Mod;
	        (tmp1=(LL)(2013*i)) %= Mod;
	        (tmp2=(LL)(2013*j)) %= Mod;
	        (tmp=(LL)(tp+tmp1+tmp2)) %= Mod;
	        if(tmp<=20)
            {
                //ma[i][j]=true;
                d[i][j]=true;
            }
	    }
	}
	FOR(i,1,501)
        d[500][i]=true;
	for(int i=499;i>=1;i--)
    {
        //if((i%2)==1)
        {
            FOR(j,1,501)
            {
                if(j>1)
                    flag1=(d[i+1][j-1]);
                else
                    flag1=true;
                if(j<500)
                    flag2=d[i+1][j+1];
                else
                    flag2=true;
                if (d[i+1][j] && (flag1&&flag2))
                {
                    d[i][j]=true;
                }
            }
        }
        /**
        else
        {
            FOR(j,1,501)
            {
                if(j>1)
                    flag1=(d[i+1][j-1]);
                    else
                flag1=true;
                if(j<500)
                    flag2=d[i+1][j+1];
                else
                    flag1=true;
                if ((d[i+1][j] || (flag1 || flag2)))
                {
                    d[i][j]=true;
                }
            }
        }
    /**/
    }
    FOR(i,1,501)
    {
        if (!d[1][i])
        {
            Ans++;
        }
    }
    cout << Ans << endl;
}
