/*
ID: ghoolha1
PROG: ride
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

ofstream fout ("transform.out");
ifstream fin ("transform.in");

//#define cin fin
//#define cout fout

const int Maxn=10;

long long in;
bool pr[1000*1000*1000+25];
vector<long long >pals;

bool palincheck(long long a)
{
    int i=0,j=0;
    long long temp=a,counter=1,ch1=0,ch2=0;
    while(temp>0)
    {
        ch1+=((temp%10)*(1<<i));
        temp/=10;
        i++;
    }
    cerr << endl;
    for (int j=1;j<i;j++)
    {
        counter*=10;
    }
    temp=a;
    while(temp>0)
    {
        ch2+=((temp/counter)*(1<<j));
        j++;
        temp=(temp-((temp/counter)*counter));
        counter/=10;
    }
    return (ch1==ch2);
}
void tr(long long p)
{
    long long temp=p;
    while(p<(1000*1000*1000+10))
    {
        temp+=p;
        pr[p]=true;
        //cerr << temp << endl;
    }
}
int main()
{
    cin >> in;
    cout << palincheck(in);
    pr[0]=true;
    pr[1]=pr[0];
    system("pause");
    for(long long i=0;i<(1000*1000*1000);i++)
    {
        if (palincheck(i))
        {
            pals.push_back(i);
            cerr << i << endl;
        }
        /*if(!pr[i])
        {
            pals.push_back(i);
            tr(i);
        }*/
    }

}
