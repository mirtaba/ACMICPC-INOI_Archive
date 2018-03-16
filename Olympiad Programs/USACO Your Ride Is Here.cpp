/*
ID: ghoolha1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
char s[6],p[6];
 ofstream fout ("ride.out");
ifstream fin ("ride.in");

int main()
{
    int S=1,P=1;
    for (int i=0;i<6;i++)
    {
        fin >> s[i];
        if (s[i]!='\o')
        S*=(int(s[i])-64);
    }

    for (int i=0;i<6;i++)
    {
        fin >> p[i];
         if (p[i]!='\o')
         P=(P*(int(p[i])-64));
    }
    /*  for (int i=0;i<6;i++)
    {
        cout << int(s[i]-64) << endl;
    }
        for (int i=0;i<6;i++)
    {
        cout <<  int(p[i]-64) << endl;
    }
    cout << (S%47) << (P%47);
    */
    if ((S%47)==(P%47))
      fout<<"GO"<<endl;
    else
      fout<<"STAY"<<endl;

}
