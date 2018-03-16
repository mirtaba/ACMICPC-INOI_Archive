// this agorithm is used to find the shortest path between every two vertex in a Graph
// d[k][i][j] means the shortest path between i and j with use of vertexes 0 to k-1  (    [0,k)   );
// the base case is d[0][i][j] that mean 1 if the i and j are ajected and 0 if they don't
for (int k=0;k<N;k++)
{
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            d[k][i][j]=min(d[k-1][i][j],d[k-1][i][k]+d[k-1][k][j]);
        }
    }
}
