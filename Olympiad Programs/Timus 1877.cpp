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

int a,b;
bool d=false,e=false;

int main()
{
	cin >> a;
	cin >> b;
	if (a%2==0)
	d=true;
	if (b%2==1)
	e=true;
	if (d||e)
	cout << "yes" << endl;
	else
	cout << "no" << endl;	
}
