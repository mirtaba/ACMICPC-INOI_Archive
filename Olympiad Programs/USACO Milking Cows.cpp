/*
ID: ghoolha1
PROG: milk2
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

ofstream fout ("milk2.out");
ifstream fin ("milk2.in");

#define cin fin
#define cout fout
const int MAXN=5*100*10+20;

int group[MAXN];
pair <int,int> frm [MAXN];
/*
int partition(int p,int r)
{
    int x=frm[r].first;
    int i=p;
    for (int j=p;j<r;j++)
    {
        if (frm[j].first<x)
        {
            i++;
            swap(frm[i].first,frm[j].first);
            swap(frm[i].second,frm[j].second);
            swap(group[i],group[j]);
        }
    }
    swap(frm[i+1].first,frm[r].first);
    swap(frm[i+1].second,frm[r].second);
    swap(group[i+1],group[r]);
    cout << x << endl;
    return i+1;
}
void Quicksort(int p,int r)
{
    int q = partition(p,r);
    if (p!=(q-1))
        Quicksort(p,q-1);
    if ((q+1)!=r)
        Quicksort(q+1,r);

}*/
int main()
{
    int n,G=1;
    int grandstart[MAXN];
    int grandfinish[MAXN];
    int Max=0,Min=0;
    cin >> n;
    if (n>1)
    {
        group[0]=G;
        for(int i=0;i<n;i++)
        {
            cin >> frm[i].first >> frm[i].second;
            if(i>0)
            {
                grandfinish[i]=1000000;
                grandstart[i]=1000000;
            }
        }
        sort(frm,frm+n);
        grandstart[1]=frm[0].first;
        grandfinish[1]=frm[0].second;
        for(int i=1;i<n;i++)
        {
            if (((grandstart[G]<=frm[i].first)&&(grandfinish[G]>=frm[i].first)))
            {
                group[i]=G;
                grandstart[G]= frm[i].first<grandstart[G] ? frm[i].first : grandstart[G];
                grandfinish[G]= frm[i].second>grandfinish[G] ? frm[i].second : grandfinish[G];
            }
            else
            {
                G++;
                group[i]=G;
                grandstart[G]=(frm[i].first);
                grandfinish[G]=(frm[i].second);
            }
        }
       /*for(int i=0;i<n;i++)
        {
            cout << frm[i].first << ' ' << frm[i].second << ' ' << group[i] << endl;
            if (i>0)
            cout <<grandstart[i]<< ' ' <<grandfinish[i] << endl;
        }*/
        grandfinish[0]=grandstart[1];
        for(int i=1;i<=G;i++)
        {
            Max=(grandfinish[i]-grandstart[i])>Max ? grandfinish[i]-grandstart[i] : Max ;
            Min=(grandstart[i]-grandfinish[i-1])>Min ? grandstart[i]-grandfinish[i-1] : Min ;
        }
    }
    else
    {
        cin >> Max >> Min;
        Max=(Min-Max);
        Min=0;
    }
    cout << Max << ' ' << Min << endl;
}
