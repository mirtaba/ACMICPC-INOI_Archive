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
const int MAXN = 500;

vector <int> Graph[MAXN],color[MAXN];
int N,M,S,T,edgenum[MAXN][MAXN],dis[MAXN];
bool mark[MAXN];
queue<int> que;

void BFS(int v)
{
	que.push(v);
	mark[v] = 1;
	dis[v] = 0;
	while (que.size())
	{
		int u = que.front();
		for (int i = 0 ; i < Graph[u].size() ; i++)
			if (!mark[Graph[u][i]])
			{
				int temp = Graph[u][i];
				que.push(temp);
				mark[temp] = 1;
				dis[temp] = dis[u] + 1;
			}
		que.pop();
	}
}

int main()
{
    std::sync_with_stdio(0);
	cin >> N >> M >> S >> T;
	int u,v;
	for (int i=1;i<=M;i++)
	{
		cin >> u >> v;
		Graph[u].push_back(v);
		Graph[v].push_back(u);
		edgenum[u][v] = i;
		edgenum[v][u] = i;
	}
	BFS(S);
	cout << dis[T] << endl;
	for (int i = 1 ; i <= N ; i++)
		for (int j = i+1 ; j <= N ; j++)
			if (edgenum[i][j])
				color[max(dis[i], dis[j])].push_back(edgenum[i][j]);
	for (int i = 1 ; i <= dis[T] ; i++)
	{
		cout << color[i].size() << " ";
		for (int j = 0 ; j < color[i].size() ; j++)
			cout << color[i][j] << " ";
		cout << endl;
	}
}
