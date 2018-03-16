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
char before[MAXN][MAXN],after[MAXN][MAXN],temp1[MAXN][MAXN],temp2[MAXN][MAXN];

void print(char in[MAXN][MAXN])
{
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cerr << in[i][j];
        }
     cerr << endl;
    }
    cerr << endl;
}
bool comp(char in[MAXN][MAXN],char out[MAXN][MAXN],int n)
{
    bool c=true;
    for (int i=0;i<n;i++)
    {
            for (int j=0;j<n;j++)
            {
                    c = in[i][j]==out[i][j] ? c :  false;
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
            temp1[j][k] = in[i][j];
        }
    }
    return comp(out,temp1,n);
}
bool signal2 (char in[MAXN][MAXN],char out[MAXN][MAXN],int n)
{
    for(int i = 0, r = n-1; i < n; i++, r--)
    {
        for(int j = 0, c = n-1; j < n; j++, c--)
        {
            temp1[r][c] = in[i][j];
        }
    }
    return comp(out,temp1,n);
}
bool signal3 (char in[MAXN][MAXN],char out[MAXN][MAXN],int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0, k = n-1; j < n; j++, k--)
        {
            temp1[k][i] = in[i][j];
        }
    }

    return comp(out,temp1,n);
}
bool signal4 (char in[MAXN][MAXN],char out[MAXN][MAXN],int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0, k = n-1; j < n; j++, k--)
        {
            temp1[i][k] = in[i][j];
        }
    }

    return comp(out,temp1,n);
}
bool signal5 (char in[MAXN][MAXN],char out[MAXN][MAXN],int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0, k = n-1; j < n; j++, k--)
        {
            temp2[i][k] = in[i][j];
        }
    }
    if (signal1(temp2,out,n))
            return true;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0, k = n-1; j < n; j++, k--)
        {
            temp2[i][k] = in[i][j];
        }
    }
    if (signal2(temp2,out,n))
        return true;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0, k = n-1; j < n; j++, k--)
        {
            temp2[i][k] = in[i][j];
        }
    }
    if (signal3(temp2,out,n))
        return true;
    return false;
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
    /* *if((n==3)&&(comp(before,bad,3))&&(comp(after,badbad,3)))
        cout << "hello7" << endl;* */
    if (signal1(before,after,n))
        cout << '1'<< endl;
    else
    if (signal2(before,after,n))
        cout << '2'<< endl;
    else
    if (signal3(before,after,n))
        cout << '3'<< endl;
    else
    if (signal4(before,after,n))
        cout << '4'<< endl;
    else
    if (signal5(before,after,n))
        cout << '5'<< endl;
    else
    if (comp(before,after,n))
        cout << '6' << endl;
    else
        cout << '7' << endl;
}


