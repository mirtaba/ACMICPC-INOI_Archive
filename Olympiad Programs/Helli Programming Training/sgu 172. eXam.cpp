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

const int Maxn=300*100+25;
vector <int> Graph[Maxn];
short dis[Maxn],mark[Maxn];
queue <int> que;
long long N,M;
pair<int,int> temp;
vector <int> answer,group[3];

void BFS(int v)
{
	que.push(v);
	mark[v]=1;
	dis[v]=1;
	group[1].push_back(v);
	while(que.size())
	{
		int u=que.front();
		for(int i=0;i<Graph[u].size();i++)
			if(mark[Graph[u][i]]==0)
			{
				mark[Graph[u][i]]=1;
				que.push(Graph[u][i]);
				if(dis[Graph[u][i]]==0)
                    dis[Graph[u][i]]=((dis[u]==1) ? 2 : 1);
                group[dis[Graph[u][i]]].push_back(Graph[u][i]);

			}
		que.pop();
	}
}

int main()
{
    cin >> N >> M ;
    for (int i=1;i<=M;i++)
    {
        cin >> temp.first >> temp.second;
        Graph[temp.first-1].push_back(temp.second-1);
        Graph[temp.second-1].push_back(temp.first-1);
    }
    for (int i=0;i<N;i++)
    {
        if(dis[i]==0)
            BFS(i);
    }
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<(Graph[i].size());j++)
        {
            if (dis[i]==dis[Graph[i][j]])
            {
                cout << "no" << endl;
                return(0);            }
        }
    }
        cout << "yes" << endl;
        cout << group[1].size() << endl;
        cout << group[1][0]+1 ;
        for (int j=1;j<group[1].size();j++)
        {
            cout << ' ' <<group[1][j]+1 ;
        }
}
