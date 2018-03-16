#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <utility>

using namespace std;

ofstream fout ("prime numbers.txt");

#define cout fout

const long long MaxN=(100*100*100)+1000;

bool num [MaxN]={0,0,1};

void operat(long long n)
{
    int i=2;
    while( (i*n) <=MaxN )
    {
        num[i*n]=false;
        i++;
    }
}
bool palincheck(int i)
{
    if (i<10)
    {
        return true;
    }
    else
    if (i<100)
    {
        if ((i%10)==(i-i%10))
    }
    else
    if (i<1000)
    {

    }
    else
    if (i<10000)
    {

    }
    else
    if (i<100000)
    {

    }
}
int main()
{
    for (int i=3;i<MaxN;i++)
    {
        num[i]=true;
    }
    num[2]=true;
    for (int i=0;i<2000;i++)
    {
        if (num[i]==true)
            operat(i);
    }
    int j=0;
    for (int i=0;i<MaxN;i++)
    {
        if (num[i]==true)
            {
                cout << i <<',';
                j++;
            }
    }
    cout << j;
}
