/*
ID: ghoolha1
PROG: milk
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <utility>

using namespace std;

ofstream fout ("milk.out");
ifstream fin ("milk.in");

#define cin fin
#define cout fout

const int Maxm=(5*10*100)+20;
pair <int,long long> milk [Maxm];
long long N,M;

int main ()
{
    cin >> N >> M;
    for (int i=0;i<M;i++)
    {
        cin >> milk[i].first >> milk[i].second;
    }
    sort (milk,milk+M);
    int countprice =0,countamount=N;
    int i=0;
    while (countamount!=0)
    {
        if (milk[i].second <= countamount)
            {
                countamount-=milk[i].second;
                countprice+=(milk[i].first)*(milk[i].second);
                //cout <<(milk[i].first) << ' ' << (milk[i].second) << endl;
                //cout << (milk[i].first)*(milk[i].second) << endl;
            }
            else
            {
                milk[i].second=countamount;
                countprice+=(milk[i].first)*(milk[i].second);
                //cout <<(milk[i].first) << ' ' << (milk[i].second) << endl;
                //cout << (milk[i].first)*(milk[i].second)<< endl;
                countamount=0;
            }
        i++;
    }
    cout << countprice << endl;
}
