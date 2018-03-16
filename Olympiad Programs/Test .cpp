#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN 50005
using namespace std;

priority_queue <int, vector<int>, greater<int> > q;
int n,m,d,l;
int s[MAXN];

int main()
{
    int i,j,ans;
    scanf("%d%d%d%d",&n,&m,&d,&l);
    for (i=1;i<=n;i++) scanf("%d",&s[i]);
    sort(s+1,s+i);
    for (i=1;i<=m;i++) q.push(i);
    cerr << q.top() << endl;
    for (i=1;i<=n;i++)
        if (s[i]-d*q.top()>=l)
        {
           j=q.top()+1;
           q.pop();
           q.push(j);
        }
    ans=0;
    for (i=1;i<=m;i++)
    {
        ans=ans+q.top();
        q.pop();
    }
    printf("%d\n",ans);
    //system("pause");
}
