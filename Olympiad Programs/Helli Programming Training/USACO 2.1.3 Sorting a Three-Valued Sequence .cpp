/*
ID: ghoolha1
PROG: sort3
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

ofstream fout ("sort3.out");
ifstream fin ("sort3.in");

#define cin fin
#define cout fout

const int Maxn=1000+25;

short in[Maxn],ins[Maxn],tmp;
int difer[3][3],N,a,b,c;//a is misplaces of 1&2 b is 1&3 and c is 2&3
long long ans;

int main()
{
    cin >> N;
    for (int i=0;i<N;i++)
    {
        cin >> tmp;
        in[i]=(tmp-1);
        ins[i]=in[i];
    }
    sort(ins,ins+N);
    for (int i=0;i<N;i++)
    {
        difer[in[i]][ins[i]]++;
    }
    a=abs(difer[0][1]-difer[1][0]);
    b=abs(difer[0][2]-difer[2][0]);
    c=abs(difer[1][2]-difer[2][1]);
    ans=min(difer[0][1],difer[1][0])+min(difer[0][2],difer[2][0])+min(difer[1][2],difer[2][1]);
    ans+=2*min(a,min(b,c));
    cout << ans << endl;
}

