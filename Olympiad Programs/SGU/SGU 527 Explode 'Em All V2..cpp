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

LL cont(LL input)
{
	result=0;
	while (input> 0)
	{
		result+=input%2;
		input=input>>1;
	}
	return result;
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
    LL temp=0;
    for (int i=0;i<(1<<M);i++)
    {
        temp=cont(i);
        for (int j=0;j<N;j++)
        {
            if (temp>=answer)
                break;
            if((cond[j]|i)!=i)
            {
                sum++;
            }
        }
        sum=max(sum,temp);
        if(sum<answer)
            answer=sum;
        sum=0;
    }
    cout << answer << endl;
}



