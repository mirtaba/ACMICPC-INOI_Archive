#include <bits/stdc++.h>
#include <math.h>
using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;
const int bMax = 1 << 25;
int ans,al = 0;
int netname = 1;

int dis[Maxn][Maxn];
vector <int> Graph[Maxn];
bool mark[Maxn];
queue<int> que;
map<string , int> aloc;

void BFS(int v)
{
    que.push(v);
    mark[v]=true;
    dis[v][v]=0;
    while(que.size())
    {
        int u=que.front();
        for (int i=0;i<Graph[u].size();i++)
        {
            if (!mark[Graph[u][i]])
            {
                que.push(Graph[u][i]);
                mark[Graph[u][i]]=true;
                dis[v][Graph[u][i]] =dis[v][Graph[v][u]]+1;

            }
        }
        que.pop();
    }
}
int main(){
    int p,q;
    string name1,name2;
    vector<int> cone[Maxn];
    do{

    cin >> p >> q;
    for(int i=0;i<p;i++)
        {
            for(int j=0;j<p;j++)
            {
                dis[i][j] = bMax;
            }
            dis[i][i]=0;
        }
    for(int i=0 ; i<q ; i++){

        cin >> name1 >> name2;

            if(aloc.find(name1) == aloc.end())
            {
                aloc[name1] = al++;
            }
            if(aloc.find(name2) == aloc.end())
            {
                aloc[name2] = al++;
            }
        cone[aloc[name1]].push_back(aloc[name2]);
        cone[aloc[name2]].push_back(aloc[name1]);
    }

    for(int i=0;i<p;i++){
        BFS(i);
    }
    for(int i=0;i<p;i++)
        {
            for(int j=0;j<p;j++)
            {
                ans = max (ans , dis[i][j]);
            }
        }

        if(ans == bMax)
            cout << "Network " << netname << ": " << ans << endl;
        else
            cout << "Network " << netname << ": " << "DISCONNECTED" << endl;
    netname++;
    }while(p!=0 && q!=0);
    return 0;
}

