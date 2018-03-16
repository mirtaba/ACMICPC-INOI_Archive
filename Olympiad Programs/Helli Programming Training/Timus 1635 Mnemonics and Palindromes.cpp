#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

const int Maxn=4*1E3+25;

string S;
bool ispal[Maxn][Maxn];
long long d[Maxn],place[Maxn];
vector <int> anspl;

void ispalev(int pivot)
{
    int i=pivot;
    int j=pivot+1;
    while( i>=0 && j<=S.size() )
    {
        if(S[i]==S[j])
        {
            ispal[i][j]=true;
            ispal[j][i]=true;
            i--;
            j++;
        }
        else
            break;
    }
}
void ispalod(int pivot)
{
    int i=pivot;
    int j=pivot;
    while( i>=0 && j<=S.size() )
    {
        if(S[i]==S[j])
        {
            ispal[i][j]=true;
            ispal[j][i]=true;
            i--;
            j++;
        }
        else
            break;
    }
}

void getitdone(int t)
{
    if (t==0)
    {
        anspl.resize(d[S.size()-1]-1);
        reverse(anspl.begin(),anspl.end());
    }
    else
    {
        anspl.push_back(t);
        getitdone(place[t-1]);
    }
}

int main()
{
    cin >>  S;
    for(int i=0;i<S.size();i++)
    {
        ispalev(i);
        ispalod(i);
    }
    for(int i=0;i<S.size();i++)
    {
        d[i]=((ispal[0][i])? 1 : 0);
        if(d[i]==1)
            place[i]=0;
        else
        {
            d[i]=9223372036854775807;
            for(int j=1;j<=i;j++)
            {
                if (ispal[j][i])
                {
                    if (d[i] > d[j-1]+1)
                    {
                        d[i]=d[j-1]+1;
                        place[i]=j;
                    }
                }
                else
                {
                    if (d[i] > (d[j-1]+(i-j+1)))
                    {
                        d[i]=(d[j-1]+(i-j+1));
                        place[i]=i;
                    }
                }
            }
        }
    }
    cout << d[S.size()-1] << endl;
    if (d[S.size()-1]==1)
        cout << S << endl;
    else
    {
        getitdone(place[S.size()-1]);
        /*for (int i=0;i<anspl.size();i++)
        {
            cerr << anspl[i] << ' ';
        }
        cerr << endl;*/
        int iter=0;
        for (int i=0;i<S.size();i++)
        {
            if (i==anspl[iter])
            {
                cout<< ' ';
                iter++;
            }
            cout << S[i];
        }
        cout << endl;
        /*for (int i=0;i<S.size();i++)
        {
            cerr << place[i] << ' ';
        }
        cerr << endl;*/
    }
    return 0;
}

