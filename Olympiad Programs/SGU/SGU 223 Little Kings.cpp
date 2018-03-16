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
#define X first
#define Y second

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const LL Maxn=(10+2);
const LL Maxk=((10*10)+20);
const LL Maxrc=((1<<10)+25);//Maximum row condition posible by problem limitions

LL d[Maxn][Maxk][Maxrc];//[the row that we are now discusing][number of kings used so far][condition of the last row]
LL result,N,K,nums[Maxrc];
ULL answer=0;
bool check[Maxrc][Maxrc];
vector <LL> useable;
LL cont(LL input)
{
	result=0;
	while (input> 0)
	{
		result+=input%2;
		input/=2;
	}
	return result;
}


LL tmp[Maxn][2];

bool chck(LL x, LL y)
{
	for (LL i = 0; i < N; i++)
	{
		tmp[i][0] = x % 2;
		tmp[i][1] = y % 2;
		x /= 2; y /= 2;
	}
	for (LL i = 0; i < N - 1; i++)
	{
		if (tmp[i][0])
			if (tmp[i + 1][0] || tmp[i + 1][1] || tmp[i][1])
				return false;
		if (tmp[i][1])
			if (tmp[i + 1][0] || tmp[i + 1][1])
				return false;
	}
	if (tmp[N - 1][0] && tmp[N - 1][1])
		return false;
	return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> K;
    LL tmp1,tmp2;
    for(LL i=0;i<(1<<N);i++)
    {
        for(LL j=0;j<(1<<N);j++)
        {
            check[i][j]=chck(i,j);
        }
    }
    for(LL i=0;i<(1<<N);i++)
    {
        nums[i]=cont(i);
        if(check[0][i] )
            useable.pb(i);
    }
    for (LL i=0;i<=K;i++)
    {
        for (LL j=0;j<useable.size();j++)
        {
            if(nums[useable[j]]==i && check[0][useable[j]])
                d[0][i][useable[j]]=1;
        }
        for (LL j=1;j<N;j++)
        {
            for (LL p=0;p<useable.size();p++)
			{

				for (LL q=0;q<useable.size();q++)
				{
					if ((check[useable[p]][useable[q]] && check[useable[q]][useable[p]])&& ((i - nums[useable[p]]) >= 0))
						d[j][i][useable[p]]+=d[j-1][i - nums[useable[p]]][useable[q]];
				}
			}
        }
    }
    for (LL i=0;i<(1<<N);i++)
    {
        answer+=d[N-1][K][i];
    }
    cout << answer << endl;
}

