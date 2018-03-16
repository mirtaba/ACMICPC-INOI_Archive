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

const int Maxn=200*100+25;
vector <int> Graph[Maxn];
short dis[Maxn],mark[Maxn];
queue <int> que;
long long N,M;
char ch;

void BFS(int v)
{
	que.push(v);
	mark[v]=1;
	dis[v]=0;
	while(que.size())
	{
		int u=que.front();
		for(int i=0;i<Graph[u].size();i++)
			if(mark[Graph[u][i]]==0)
			{
				mark[Graph[u][i]]=1;
				que.push(Graph[u][i]);
				dis[Graph[u][i]]=dis[u]+1;
			}
		que.pop();
	}
}

int main()
{
	cin >> N >> M;
    if(M == 1)
	{
		cout << 0 << endl;
	}
	for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
			{
				cin >> ch;
				if(ch=='#')
				{
					Graph[j].push_back(i+M);
					Graph[i+M].push_back(j);
				}
			}
	BFS(M+N);
	cout << ((dis[M+1])?dis[M+1]:-1) << endl;
}
