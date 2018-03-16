 /*
ID:ghoolha1
PROG:beads
LANG:C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("beads.in");
ofstream fout("beads.out");

//#define cin fin
//#define cout fout

int len;
string s;
int cal(int a)
{
    if (s[a]!='w')
    {
    int L=0,R=1,i=(a-2),base=(a-1);
    while(s[base]==s[i]||s[i]=='w')
    {
        i--;
        if (i<0)
        i+=(len);
        if(s[base]=='w' && s[i]!='w')
        {
            base=i;

        }
        L++;
    }
    cout << "L:" <<L;
    i=(a+1);
    while((s[a]==s[i])||(s[i]=='w'))
    {
         i++;
        if (i==len)
        i=0;
        R++;
    }
    cout << "R:" <<R;
    if ((L+R)<= len)
    return(L+R);
    else
    return(len);
    }
    return(0);
   // cout << "TEEEEER";
}
int main()
{
    int max;
    cin >> len >> s;
    max =(cal(0));
    for (int j=0;j<len;j++)
    {
        cout << (cal(j)) << " ";
        /*if (max < cal(i))
            max = cal(i);8*/
    }
    cout << max << endl;
}
