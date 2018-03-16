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

using namespace std;

const long long Maxn = 2*100+25;

long long N,M;
vector <long long> Graph[Maxn];
long long Edgecolor[Maxn][Maxn];
bool Mark[Maxn][Maxn];
long long dis[Maxn][Maxn];
queue <long long> que;

void BFS()
{
    for(long long i=0;i<Graph[0].size();i++)
    {
        Mark[0][Graph[0][i]]=true;
        que.push(Graph[0][i]);
        que.push(0);
        dis[0][Graph[0][i]]=1;
    }
    while(que.size())
    {
        long long u=que.front();
        que.pop();
        long long last=que.front();
        que.pop();
        for(long long i=0;i<Graph[u].size();i++)
        {
            if((!Mark[u][Graph[u][i]] )&&(Edgecolor[u][Graph[u][i]]!=Edgecolor[last][u]))
            {
                Mark[u][Graph[u][i]]=true;
                que.push(Graph[u][i]);
                que.push(u);
                dis[u][Graph[u][i]]=dis[last][u]+1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> N >> M;
    if(M>((N)*(N-1)))
    {
        cout << -1 << endl;
        return 0;
    }
    else
    if (N==1)
    {
        cout << 0 << endl;
        return 0;
    }
    long long tmp1=0,tmp2=0,tmp3=0;
    for (long long i=0;i<M;i++)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        Graph[tmp1-1].push_back(tmp2-1);
        Edgecolor[tmp1-1][tmp2-1]=tmp3;
    }
    BFS();
    long long Minfind=50000000;
    for(long long i=0;i<N-1;i++)
    {
        if (dis[i][N-1]==0)
            continue;
        else
            Minfind=min(Minfind,dis[i][N-1]);
    }
    if (Minfind==50000000)
        cout << -1 << endl;
    else
        cout << Minfind << endl;
}
