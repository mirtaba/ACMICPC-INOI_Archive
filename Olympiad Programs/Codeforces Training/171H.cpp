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

long long input, iteratorlike, x, y;

void check()
{
	if(iteratorlike == 0)
	{
        cout << x << ' ' << y << endl;
	}
	iteratorlike--;
}

void U()
{
	y++;
	check();
}

void D()
{
	y--;
	check();
}

void R()
{
	x++;
	check();
}

void L()
{
	x--;
	check();
}
//A= Up --> Right --> Down
//B=Down --> Left --> Up
//C=Left --> Down --> Right
//D=Right --> Up --> Left
void A(int);
void B(int);
void C(int);
void D(int n)
{
	if(n > 0)
	{
		A(n - 1);
		R();
		D(n - 1);
		U();
		D(n - 1);
		L();
		B(n - 1);
	}
}

void A(int n)
{
	if(n > 0)
	{
		D(n - 1);
		U();
		A(n - 1);
		R();
		A(n - 1);
		D();
		C(n - 1);
	}
}
void B(int n)
{
	if(n > 0)
	{
		C(n - 1);
		D();
		B(n - 1);
		L();
		B(n - 1);
		U();
		D(n - 1);
	}
}

void C(int n)
{
	if(n > 0)
	{
		B(n - 1);
		L();
		C(n - 1);
		D();
		C(n - 1);
		R();
		A(n - 1);
	}
}

int main()
{
	cin >> input >> iteratorlike;
	check();
	A(input);
}
