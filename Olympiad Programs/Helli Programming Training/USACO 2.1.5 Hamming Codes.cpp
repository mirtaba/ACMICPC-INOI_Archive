/*
ID: ghoolha1
PROG: hamming
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

ofstream fout ("hamming.out");
ifstream fin ("hamming.in");

#define cin fin
#define cout fout

const int mm=1<<8;
const int oo=1e9;
int a,b,c,len;
int hamm[79],lham;
int hamming_length(int x,int y)
{
    int z=x^y;
    int ans=0;
    while(z>0)
    {
    if(z&1)
    ans++;
    z>>=1;
    }
    return ans;
}
void dfs(int dep)
{
    if(dep==a)
        return;
    int i,j;
    for(i=1;i<len;i++)
    {
        bool flag=0;
        for(j=0;j<lham;j++)
            if(hamming_length(i,hamm[j])<c)
            {
                flag=1;break;
            }
        if(!flag)
        {
            hamm[j]=i;
            lham++;
            break;
        }
    }
    dfs(dep+1);
}

int main()
{
    cin>>a>>b>>c;
    len=1<<b;
    lham=1;
    hamm[0]=0;
    dfs(1);
    cout<<"0";
    for(int i=1;i<lham;i++)
        if(i%10==0)
            cout<<"\n"<<hamm[i];
        else
        cout<<" "<<hamm[i];
    cout<<"\n";
    return 0;
}
