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

const int Maxn=5*1E2+25;

short N;
unsigned long long d[Maxn][Maxn],answer;

int main()
{
    cin >> N;
    for(int i=3;i<=N;i++)
    {
        //cerr << "i'm here" << i/2 <<endl;
        for(int j=(i-1);j>0;j--)
        {
            //cerr << j << ' ' << ((i-1)/2) << endl;
            if (j>((i-1)/2)&&j!=i/2)
                d[i][j]=1;
            for(int t=0;t<j;t++)
                d[i][j]+=d[i-j][t];
            //cerr << i << ' ' << d[i][j] << ' ' << j <<endl;
        }
        //d[i]= (i%2) ? d[i] : d[i]-1;
    }
    for (int i=0;i<N;i++)
    {
        answer+=d[N][i];
    }
    cout << answer << endl;
}
