#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <map>
#include <fstream>
#include <cstring>

//#define cin fin
//#define cout fout

#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second
#define Size(n) ((int)(n).size())
#define Foreach(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)


using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef vector <int> Vint;

const int maxN = 100 * 1000 + 5;
const int mod = 1000 * 1000 * 1000 + 7;

vector <int> adj[maxN];
int mark[maxN];
vector <int> path;

void dfs(int x)
{
	path.pb(x);
	for (int i = 0; i < Size(adj[x]); i++)
	{
		int u = adj[x][i];
		if (!mark[u])
		{
			mark[u] = mark[x] + 1;
			dfs(u);
			break;
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v; u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	mark[0] = 1;
	dfs(0);
	for (int i=0;i < path.size() ;i++)
	{
	    cerr << path[i] << ' ' ;
	}
	cerr << endl;
	int v = path.back();
	int s = -1;
	for (int i = 0; i < Size(adj[v]); i++)
		if (s == -1 || mark[adj[v][i]] < mark[s])
			s = adj[v][i];
	int ind = 0;
	for (int i = 0; i < Size(path); i++)
		if (path[i] == s)
		{
			ind = i;
			break;
		}
	vector <int> out;
	for (int i = ind; i < Size(path); i++)
		out.pb(path[i]);
	cout << Size(out) << endl;
	for (int i = 0; i < Size(out); i++)
		cout << out[i] + 1 << " ";
	cout << endl;
	return 0;
}
