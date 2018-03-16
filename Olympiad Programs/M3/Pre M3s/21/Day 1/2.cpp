#include <iostream>
#include <vector>

const int Del=29123;

#define FOR(i,s,f) for(int i=s;i<f;i++)
using namespace std;

const int Maxn=2000*2000+225;

typedef long long LL;

vector <int>p;
int m[Maxn];
int tmp,Ans;
bool mark[Maxn];

void cal(int x)
{
    FOR(i,0,p.size())
    {
        tmp=0;
        while((x%p[i])==0)
        {
            x/=p[i];
            tmp++;
        }
        m[i]=max(m[i],tmp);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    tmp=1;
    FOR(i,2,2012)
    {
        cerr << i << endl;
        if(!mark[i])
        {
            p.push_back(i);
            m[p.size()-1]=1;
            for(int j=(i*i);j<Maxn;j+=i)
            {
                mark[j]=1;
            }
        }
        else
            cal(i);
    }
    Ans=1;
    FOR(i,0,p.size())
    {
        FOR(j,0,m[i])
        {
            Ans*=p[i];
            Ans%=Del;
        }
    }
    cout << Ans << endl;
}
