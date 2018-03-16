// The dijestra Algorithm used to find the exact distance to every vertex in a graph with weighted edges;

// we use set to remmember those who we found a distance for them but we are not sure that this distnce is the shortest path;
set < pair<int ,int> > S;
d[V]=0;
S.insert(make_pair(d[V],v));
while(S.size())
{
    int u=S.begin() -> second;
    mark[u]=true;
    S.erase(make_pair(d[u],u));
    for (int i=0;i<Graph[u].size();i++)
    {
        int x=Graph[u][i];
        if(d[x]>d[u]+weight[u][i] && !mark[x])
        {
            S.erase(make_pair(d[x],x));
            d[x]=d[u]+weight[u][i];
            S.insert(make_pair(d[x],x));
        }
    }
}
