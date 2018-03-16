#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAXV = 200;

#define REP( i, n ) = for ( i = 0; i  (n); i++ )

int V, E, i, sol;
int u, v, c, nu, nc;
int dist[MAXV][3];
vector < pair<int,int> > G[MAXV];
queue < pair<int,int> > Q;

void BFS()
{
    while ( Q.size() )
    {
        u = Q.front().first;
        c = Q.front().second;
        Q.pop();
        for (int i=0;i<G[u].size();i++)
        {
            nu = G[u][i].first;
            nc = G[u][i].second;
            if ( nc == c ) continue;
            if ( dist[nu][nc] == 0 ||
                dist[nu][nc] > dist[u][c] + 1 ) {
                dist[nu][nc] = dist[u][c] + 1;
                Q.push( make_pair( nu, nc ) );
            }
        }
    }
}

int main()
{
    cin >> V >> E;
    for(int i=0;i<E;i++)
    {
        cin >> u >> v >> c;
        u--; v--; c--;
        G[u].push_back(make_pair(v,c));
        G[v].push_back(make_pair(v,c));
    }
    for (int i=0;i<3;i++)
        Q.push( make_pair( 0, i ) );
    BFS();
    sol=-1;
    for (int i=0;i<3;i++)
        if ( dist[V - 1][i] > 0 )
            sol = (sol<dist[V - 1][i])?dist[V-1][i]:sol;
        cout <<  sol ;
        return 0;
    }
