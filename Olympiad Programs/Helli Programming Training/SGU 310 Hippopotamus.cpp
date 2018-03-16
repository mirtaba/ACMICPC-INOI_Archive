// The Program uses a bitmask approch and uses dynamic programing
// if you are interested in learning it take a look at these and search for it in stackoverflow.com:
// www.ugrad.cs.ubc.ca/~cs490/sec202/notes/dp/DP%202.pdf
// http://en.wikipedia.org/wiki/Mask_%28computing%29    (Thanks to S.Mosavi)
// also remmeber that "LL" after a number means : consider it as long long (Thanks to M.Tahmasebi)
// Author: 2Taba Got accepted at 3:39 (almost morning) 7/31/2012 (10/5/1391) Afther a lot of effort :D
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

const long long Maxn=60+25 , Maxm=(1<<15)+25;

unsigned long long d[Maxn][Maxm],sum[Maxm],Maxnum,N,M,k,answer;
//d[length][if we observe the last 'm' digit we get the number in this place]=number of acceptable conditions
// sum[number t]=number of 1 in binary view of the number t(mean how much iron boards)

long long make(long long input,int lastdigit)
{
    if (lastdigit==0)
    {
        return (sum[input]<k)? -1:((((Maxnum>>1) & input)<<1)+lastdigit);
    }
    else
    {
        return ((sum[input]+1)<k)? -1:((((Maxnum>>1) & input)<<1)+lastdigit);//guarantee to have exact m digits
    }
}

int main()
{
    cin >> N >> M >> k;
    if(k==0)
    {
        cout << (1LL<<(N)) << endl;
        return 0;
    }
    else
    if(k==M)
    {
        cout << 1 << endl;
        return 0;
    }
    else
    {
        Maxnum=(1<<(M-1))-1;
        d[N][Maxnum]=1;
        unsigned long long temp=0;
        for (int i=0;i<=Maxnum;i++)
        {
            temp=i;
            while(temp)
            {
                if(temp%2)
                    sum[i]++;
                temp/=2;
            }
        }
        for (int i=(N-1);i>=0;i--)
        {
            for (int j=0;j<=Maxnum;j++)
            {
                temp=make(j,0);// you could generate all make(j,0) and make(j,1) for all j from 0 to Maxnum one time and just use it here, it means more space for less time
                if(temp!=-1)
                    d[i][j]+=d[i+1][temp];
                d[i][j]+=d[i+1][make(j,1)];
            }
        }
        for(int i=0;i<=Maxnum;i++)
        {
            answer+=d[0][i];
        }
        cout << answer << endl;
        return 0;
    }
}


