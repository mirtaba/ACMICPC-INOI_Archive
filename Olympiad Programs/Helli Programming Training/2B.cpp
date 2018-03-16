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

const int Maxn=400+25;
vector <int> Graph[Maxn];
short dis[Maxn],mark[Maxn];
queue <int> que;
long long N,M,S,T,color[Maxn];
map<pair<int,int>,pair<int,int> > mp;
pair<int,int> temp,Edgs[Maxn];
vector <short> vcolor[Maxn];
bool Flag;


void BFS(int v)
{
	que.push(v);
	mark[v]=1;
	dis[v]=0;
	while(que.size())
	{
		int u=que.front();
		for(int i=0;i<Graph[u].size();i++)
			if(mark[Graph[u][i]]==0 || Graph[u][i]==(T-1) )
			{
				mark[Graph[u][i]]=1;
				que.push(Graph[u][i]);
				dis[Graph[u][i]]=dis[u]+1;
				mp[make_pair(u,Graph[u][i])].second=dis[Graph[u][i]];
				mp[make_pair(Graph[u][i],u)].second=dis[Graph[u][i]];

			}
		que.pop();
	}
}

int main()
{
    cin >> N >> M >> S >> T;
    for (int i=1;i<=M;i++)
    {
        cin >> Edgs[i].first >> Edgs[i].second;
        if ((Edgs[i].first==S && Edgs[i].second==T)||(Edgs[i].first==T && Edgs[i].second==S)) Flag=true;
        Graph[Edgs[i].first-1].push_back(Edgs[i].second-1);
        Graph[Edgs[i].second-1].push_back(Edgs[i].first-1);
        mp[make_pair(Edgs[i].first-1,Edgs[i].second-1)].first=i;
    }
   if (Flag==false)
    {
        short Minfind=0;
        BFS(S-1);
        for (int i=0;i<=Graph[T].size();i++)
        {
            Minfind=((mp[make_pair(Graph[T][i],T)].second > Minfind) ? mp[make_pair(Graph[T][i],T)].second:Minfind);
        }
        for(int i=0;i<Graph[T].size();i++)
        {
            mp[make_pair(T,Graph[T][i])].second=Minfind;
        }
        long long Maxfind=0;
        for (int i=1;i<=M;i++)
        {
            color[mp[make_pair((Edgs[i].first-1),(Edgs[i].second-1))].second]++;
            vcolor[mp[make_pair((Edgs[i].first-1),(Edgs[i].second-1))].second].push_back(mp[make_pair(Edgs[i].first-1,Edgs[i].second-1)].first);
            Maxfind= (Maxfind<mp[make_pair((Edgs[i].first-1),(Edgs[i].second-1))].second) ? mp[make_pair((Edgs[i].first-1),(Edgs[i].second-1))].second : Maxfind;
        }
        cout << Maxfind << endl;
        for (int i=1;i<=Maxfind;i++)
        {
            cout << color[i];
            for (int j=0;j<(vcolor[i].size());j++)
            {
                    cout << " " <<vcolor[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        cout << 1 << endl;
        cout << M;
        for (int i=1;i<=M;i++)
        {
            cout << " " << i;
        }
        cout << endl;
    }
}

