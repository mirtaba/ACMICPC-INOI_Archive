#include <iostream>
#include <cmath>
#include <cstdio>
#include<algorithm>

using namespace std;
const int MAXn = 100*100*10 +100;
long long array[MAXn],n,start,Max;
int main()
{
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> array[i];
	for (int i=1;i<n;i++)
		{
			if (Max < abs(array[i]-array[i+1]))
				{
					Max=abs(array[i]-array[i+1]);
					start=i;
				}
		}
	cout << start << ' ' << start+1 <<endl;
}
