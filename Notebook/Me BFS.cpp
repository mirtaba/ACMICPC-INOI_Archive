void BFS(int v,int place)
{
    que.push(v);
    mark[v]=true;
    while(que.size())
    {
        int u=que.front();
        for (int i=0;i<Graph[u].size();i++)
        {
            if (!mark[Graph[u][i]])
            {
                que.push(Graph[u][i]);
                mark[Graph[u][i]]=true;
            }
        }
        que.pop();
    }
}
