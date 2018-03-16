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

int d[10][82];//[number of digits][sum]
int ans[82];//calculated number of each sum goes there
int N;

int main()
{
    for(int i=0;i<10;i++)
    {
        d[1][i] = 1;
    }
    for(int i=2;i<10;i++)
    {
        for(int j=1;j<82;j++)
        {
            for(int t=j;(t>0&&t>=j-9);t--)
            {
                d[i][j]+=d[i-1][t];
            }
        }
    }
    ans[0]=1;
    ans[1]=10;
    for(int j=2;j<82;j++)
    {
        for(int i=1;i<10;i++)
        {
            ans[j]+=d[i][j];
        }
    }
    cin >> N;
    cout << ans[N]<<endl;
}
