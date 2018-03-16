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

using namespace std;

const int MAXn=16*1000+40;
long long d[MAXn];
long long d2[MAXn];
vector<long long>v[MAXn];
queue<long long>q;
vector<long long>answer;
bool mark[MAXn];
int n;

void dfs(int u)
{
	long long Maxe=0;
	mark[u]=true;
	d[u] = 1;
	for(int i=0;i<v[u].size();i++)
	{
		if(!mark[v[u][i]])
		{
			dfs(v[u][i]);
			if(Maxe<d[v[u][i]])
				Maxe=d[v[u][i]];
			d[u]+=d[v[u][i]];
		}	
	}
	
	if((n-d[u])>Maxe)
		Maxe=n-d[u];
	d2[u]=Maxe;
}

int main()
{
	int u1,u2;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		cin>>u1>>u2;
		u1--;
		u2--;
		v[u1].push_back(u2);
		v[u2].push_back(u1);
	}
	dfs(0);
	long long temp=(*min_element(d2,d2+n));
	long long count=0;
	for(int i=0;i<n;i++)
	{
		if(d2[i]==temp)
		{
			answer.push_back(i);
			count++;
		}
	}
	cout << temp << " " << count << endl;
	for (int i=0;i<answer.size();i++)
	{
		cout << answer[i]+1 << " ";
	}  
	cout << endl;
}
