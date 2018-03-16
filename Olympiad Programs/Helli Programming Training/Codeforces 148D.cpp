#include <iostream>
#include <algorithm>
#include <cstdio>
#include <iomanip>

using namespace std;

const int Maxn=1E3+25;

unsigned int W,B;
bool cando[Maxn][Maxn];
double dp[Maxn][Maxn];

double doit(int w,int b, int person)//person 0 is princes , 1 is dragon and 2 is mices itself :D
{
	if(w<0||b<0)
        return 0;
    else
    if(w==0 && b==0)
        return 0;
    else
	if(!cando[w][b])
	{
		cando[w][b]=1;
		if(person==2)
		{
			dp[w][b]=double(w)/(w+b)*doit(w-1,b,0)+double(b)/(w+b)*doit(w,b-1,0);
		}
		else
		{
			dp[w][b]=double(w)/(w+b)*double((person==0))+double(b)/(w+b)*doit(w,b-1,person+1);
		}
	}
	return dp[w][b];
}
int main()
{
	cin >> W >> B;
    cout << fixed << setprecision(9) << doit(W,B,0) << endl;
	return 0;
}
