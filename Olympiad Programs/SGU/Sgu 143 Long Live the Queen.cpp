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

const int MAXn=16*1000+40;
long long d[MAXn];
long long w[MAXn];
vector<long long>v[MAXn];
queue<long long>q;
vector<long long>answer;
bool mark[MAXn];
int n;

void dfs(int u)
{
	mark[u]=true;
	d[u] = w[u];
	for(int i=0;i<v[u].size();i++)
	{
		if(!mark[v[u][i]])
		{
			dfs(v[u][i]);
			if(0<d[v[u][i]])
				d[u]+=d[v[u][i]];
		}
	}
}

int main()
{
	int u1,u2;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    cin >> w[i];
	}
	for(int i=0;i<n-1;i++)
	{
		cin>>u1>>u2;
		u1--;
		u2--;
		v[u1].push_back(u2);
		v[u2].push_back(u1);
	}
	dfs(0);
    cout << *max_element(d,d+n) << endl;
}

