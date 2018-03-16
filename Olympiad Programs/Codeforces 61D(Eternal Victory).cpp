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

using namespace std;

const int MaxN=(100*100*10)+200;

bool mark[MaxN];
vector <int> g[MaxN], w[MaxN];
int dis[MaxN];

void dfs (int i)
{
    mark[i]=true;
    for (int j=0;j<(g[i].size());j++)
    {
        if(mark[g[i][j]]==false)
        {
            dis[g[i][j]]=(dis[i]+w[i][j]);
            dfs(g[i][j]);
        }
    }
}
int main ()
{
    int n=0,f=0,t=0,we=0;
    cin >> n;
    for (int i=1;(i<n);i++)
    {

        cin >> f >> t >> we;
        g[f].push_back(t);
        g[t].push_back(f);
        w[f].push_back(we);
        w[t].push_back(we);
    }
    cerr << "i'm before dfs"<<endl;
    dfs(1);
    cerr << "i'm after dfs"<<endl;
    long long Maxdis=0;
    for (int i=0;i<MaxN;i++)
    {
        Maxdis = (Maxdis < dis[i]) ? dis[i] : Maxdis ;
    }
    cerr << Maxdis << endl;
    long long sum=0;
    for (int i=0;i<MaxN;i++)
    {
        for (int j=0;j<w[i].size();j++)
        {
            sum+=w[i][j];
        }
    }
    cerr << sum << endl;
    cout << (sum-Maxdis) << endl;
}


