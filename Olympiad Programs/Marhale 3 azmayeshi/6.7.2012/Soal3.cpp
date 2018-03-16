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

long long gogols[1000*1000*100+25],magols[1000*1000*100];

int main()
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
	long long t=0;
	for (int j=1;j<(2*i+2);j++)
	{
	    for (int p=1;p<(2*(i+1));p++)
	    {
	        magols[t]=gogols[j]+gogols[p];
	        t++;
	    }
	}
	sort(magols,magols+(2*(i+1)));
	long long j=1,cont=1;
	while (( count < (2*i+2)) && (j!=0))
	{
	    if (magols[j-1]!=magols[j])
            cont++;
        if (j=((2*(i+1))))
            j=0;
        j++;
	}
}
