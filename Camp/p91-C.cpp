#include <bits/stdc++.h>

using namespace std;

const int Maxn = 100 * 100 + 250;

#define FOR(a,b,c) for(int a = b ; a < c ; a++)
#define DFOR(a,b) for(int a = b ; a >= 0 ; a--)

int in[Maxn] , goal , n;

ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
#define cout fout




int main ()
{
    int tt = 0;

	while(cin >> n && n)
	{
        in[0] = 10000;
		FOR(i,1,n+1)
		{
			cin >> in[i];
		}
		in[n+1] = 10000;
		n+=2;

		cin >> goal;

		int lMax = in[goal] +1;
		int ans = 0;
		FOR(i,goal+1,n)
		{
			if(in[i] >= (in[goal]+1) ){
                cerr << "HI" << i << endl;
                break;
			}
            cerr << "jfdf" << (in[goal] +1)-in[i] << endl;
			ans += (in[goal] +1)-in[i];
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

        cout <<  ans << endl;

	}
}
