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

#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second

using namespace std;

typedef long long LL;

typedef pair <int, int> PII;

const int MAXN = 1000 * 10 + 10;

vector <int> out[MAXN], in[MAXN], queue;
int n, m, comps, component[MAXN], mark[MAXN], badcomp[MAXN], ans;

void dfs(int v)
{
	mark[v] = 1;
	for (int i = 0 ; i < (int)out[v].size() ; i++)
	{
		int u = out[v][i];
		if (!mark[u])
			dfs(u);
	}
	queue.push_back(v);
}

void dfs2(int v)
{
	component[v] = comps;
	mark[v] = 1;
	for (int i = 0 ; i < (int)in[v].size() ; i++)
	{
		int u = in[v][i];
		if (!mark[u])
			dfs2(u);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int turn = 1 ; turn <= t ; turn++)
	{
		for (int i = 0 ; i < MAXN ; i++)
		{
			out[i].clear();
			in[i].clear();
		}
		queue.clear();
		memset(component, 0, sizeof(component));
		memset(mark, 0, sizeof(mark));
		memset(badcomp, 0, sizeof(badcomp));
		cin >> n >> m;
		comps = 0;
		ans = 0;
		for (int i = 1 ; i <= m ; i++)
		{
			int u, v;
			cin >> u >> v;
			out[u].push_back(v);
			in[v].push_back(u);
		}
		for (int i = 1 ; i <= n ; i++)
			if (!mark[i])
				dfs(i);
		memset(mark, 0, sizeof(mark));
		for (int i = (int)queue.size()-1 ; i >= 0 ; i--)
		{
			int v = queue[i];
			if (!mark[v])
			{
				comps++;
				dfs2(v);
			}
		}
		for (int i = 1 ; i <= n ; i++)
		{
			bool flag = 0;
			for (int j = 0 ; j < (int)in[i].size() ; j++)
			{
				int v = in[i][j];
				if (component[v] != component[i])
					flag = 1;
			}
			badcomp[component[i]] |= flag;
		}
		for (int i = 1 ; i <= comps ; i++)
			ans += ((badcomp[i]) ? 0 : 1);
		cout << "Case " << turn << ": " << ans << endl;
	}
	return 0;
}
