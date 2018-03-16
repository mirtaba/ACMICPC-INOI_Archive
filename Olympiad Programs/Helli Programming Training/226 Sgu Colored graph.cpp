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

const int Maxn=2*100+25;

queue <int> q;
vector <int> Graph[Maxn];
short Edgs[Maxn][Maxn];
bool mark[Maxn][Maxn];
long long dis[Maxn],N,M;

void BFS(int v)
{
    q.push(v);
    dis[v]=0;
    int lastused=0;
    while(q.size())
    {
        int u=q.front();
        q.pop();
        int color=q.front;
        q.pop();
        for(int i=0;i<Graph[u].size();i++)
        {
            if((!mark[u][Graph[u][i]] )&&
               (!mark[Graph[u][i]][u])&&
               (Edgs[Graph[u][i]][u]!=color)&&
               (Edgs[u][Graph[u][i]]!=color))
            {
                mark[u][Graph[u][i]] =true;
                mark[Graph[u][i]][u] =true;


            }
        }
    }
}
