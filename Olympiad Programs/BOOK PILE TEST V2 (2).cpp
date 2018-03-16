#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const int MAXn = 4*100*100 + 100;
struct node
{
       string name;
       int u,d;
       node()
       {
               u = d = -1 ;
       }
} book[MAXn];
int f=0,l=1,k=0,N,M,T;
string s;
string ttt;
int j=4,Cout=0;
void add(string q)
{
    book[N].name=q;
    book[N].u=(-1);
    book[N].d=l;
    book[l].u=N;
    k=book[k].u;
    l=N;
    j=4;
    N++;
    ttt.clear();
}
void rotate()
{
    int yad=book[k].d;
    int po=k,point=0;
    for(int i=0;i<k; i++)
    {
        point = book[po].u;
        int temper=book[po].u;
        book[po].u=(i!=k) ? book[po].d : (-1);
        book[po].d=(i!=l) ? temper : yad;
        po=point;
    }
    int temp=k;
    k=l;
    l=temp;
}
int main()
{
    cin >> N >> M >> T;
    k=(N-T);
    l=(N-1);
    f=(0);
    string Y[N];
    for (int i=0;i<N;i++)
        cin >> Y[i];
    int h =N-1;
    for (int i=0;i<N;i++)
    {
        book[h].name = Y[i];
        h--;
    }
    for (int i=0;i<N;i++)
    {
        book[i].u = (i!=(N-1)) ? (i+1) : (-1);
        book[i].d = (i!=0) ? (i-1) : (-1);
    }
    for (int i=0;i<M;i++)
    {
        cin >> s;
        if (s=="ROTATE"&& k>0)
            rotate();
        if (s[0]=='A')
            {
            while (s[j]!=')')
            {
                ttt.push_back(s[j]);
                j++;
            }
            add(ttt);
            }
    }
    Cout =l;
    for (int i=N;i>0;i--)
    {
        cout << book[Cout].name<< endl;
        Cout=(book[Cout].d);
        if (Cout == -1)
            i=0;
    }
}
