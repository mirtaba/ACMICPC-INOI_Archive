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

const int Maxn=100*100+25;

queue <int> que;
int dis[Maxn][3],N;
bool mark[Maxn][Maxn];
vector <int> Graph[Maxn];
map < pair <int ,int> , int > w;

void BFS(int v,int place)
{
    que.push(v);
    dis[v][place]=0;
    mark[v][place]=true;
    while(que.size())
    {
        int u=que.front();
        for (int i=0;i<Graph[u].size();i++)
        {
            if (!mark[Graph[u][i]][place])
            {
                //cerr << u+1 << ' ' << Graph[u][i]+1 << ' ' <<w[u][Graph[u][i]] << endl;
                que.push(Graph[u][i]);
                mark[Graph[u][i]][place]=true;
                dis[Graph[u][i]][place]=dis[u][place]+max(w[Graph[u][i]],w[u]);
            }
        }
        que.pop();
    }
}
int main()
{
    cin >> N;
    int tmp1=0,tmp2=0;
    w[0]=0;
    for (int i=1;i<N;i++)
    {
        cin >> tmp1 >> tmp2;
        Graph[tmp1-1].push_back(i);
        Graph[i].push_back(tmp1-1);
        w[make_pair(i,tmp1-1)][i]=tmp2;
        w[make_pair(tmp1-1,i)][i]=tmp2;
        dis[i][0]=dis[tmp1-1][0]+tmp2;
    }
    long long Maxfind=0,Maxfindplace=0;
    for (int i=0;i<N;i++)
    {
        if (Maxfind<dis[i][0])
        {
            Maxfind=dis[i][0];
            Maxfindplace=i;
        }
    }
    //cerr << Maxfindplace << endl;
    BFS(Maxfindplace,1);
    Maxfind=0,Maxfindplace=0;
    for (int i=0;i<N;i++)
    {
        if (Maxfind<dis[i][1])
        {
            Maxfind=dis[i][1];
            Maxfindplace=i;
        }
    }
    //cerr << Maxfindplace << endl;
    BFS(Maxfindplace,2);
    for (int i=0;i<N;i++)
    {
        cout << max(dis[i][1],dis[i][2]) << endl;
    }

}
