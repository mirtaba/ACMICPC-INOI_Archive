// O(ne)
bool mark // بخش بالا
LL match // بخش بالا
LL dmatch // بخش پایین

bool dfs (int x)
{
    if (x == -1 ) return true;
    mark[x]=true;
    for v to adj[x] // adjacent vertexs to V
    {
        if (mark[dmatch[v]) continue ;
        if (dfs(dmatch))
        {
            match[x]=V;
            dmatch[v]=x;
            return true;
        }
    }
    return 0;
}

int main()
{
    for (i= 1 to N) // N = nubmer of vertexses
    {
        mark[i]=false;
    }
    for (j 1 to N)
    {
        if (!mark[j])
            dfs(j);
    }
    //---------------OR--------------------
    for (i to V)  // here V is diffrent to V we used in dfs , this is the number of vertexses
    {
        mark[i]=false;
        dfs(i);
    }

}
