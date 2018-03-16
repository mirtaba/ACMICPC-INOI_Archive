/*
ID: ghoolha1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream fout ("ride.out");
ifstream fin ("ride.in");

#define cin fin
#define cout fout

int main()
{
   int A=1,B=1;
   string a, b;
   cin >> a;
   cin >> b;
   for (int i=0;i<a.length();i++)
   {
   A*=(int (a[i])-64);
   }
   for (int i=0;i<b.length();i++)
   {
   B*=(int (b[i])-64);
   }
   if(A%47==B%47)
   {
       cout << "GO" << endl;
   }
   else
   {
       cout <<"STAY" << endl;
   }
   return 0;

}
