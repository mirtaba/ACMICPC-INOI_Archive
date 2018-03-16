#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

#define mp make_pair
#define pb push_back
#define pf push_front
#define X first
#define Y second
#define FOR(i,s,f) for(int i=s;i<f;i++)

const int Maxn=1000*1000;
const int Mod = 1000 *1000 *1000 +7;
const int Del = 33083;

deque <bool> s,tp;
int tmp,fl,Ans,in1,in2;
bool flag;

void mk (int a)
{
    tp.clear();
    while(a>0)
    {
        tp.pb(a%2);
        a/=2;
    }
    for(int i=tp.size()-1;i>=0;i--)
    {
        s.pb(tp[i]);
    }
}


int main()
{
    ios::sync_with_stdio(0);
    /**/
    FOR(i,1,Maxn+1)
    {
        mk(i);
    }
    /**/
    //s.pb(1);s.pb(1);s.pb(0);s.pb(1);s.pb(0);s.pb(1);
    fl=1;
    in1=0;
    in2=(s.size()-1);
    while(in1!=in2)
    {
        if(!flag)
        {
            tmp=s[in1];
            in1++;
        }
        else
        {
            tmp=s[in2];
            in2--;
        }
        if(tmp==fl)
        {
            //cerr << 1 << endl;
            fl=( (fl==0)?1:0 );
            Ans++;
            Ans%=Del;
        }
        else
        {
            //cerr << 0 << endl;
            flag=( (flag==0)?1:0 );
        }
        //system("pause");
    }
    if(!flag)
    {
        tmp=s[in1];
        in1++;
    }
    else
    {
        tmp=s[in2];
        in2--;
    }
    if(tmp==fl)
    {
        //cerr << 1 << endl;
        fl=( (fl==0)?1:0 );
        Ans++;
        Ans%=Del;
    }
    else
    {
        //cerr << 0 << endl;
        flag=( (flag==0)?1:0 );
    }
    cout << Ans << endl;
    /**
    FOR(i,0,20)
    {
        cerr << s[i] << ' ';
    }
    cerr << endl;
    /**/
}
