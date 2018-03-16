/*
ID: ghoolha1
PROG: frac1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

ofstream fout ("frac1.out");
ifstream fin ("frac1.in");

#define cin fin
#define cout fout

int N;

void gener(int s1,int s2,int m1,int m2)
{
    if ((m1+m2)<=N)
    {
        gener(s1,s1+s2,m1,m1+m2);
        cout << s1+s2 << '/' << m1+m2 << endl;
        gener(s1+s2,s2,m1+m2,m2);
    }
}

int main()
{
    cin >> N;
    cout << "0/1" << endl;
    gener(0,1,1,1);
    cout << "1/1" << endl;
}
