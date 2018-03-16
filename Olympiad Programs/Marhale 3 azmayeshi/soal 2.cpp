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

long long fx[1000*1000+250];
long long answer;

void cal (int num)
{
	long long j=2;
	long long t=((num*j)+1);
	while (t<=(1000*1000))
	{
		fx[t]++;
		j++;
		t=((j*num)+1);
	}
}

int main()
{
	int answerplace=0;
	long long Max=0; 
	fx[1]=1;
	for (int i=1;i<=1000*1000;i++)
	{
		if (fx[i]!=0)
			cal(i);
	}
	for (int i=1;i<=1000*1000;i++)
	{
		//cout << "number " << i << ' ' << fx[i] << ' ' ;
		
		if (Max < fx[i])
		{
			Max=(fx[i]);
			cout << "max is:" << Max << endl;
			answerplace=(i);
			cout << "place is:" << answerplace << endl;
		}
		
	}
	//cout << "number is " << Max << endl;
	//cout << "place is " << answerplace << endl;
	cout << (answerplace*Max)%30211;
	cin >> answer;
	
	
}
