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

using namespace std;

const int Maxn=1000+25;

int N,M;
bool chart[Maxn][Maxn],origchart[Maxn][Maxn];
char ch;
unsigned long long answer;

void doit(int i,int j)
{
    if(chart[i][j]==false)
    {
        short count=0;
        if(i>0)
            if(chart[i-1][j])
                count++;
        if (i<=N)
            if(chart[i+1][j])
                count++;
        if(j>0)
            if(chart[i][j-1])
                count++;
        if(j<=M)
            if(chart[i][j+1])
                count++;
        if(count>1)
        {
            chart[i][j]=true;
            //if (i>0)
                doit(i-1,j);
            //if (i<=N)
                doit(i+1,j);
            //if(j>0)
                doit(i,j-1);
            //if(j<=M)
                doit(i,j+1);
        }
    }
}
int main()
{
    cin >> N >> M;
    for (int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin >> ch;
            if(ch=='X')
            {
                origchart[i][j]=true;
                chart[i][j]=true;
            }
        }
        cout << endl;
    }
    for (int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(origchart[i][j])
                {
                    //if (i>0)
                        doit(i-1,j);
                    //if (i<=N)
                        doit(i+1,j);
                    //if(j>0)
                        doit(i,j-1);
                    //if(j<=M)
                        doit(i,j+1);
                }
        }
    }
    for (int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(chart[i][j])
                answer++;
        }
    }
    cout << answer ;
}

