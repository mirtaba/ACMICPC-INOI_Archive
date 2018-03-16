#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

vector<double> info;
double a=0,c=0;

int main()
{
	long long count=0;
	while (cin)
	{
		cin >> a;
		info.push_back(a);
		count=(count+1);
	}
	for(int i=1;i<(count);i++)
	{
		info.pop_back();
		c=sqrt(info.back());
		//cerr << info.back();
		cout.precision(4);
		cout << fixed << c << endl;
		//info.pop_back();
	}
	//system("pause");
}
