#include <bits/stdc++.h>

using namespace std;

const int Maxn = 100 * 100 + 250;

#define FOR(a,b,c) for(int a = b ; a < c ; a++)
#define DFOR(a,b) for(int a = b ; a >= 0 ; a--)


//ofstream fout ("p91.out");

//#define cout fout

int in[Maxn] , goal , n;


int main ()
{

	while(cin >> n && n)
	{
	    in[0] = 100000;
		FOR(i,1,n+1)
		{
			cin >> in[i];
		}
		in[n+1] = 100000;
		n++;
		cin >> goal;

		int lMax = in[goal] + 1;
		int ans = 0;
		FOR(i,goal,n)
		{
			if(lMax<in[i])
			{
				lMax = in[i];
			}
			if(lMax > in[goal])
                break;
			ans += lMax-in[i];
		}
		lMax = in[goal] + 1;
		DFOR(i,goal)
		{
			if(lMax<in[i])
			{
				lMax = in[i];
			}
			ans += lMax-in[i];
		}

        cout << ans<< endl;

	}
}
