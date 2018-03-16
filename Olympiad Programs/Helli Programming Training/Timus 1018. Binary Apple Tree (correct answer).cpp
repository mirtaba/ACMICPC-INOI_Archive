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

const int Maxn=1E2+25;

vector <int> Graph[Maxn];
int N,Q,d[Maxn][Maxn];
int app[Maxn][Maxn];
bool mark[Maxn];

void dfs(int v)
{
    int cont=0,kid[2]={0,0};
    mark[v]=true;
    for (int i=0;i<Graph[v].size();i++)
    {
        if (!mark[Graph[v][i]])
        {
            kid[cont]=Graph[v][i];
            cont++;
            d[v][1]= (d[v][1]<app[v][Graph[v][i]]) ? app[v][Graph[v][i]] :d[v][1];
            dfs(Graph[v][i]);
        }
    }
    if(Graph[v].size()==3 || (v==0 && Graph[v].size()==2))
        for (int j=2;(j<=Q);j++)
        {
            d[v][j]=max(d[kid[0]][j-1]+app[v][kid[0]],d[kid[1]][j-1]+app[v][kid[1]]);
            for (int i=0;(i<(j-1));i++)
            {
                d[v][j]=max(d[v][j],d[kid[0]][i]+d[kid[1]][j-i-2]+app[v][kid[0]]+app[v][kid[1]]);
            }
        }
    else
    if(Graph[v].size()==2 )
        for (int j=2;j<=Q;j++)
        {
            d[v][j]=(d[v][j-1]+app[v][kid[0]]);
        }
}
int main()
{
    cin >> N >> Q;
    if (N==1)
    {
        cout << 0 << endl;
        return 0;
    }
    int tmp1=0,tmp2=0,temp=0;
    for (int i=0;i<(N-1);i++)
    {
        cin >> tmp1 >> tmp2 >> temp;
        Graph[tmp1-1].push_back(tmp2-1);
        Graph[tmp2-1].push_back(tmp1-1);
        app[tmp1-1][tmp2-1]=temp;
        app[tmp2-1][tmp1-1]=temp;
    }
    dfs(0);
    cout << d[0][Q] << endl;
}
