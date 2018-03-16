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
#include <iostream>

using namespace std;

const int Maxn=1E3+25;

string str1,str2;

long long d[Maxn][Maxn];

int main()
{
    cin >> str1 >> str2;
    long long maxe=0;

    for (int i=1;i<=str1.size();i++)
    {
        for (int j=1;j<=str2.size();j++)
        {
            if(str1[i-1]==str2[j-1])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j-1],max(d[i][j-1],d[i-1][j]));
            //cerr << d[i][j] << ' ';
            maxe = maxe < d[i][j] ? d[i][j] : maxe;
        }
        //cerr << endl;
    }
    cout << maxe << endl;
}

