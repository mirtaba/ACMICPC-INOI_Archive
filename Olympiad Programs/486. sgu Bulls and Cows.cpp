#include <iostream>
#include <cmath>
#include <cstdio>
#include<algorithm>

using namespace std;
const int MAXn = 100 *100 *10 +50;
string s,g;
int b=0,c=0,t1=0,t2=0;
int main()
{
    cin >> s >> g;
    t1=(s.size());
    t2=(g.size());
    for (int i=0;i<t1;i++)
        for (int d=0;d<t2;d++)
        {
            if(s[i]==g[d])
                {
                //cout << "in if";
                b=(i==d)?b+1:b;
                c=(i!=d)?c+1:c;
                }
        }
    cout << b << ' ' <<  c;
}
