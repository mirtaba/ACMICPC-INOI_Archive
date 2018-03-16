#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    long long a;
    cin >> a;
    a=(a & (-a));
    int cnt=0;
    while (a)
    {
          cnt++;
          a>>=1;
    }
    cout << cnt-1 << endl;
}
