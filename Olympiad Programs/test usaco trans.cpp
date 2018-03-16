/*
ID: ghoolha1
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

ofstream fout ("transform.out");
ifstream fin ("transform.in");

#define cin fin
#define cout fout

const int MAXN = 10;
int n;
char before [MAXN][MAXN],after [MAXN][MAXN],temp[MAXN][MAXN];

void print(char in[MAXN][MAXN])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << in[i][j];
        }
     cout << endl;
    }
    cout << endl;
}
bool comp(char in[MAXN][MAXN],char out[MAXN][MAXN],int n)
{
    bool c;
    int i=-1;
    while (c == 1 )
    {
        i++;
        for (int j=0;j<n;j++)
        {
            c= in[i][j]==out[i][j] ? 1 :  0;
        }
    }
    return c;
}
bool signal1 (char in[MAXN][MAXN],char out[MAXN][MAXN],int n)
{
    for(int i = 0, k = n-1; i < n; i++, k--)
    {
        for(int j = 0; j < n; j++)
        {
            temp[j][k] = in[i][j];
        }
    }
    //print(temp);
    return comp(out,temp,n);
}
bool signal2 (char in[MAXN][MAXN],char out[MAXN][MAXN],int n)
{
    for(int i = 0, r = n-1; i < n; i++, r--)
    {
        for(int j = 0, c = n-1; j < n; j++, c--)
        {
            temp[r][c] = in[i][j];
        }
    }
    return comp(out,temp,n);
}
bool signal3 (char in[MAXN][MAXN],char out[MAXN][MAXN],int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0, k = n-1; j < n; j++, k--)
        {
            temp[k][i] = in[i][j];
        }
    }

    return comp(out,temp,n);
}
bool signal4 (char in[MAXN][MAXN],char out[MAXN][MAXN],int n)
{
    for(int i = 0, k = n-1; i < n; i++, k--)
    {
        for(int j = 0; j < n; j++)
        {
            temp[k][j] = in[i][j];
        }
    }

    return comp(out,temp,n);
}
bool signal5 (char in[MAXN][MAXN],char out[MAXN][MAXN],int n)
{
    for(int i = 0, k = n-1; i < n; i++, k--)
    {
        for(int j = 0; j < n; j++)
        {
            temp[k][j] = in[i][j];
        }
    }
    if (signal1(temp,out,n)==1)
        return 1;
    if (signal2(temp,out,n)==1)
        return 1;
    if (signal3(temp,out,n)==1)
        return 1;
}
int main()
{
    cin >> n;
    for (int t=0;t<n;t++)
    {
        for (int y=0;y<n;y++)
        {
            cin >> before[t][y];
        }
    }
    for (int t=0;t<n;t++)
    {
        for (int y=0;y<n;y++)
        {
            cin >> after[t][y];
        }
    }
    if (signal1(before,after,n)==1)
        cout << '1';
    else
    if (signal2(before,after,n)==1)
        cout << '2';
    else
    if (signal3(before,after,n)==1)
        cout << '3';
    else
    if (signal4(before,after,n)==1)
        cout << '4';
    else
    if (signal5(before,after,n)==1)
        cout << '5';
    else
    if (comp(before,after,n)==1)
        cout << '6';
    else
        cout << '7';
}
