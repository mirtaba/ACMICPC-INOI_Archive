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

#define cin fin
#define cout fout

int A=0;
bool B=0;
string s;
int cal(int a,int b)
{
    if (A>=2)
    {
    int L=0,R=0,i=(a);
    // This most kill the while but it don't.
    while((s[a]==s[i]||s[i]=='w')&& (B==0))
    {
        i--;
        if (i==a)
        {
            B=1;
            L=A;
        }
        if (i<0)
        i+=(A);
        L++;
    }
   // cout << L;
    i=(b);
    while((s[b]==s[i]||s[i]=='w')&& B==0)
    {
        i++;
        if (i>=A)
        i=0;
        R++;
    }
    //cout << R;
    if ((L+R)<= A)
    return(L+R);
    else
    return(A);
    }
    else
   // cout << "TEEEEER";
    return 0;
}
int main()
{
    int max=0;
    cin >> A >> s;
    max =(cal(0,1));
    for (int i=1;i<A;i++)
    {
        if (max < cal(i,i+1))
            max = cal(i,i+1);
    }
    cout << max << endl;

}
