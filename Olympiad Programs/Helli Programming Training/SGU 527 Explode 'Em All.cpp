#include<iostream>
#include<cstdio>
#include<cstring>
#define N 30
#define inf 999999999
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

using namespace std;

int n,m,state[N],ans;
bool hast[1<<28];
void dfs(int x,int y,int s)
{
    hast[s]=true;
	int j;
	if(y>=ans)
		return ;
	if(x==n)
	{
		int sum=0;
		for(j=0;j<m;j++)
			if((state[j]|s)!=s)
				sum++;
		sum=max(y,sum);
		if(sum<ans)
			ans=sum;
		return ;
	}
	dfs(x+1,y+1,s|(1<<x));
	dfs(x+1,y,s);
}
int main()
{
	int i,j;
	char str[N][N];
	scanf("%d%d",&n,&m);
		memset(state,0,sizeof(state));
		for(i=0;i<n;i++)
			scanf("%s",str[i]);
		for(j=0;j<m;j++)
		{
			for(i=0;i<n;i++)
			{
				if(str[i][j]=='*')
					state[j]+=(1<<i);
			}
		}
		ans=min(n,m);
		dfs(0,0,0);

		printf("%d\n",ans);
	return 0;
}
