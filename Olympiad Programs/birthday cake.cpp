#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

const int Maxn=50;
int k;
long long a[Maxn],b[Maxn],c[Maxn];
long long Minc;
bool check=true;

int main()
{
    cin >> k;
    for (int i=0;i<k;i++)
    {
        cin >> a[i];
    }
    for (int i=0;i<k;i++)
    {
        cin >> b[i];
        c[i]=(b[i]/a[i]);
    }
    Minc=c[0];
    for (int i=0;i<k;i++)
    {
        Minc= Minc>c[i] ? c[i] : Minc;
    }
    cout << Minc << endl;
}
