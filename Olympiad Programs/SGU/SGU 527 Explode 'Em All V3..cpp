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

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const LL Maxn=(25+5);
const LL Maxrc=(1<<25)+25;

int N,M,result;
LL cond[Maxn],sum,answer;

void doit(int x,int y,int s)
{
	if(y>=answer)
		return ;
	if(x==M)
	{
		int sum=0;
		for(int j=0;j<N;j++)
			if((cond[j]|s)!=s)
				sum++;
		sum=max(y,sum);
		if(sum<answer)
			answer=sum;
		return ;
	}
	doit(x+1,y+1,s|(1<<x));
	doit(x+1,y,s);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    char tmp;
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            cin >> tmp;
            if(tmp=='*')
                cond[i]+=(1<<j);
        }
    }
    answer=min(N,M);
    doit(0,0,0);
    cout << answer << endl;
}



