#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 300, MAXX = 10000+10;

int N, X, coin[MAXN];
vector <int> ans, v;
bool dp[MAXX][MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> X;
	for (int i = 0 ; i < N ; i++)
		cin >> coin[i];
	for (int i = 0 ; i < N ; i++)
	{
		v.clear();
		for (int j = 0 ; j < N ; j++)
			if (i!=j)
				v.push_back(coin[j]);
		memset (dp, 0, sizeof dp);
		dp[0][0] = 1;
		for (int k = 1 ; k <= (int)v.size() ; k++)
			for (int j = 0 ; j <= X ; j++)
				if (dp[j][k-1] || (j - v[k - 1] >= 0 && dp[j-v[k - 1]][k-1]))
					dp[j][k] = 1;
		int count = 0;
		for (int j = 1 ; j <= (int)v.size() ; j++)
			if (dp[X][j])
				count++;
		if (count == 0)
			ans.push_back(i);
	}
	cout << ans.size() << endl;
	for (int i = 0 ; i < (int)ans.size() ; i++)
		cout << coin[ans[i]] << " ";
	cout << endl;
	return 0;
}
