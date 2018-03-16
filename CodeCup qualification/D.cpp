/*
ID: One O'clock
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//ofstream fout ("gift1.out");
//ifstream fin ("gift1.in");

//#define cin fin
//#define cout fout

int a=0,b[15],Q,P;
string s[15],S,j[15];

void give (string p,int t,int d)
{
    for (int i=1;i<=a;i++)
    {
        if(p==s[i]&&d!=0)
        b[i]+=(t/d);
    }
}
void remain(string p,int t,int d)
{
    for (int i=1;i<=a;i++)
    {
        if(p==s[i]&&d!=0)
        b[i]=(b[i]-t+(t%d));
    }
}
int main()
{
    cin >> a;
    for (int i=1;i<=a;i++)
    {
        cin >> s[i];
    }
    for (int i=1;i<=a;i++)
    {
        cin >> S >> Q >> P;
        for(int i=1;i<=P;i++)
        {
        cin >> j[i];
        give(j[i],Q,P);
        }
        remain(S,Q,P);
    }
    for (int i=1;i<=a;i++)
    {
        cout << s[i] << ' ' << b[i]<<endl;
    }

}


