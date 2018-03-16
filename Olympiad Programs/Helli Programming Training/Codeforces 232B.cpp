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
#include <cmath>

#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second

using namespace std;

typedef long long LL;

typedef pair <int, int> PII;

const int maxn = 1000 + 5;
const int mod = 1000 * 1000 * 1000 + 7;

LL N,a,b,c,tmp;

LL sum(LL inp)
{
    int S=0;
    while(inp>0)
    {
        S+=inp%10;
        inp/=10;
    }
    return S;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N;
    a=0;
    b=N;
	while(!(((a+1)==c)&&((c+1)==b)))
	{
        c=(a+b)/2;
        cerr << a << ' ' << c << ' ' << b << endl;
	    system("pause");

        if (c<N)
        {
            if((c*c)<N)
            {
                tmp=((c*c)+(sum(c)*c));
                if(tmp==N)
                {
                    cout << c << endl;
                    return c;
                }
                else
                if(tmp>N)
                {
                    b=c;
                }
                else
                {
                    a=c;
                }
            }
            else
            {
                b=c;
            }
        }
        else
        {
            b=c;
        }
	}
	cout << -1 << endl;
	return -1;
}
