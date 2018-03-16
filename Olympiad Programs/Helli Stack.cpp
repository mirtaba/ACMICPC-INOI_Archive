#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 100*100*1000 + 25;

int N, g,f,a[MAX],s[MAX],k;

void insert (int t)
{
	while (a[s[g-1]] <= a[t] && g > f)
		g--;
	s[g++]=t;
	if (s[f] <= (t-k))
		f++;
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> N >> k;
	for (int i=0;i<N;i++)
		cin >> a[i];

	for (int i=0;i<N;i++)
	{
		insert(i);
		if (i>=(k-1))
			cout << a[s[f]] << " ";
	}
	cout << endl;
	return 0;
}
