#include <iostream>

#define LL long long

using namespace std;

const long Maxn=(1000*1000)+200;

bool pr[(LL)Maxn];
bool tpr[(LL)10000*10000*10000];

int main()
{
    pr[0]=true;
    pr[1]=pr[0];
    for (LL i=2;i<(Maxn);i++)
    {
        if (!pr[i])
        {
            for(LL j=2;j<(Maxn);i=j++)
            {
                pr[i*j]=true;
            }
        }
    }

}
