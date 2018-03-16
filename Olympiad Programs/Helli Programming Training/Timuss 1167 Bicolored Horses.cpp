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

short N,K,input[Maxn];
unsigned long d[Maxn][Maxn],num0[Maxn],num1[Maxn];

void calculate (int i , int j)
{
    if (j==1)
    {
        d[i][j]=(num1[i]*num0[i]);
    }
    else
    {
        long long mine=9223372036854775807;
        for (int k=min(i-1,j-1);k<=max(i-1,j-1);k++)
        {
            //num0=num0[i-1]-num0[k-1];
           // num1=num1[i-1]-num1[k-1];
            /*for(int t=k;t<i;t++)
            {
                (input[t]) ? (num1++):(num0++);
            }*/
            mine= mine>(d[k][j-1]+((num1[i]-num1[k])*(num0[i]-num0[k]))) ? (d[k][j-1]+((num1[i]-num1[k])*(num0[i]-num0[k]))) :mine;
        }
        d[i][j]=mine;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> N >> K;
    for (int i=1;i<=N;i++)
    {
        cin >> input [i];
        if(input[i])
        {
            num1[i]=num1[i-1]+1;
            num0[i]=num0[i-1];
        }
        else
        {
            num0[i]=num0[i-1]+1;
            num1[i]=num1[i-1];

        }
    }
    /*for (int check=0;check<=N;check++)
    {
        cerr << num0[check] << ' ' << num1[check] << endl;
    }*/
    for (int i=1;i<=N;i++)
    {
        for (int j=1;j<=K;j++)
            calculate(i,j);
    }
    /*for (int i=1;i<=N;i++)
    {
        for (int j=1;j<=K;j++)
            cerr << d[i][j] << ' ';
        cerr << endl;
    }*/
    cout << d[N][K] << endl;
}
