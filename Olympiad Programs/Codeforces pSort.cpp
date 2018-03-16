#include<iostream>
#include<vector>
using namespace std;
int perm[100], mark[100] = {0}, d[100], n, gr[100][100];
int k = 1;
vector<int> v;
void sort(int s){
	mark[s] = 1;
	for(int i = 0; i < n; i++)
		if(gr[s][i] && !mark[i])
			sort(i);
	v.push_back(s);
}
void dfs(int s){
	mark[s] = k;
	for(int i = 0; i < n; i++){
		if(gr[s][i] && !mark[i])
			dfs(i);
	}
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> perm[i];
	for(int i = 0; i < n; i++){
		cin >> d[i];
		if(i + d[i] < n && i + d[i] >= 0)
			gr[i][i + d[i]] = gr[i + d[i]][i] = 1;
		if(i - d[i] < n && i - d[i] >= 0)
			gr[i][i - d[i]] = gr[i - d[i]][i] = 1;
	}
	memset(mark, 0, sizeof mark);
	for(int i = 0; i < n; i++)
		if(!mark[i])
			sort(i);
	memset(mark, 0, sizeof mark);
	for(int i = 0; i < n; i++){
		if(!mark[v[n - 1 - i]]){
			dfs(v[n - 1 -  i]);
			k++;
		}
	}
	int ans = 1;
	for(int i = 0; i < n; i++)
		if(mark[i] != mark[perm[i] - 1])
			ans = 0;
	if(ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
