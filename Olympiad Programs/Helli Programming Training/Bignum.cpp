#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector <short> anszarb,anszarb1,anszarb2,ansmenha,a,b,beriztosh;
short input1,input2;

void zarb()
{
    for (long long j=0;j<(b.size()+a.size());j++)
    {
        anszarb.push_back(-1);
    }
    for(long long j=0;j<b.size();j++)
        for(long long i=j;i<a.size();i++)
        {
            //anszarb.push_back(a[i]*b[j]);
            if (i>0)
            {
                anszarb[i]+=(anszarb[i-1]/10);
                anszarb[i-1]=(anszarb[i-1]%10);
            }
        }
}
int main()
{
    cin >> input1 >> input2;
    while(input1 > 0)
    {
        a.push_back(input1%10);
        input1/=10;
    }
    reverse(a.begin(),a.end());
        while(input2 > 0)
    {
        b.push_back(input2%10);
        input2/=10;
    }
    reverse(b.begin(),b.end());
    zarb();
    for(int i=0;i<anszarb.size();i++)
    {
        cout << anszarb[i];
    }
    cout << endl;
}
