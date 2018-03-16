#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

long long gogols[1000*1000*100+25],magols[1000*1000*100];

int mian()
{
	gogols[1]=4;
	gogols[2]=7;
	long long i=0;
	while (gogols[(2*i)+2]<=(1000*1000*1000))
	{
		i++;
		cout << gogols[i] << endl;
		gogols[(2*i)+1]=((gogols[i]*10)+4);
		gogols[(2*i)+2]=((gogols[i]*10)+7);
	}
}
