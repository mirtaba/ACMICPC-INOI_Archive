/*
ID: ghoolha1
PROG: preface
LANG: C++
*/

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
#include <fstream>

using namespace std;

ofstream fout ("preface.out");
ifstream fin ("preface.in");

#define cin fin
#define cout fout

using namespace std;
const int mm=3600;
const int one[]={1,2,3,1,0,1,2,3,1,0};
const int five[]={0,0,0,1,1,1,1,1,0,0};
const char flee[]={'I','V','X','L','C','D','M'};
int f[mm][10];
void dp(int m)
{
    for(int i=1;i<=m;i++)
    {
        int num=i;
        for(int j=0;j<7;j++)
        {
            if(num<=0)
            {
                f[i][j]+=f[i-1][j];
                continue;
            }
            if(num%10)
            {
                if(j&1)
                    f[i][j]+=f[i-1][j]+five[num%10-1];
                else
                {
                    f[i][j]+=f[i-1][j]+one[num%10-1];
                    if(num%10==9)
                        f[i][j+2]++;
                }

            }
            else
            {
                f[i][j]+=f[i-1][j]+one[num%10-1];
            }
            if(j&1)
                num/=10;
        }
    }
}
int main()
{
    int m;
    cin>>m;
    dp(m);
    for(int i=0;i<7;i++)
    {
        if(f[m][i])
            cout << flee[i] << " " << f[m][i] << "\n";
    }
}
