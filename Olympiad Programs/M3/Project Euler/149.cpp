#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define X first
#define Y second
#define FOR(i,s,f) for(int i=s;i<f;i++)

const int Maxn = 2000*2000+ 125;
const int Mod = 1000000;
const int Del =  12101;

typedef long long LL;
typedef pair <int ,int> PII;

LL a,b,c,d,e;
LL s[Maxn],m[2000+25][2000+25],d1[2][2000],d2[2][2000],d3[2000],d4[2000],Ans;

int main()
{
    ios::sync_with_stdio(0);
    /**/
    FOR(i,1,56)
    {
        a=100003;
        b=200003;
        c=300007*i;
        c%=Mod;
        c*=i;
        c%=Mod;
        e=(c-b)+Mod;
        e%=Mod;
        e*=i;
        d=a+e;
        d%=Mod;
        d-=500000;
        s[i]=d;
    }
    //cerr << s[10] << endl;
    FOR(i,56,Maxn)
    {
        s[i]=(LL)((LL)((LL)(s[i-24]+s[i-55]+1000000)%1000000)-500000);
    }
    //cerr << s[100] << endl;
    /**
    m[0][0]=-2;
    m[0][1]=5;
    m[0][2]=3;
    m[0][3]=2;
    m[1][0]=9;
    m[1][1]=-6;
    m[1][2]=5;
    m[1][3]=1;
    m[2][0]=3;
    m[2][1]=2;
    m[2][2]=7;
    m[2][3]=3;
    m[3][0]=-1;
    m[3][1]=8;
    m[3][2]=4;
    m[3][3]=8;
    /**
    FOR(i,0,4)
    {
        FOR(j,0,4)
        {
            cerr << m[i][j] << ' ';
        }
        cerr << endl;
    }
    /**/
    FOR(i,0,2000)
    {
        FOR(j,0,2000)
        {
            m[i][j]=s[(i*2000)+j];
            if(i>=j)
            {
                d1[0][i-j]=max(m[i][j],d1[0][i-j]+m[i][j]);
            }
            else
            {
                d1[1][j-i]=max(m[i][j],d1[1][j-i]+m[i][j]);
            }
            if((i+j)<2000)
            {
                d2[0][(i+j)]=max(m[i][j],d2[0][(i+j)]+m[i][j]);
            }
            else
            {
                d2[1][(i+j)%2000]=max(m[i][j],d2[1][(i+j)%2000]+m[i][j]);
            }
            d3[i]=max(m[i][j],d3[i]+m[i][j]);
            d4[j]=max(m[i][j],d4[j]+m[i][j]);
        }
    }
    FOR(i,0,2000)
    {
        Ans=max(Ans,d1[0][i]);
        Ans=max(Ans,d1[1][i]);
        Ans=max(Ans,d2[0][i]);
        Ans=max(Ans,d2[1][i]);
        Ans=max(Ans,d3[i]);
        Ans=max(Ans,d4[i]);
    }
    cout << Ans << endl;

}
