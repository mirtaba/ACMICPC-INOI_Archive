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

const int Maxn = 4450;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

__int64 tmp,tmp1,tmp2,tp,Ans[Maxn][Maxn];
vector <int> pr,G[Maxn*Maxn+25];
int in[Maxn][Maxn];
int man[670000];
bool mark[10000005],m[Maxn*Maxn+25];
bool ispu[Maxn];
int ind[Maxn][Maxn];
/**
void DFS(LL x)
{
    if (x==ind[Maxn-1][Maxn-1])
    {
        Ans++;
    }
    else
    {
        FOR(i,0,G[x].size())
        {
            if(!m[G[x]])
            {
                DFS(G[x]);
            }
        }
    }
}
/**/
int main()
{
	ios::sync_with_stdio(0);
    FOR(i,2,10000005)
    {
        if(!mark[i])
        {
            pr.pb(i);
            for(int j=(i*2);j<=10000005;j+=i)
            {
                mark[j]=true;
            }
        }
    }
    cerr << "Prime find done" << endl;
    tmp=10000;
    tmp*=1000;
    tmp*=tmp;
    FOR(i,0,pr.size())
    {
        man[i]=(tmp%pr[i]);
    }
    FOR(i,0,Maxn+1)
    {
        FOR(j,0,pr.size())
        {
            tp=(LL)((i+man[j])%pr[j]);
            if(tp==0)
            {
                ispu[i]=true;
                break;
            }
        }
    }
    cerr << "Pulimunials Find" << endl;
    FOR(i,0,Maxn)
    {
        FOR(j,0,Maxn)
        {
            ind[i][j]=(i*Maxn)+j;
        }
    }
    cerr << "Indexing done" << endl;
    Ans[0][0]=1;
    FOR(i,1,Maxn)
    {
        if(ispu[i]||ispu[0])
        {
            Ans[i][0]=Ans[i-1][0];
            Ans[0][i]=Ans[0][i-1];
        }
    }
    FOR(i,1,Maxn)
    {
        FOR(j,1,Maxn)
        {
            Ans[i][j]+=Ans[i-1][j]%1234567;
            Ans[i][j]+=Ans[i][j-1]%1234567;
            Ans[i][j]=(Ans[i][j]%1234567);
        }
        cerr << "Anwers for " << i << "found" << endl;
    }
    cout << (LL)(Ans[Maxn-1][Maxn-1]) << endl;
}
