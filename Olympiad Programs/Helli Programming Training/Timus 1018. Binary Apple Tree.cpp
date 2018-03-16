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

const int Maxn=5*1E2+25;

vector <int> node[Maxn];
int app[Maxn][Maxn],tree[Maxn],N,Q,dp[Maxn][Maxn];
bool ins[Maxn];

int main()
{
    cin >> N >> Q;
    int tmp=0,tmp1=0,tmp2=0;
    for (int i=0;i<N-1;i++)
    {
        cin >> tmp >> tmp1 >> tmp2;
        if(!ins[tmp1])
            node[tmp].push_back(tmp1);
        if(!ins[tmp])
            node[tmp1].push_back(tmp);
        app[tmp][tmp1]=tmp2;
        app[tmp1][tmp]=tmp2;
        ins[tmp]=true;
        ins[tmp1]=true;
    }
    for(int j=1;j<N;j++)
    {
        for(int i=0;i<node[j].size();i++)
        {
            cerr << j << ' ' <<node[j][i] << ' ';
        }
        cerr << endl;
    }
    tree[1]=1;
    int place=0;
    for(int i=1;i<(N*N);i++)
    {
        if (tree[i]!=0)
        {
            tree[2*i]=node[tree[i]][0];
            place=(2*i)+1;
            if(node[tree[i]].size()==2)
                tree[(2*i)+1]=node[tree[i]][1];
        }
    }
    for(int i=1;i<N;i++)
        cerr << tree[i] << ' ';
    for(int i=place;i>0;i--)
    {
        for(int j=2;j<=Q;j++)
        {
            dp[tree[i]][j]=max(dp[tree[2*i]][j-1]+app[tree[i]][tree[2*i]],max(dp[tree[(2*i)+1]][j-1]+app[tree[i]][tree[(2*i)+1]],dp[tree[2*i]][j-2]+app[tree[i]][tree[2*i]]+dp[tree[(2*i)+1]][j-2]+app[tree[i]][tree[(2*i)+1]]));
        }
    }
    cout << dp[1][Q];
}

