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

const int MaxN=(5*100*100)+200;
const int MaxK=(5*100)+20;

bool mark[MaxN];
vector<int>G[MaxN];
long long d[MaxN][MaxK];
int N,K;
long long answer;

void dfs(int v)
{
	mark[v]=true;
	for(int i =0;(i<G[v].size());i++)
		if((!mark[G[v][i]]))
			dfs(G[v][i]);
	for(int i=0;i<(G[v].size());i++)
		for(int j=1;j<=K;j++)
			{
			    d[v][j]+=d[G[v][i]][j - 1];
            }
	d[v][0]=1;
	long long res=(2*d[v][K]);
	for(int i=1;i<K;i++)
		res+=d[v][i]*d[v][K - i];
	for(int j=0;j<G[v].size();j++)
	{
		int u = G[v][j];
		for(int i=1;i<K;i++)
			{
			res-=(d[u][i-1]*d[u][K-i-1]);
			}
	}
	answer+=(res/2);
}
int main ()
{
    cin >> N >> K;
    int f=0,t=0;
    for (int i=1;i<N;i++)
    {
        cin >> f >> t;
        G[f].push_back(t);
		G[t].push_back(f);
    }
    dfs(1);
    cout << answer << endl;
}

