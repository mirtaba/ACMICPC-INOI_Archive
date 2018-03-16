#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define pf push_front
#define FOR(i,s,f) for (int i=s;i<f;i++)

typedef long long LL ;
typedef  pair <int ,int > PII;
typedef  pair <LL , LL >  PLL;

const int Maxn = 1000 +25;
const int Mod  = 1000*1000*1000 +9;

LL M[5];
vector <int> G[Maxn];
bool mark[Maxn];

int dfs(int v,int d)
{
    int tmp=0;
    mark[v]=true;
    //cerr << v << ' ' << d <<' ' << tmp << endl;
    if(d>0)
    {
        FOR(i,0,G[v].size())
        {
            if(!mark[G[v][i]])
            {
                tmp+=dfs(G[v][i],d-1);
            }
        }
        //cerr << v << ' ' << d <<' ' << tmp << " End" << endl;
        return tmp;
    }
    else
    {
        //cerr << v << ' ' << d <<' ' << tmp << " End" << endl;
        return 1;
    }

}

int main()
{
    ios::sync_with_stdio(0);
    FOR(i,1,512)
    {
        G[i].pb(2*i);
        G[i].pb((2*i)+1);
    }
    FOR(i,2,1024)
    {
        G[i].pb(i/2);
    }
    /**
    //cout << G[2].size() << endl;
    //cout << G[2][0] << ' ' << G[2][1] << ' ' << G[2][2] << ' ' << endl;
    dfs(2,2);
    /**/
    FOR(i,1,1024)
    {
        FOR(j,1,5)
        {
            memset(mark,0,sizeof mark);
            M[j]+=dfs(i,j);
        }
    }
    FOR(j,1,5)
    {
        cout << j <<  ' ' <<  M[j] << endl;
        M[j]/=2;
    }
    cout << (LL)((LL)(M[1]*M[4]*4)+((LL)(M[2]*M[3]*4))) << endl;
}
