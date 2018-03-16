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

unsigned long long d[10][15][90];//[last digit][lenght][sum]
short S;



int main()
{
    for (int i=0;i<10;i++)
    {
        d[i][1][i]=1;
    }
    cin >> S;
    for (int i=2;i<=10;i++)
    {
        for (int t=0;t<10;t++)
        {
            for (int j=0;j<10;j++)
            {
                d[t][i][S]
            }
        }
    }
}

