#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

const int Maxn=1000;

int N;
double x[Maxn],y[Maxn],dis[Maxn];
double tempx,tempy,tempdis,tempsqrt,Mindis=10000,Maxdis;

int main()
{
    cin >> N;
    for (int i=0;i<N;i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            if (i!=j)
            {
            tempx=abs(x[i]-x[j]);
            tempy=abs(y[i]-y[j]);
            tempdis=pow(tempx,2)+pow(tempy,2);
            tempsqrt=sqrt(tempdis);
            Mindis = Mindis > tempsqrt ? tempsqrt:Mindis;
            }

        }
        dis[i]=Mindis;
        Mindis=10000;
    }
    Maxdis=0;
    for (int i=0;i<N;i++)
    {
        Maxdis= Maxdis < dis[i] ? dis[i] : Maxdis;
    }
    //cout << Maxdis << endl;
    Maxdis*=10;
    if( (Maxdis + 0.5) >= (int(Maxdis)) && Maxdis!=(int(Maxdis)))
    {
        Maxdis=floor(Maxdis);
        Maxdis/=10;
        cout << Maxdis;
        if (Maxdis==int (Maxdis))
        cout<<".0";
    }
    else
    {
        Maxdis=floor(Maxdis);
        Maxdis/=10;
        cout << Maxdis;
        if (Maxdis==int (Maxdis))
        cout<<".0";
    }
}
