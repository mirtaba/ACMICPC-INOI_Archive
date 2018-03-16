#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cstdio>
#include <cstring>

#define LL long long

using namespace std;

const int Maxn=5*1000+250;

LL n,i,count,V,E,tmp1,tmp2;
bool mark[Maxn],flag;
vector <int> graph[Maxn];
vector<int> saf;
void dfs(int v)
{
    mark[v]=1;
    for (int i=0;i<graph[v].size();i++)
    {
        if(!mark[graph[v][i]])
            dfs(graph[v][i]);
    }
    saf.push_back(v);
}

int main()
{
    cin >> n;
    while(i<=n)
    {
        for (int j=0;j<Maxn;j++)
            graph[i].clear();
        saf.clear();
        memset(mark,0,sizeof mark);
        cin >> V >> E;
        tmp1=0;
        tmp2=0;
        for (int j=0;j<E;j++)
        {
            cin >> tmp1 >> tmp2;
            graph[tmp1-1].push_back(tmp2-1);
        }
        for (int j=0;j<V;j++)
        {
            if (!mark[j])
                dfs(j);
        }
        reverse(saf.begin(),saf.end());
        /*
        for (int j=0;j<V;j++)
        {
            cerr << saf[j] << ' ';
        }
        cerr << endl;
        */
        if (V==0)
        {
            cout << "Good Luck President!" << endl;
            i++;
            flag=true;
        }
        else
        if(V>1 && E==0)
        {
            cout << "Sorry President!" << endl;
            i++;
            flag=true;
        }
        else
            for (int j=0;j<(V-1);j++)
            {
                if (find(graph[saf[j]].begin(),graph[saf[j]].end(),saf[j+1]) == graph[saf[j]].end())
                {
                    cout << "Sorry President!" << endl;
                    i++;
                    flag=true;
                    break;
                }
            }
        if(!flag)
            cout << "Good Luck President!" << endl;
        i++;
        flag=false;
    }
    system("pause");
}
