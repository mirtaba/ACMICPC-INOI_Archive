#include <iostream>
#include<cstdio>
using namespace std;

const int MaxN=2*100+9;
const int mNp =9999999;// kochik tarin adadi ke mishe sakht!
int a[MaxN][MaxN],F[MaxN][MaxN],lst[MaxN][MaxN],beg[MaxN][MaxN],f,v,i,j;
void ans(int f,int v)
{
        if(f==0)
                return;
        ans(f-1,beg[f][v]);
        cout << v << " ";
}
int main()
{
        cin >>f>>v;
        for(i=1;i<=f;++i)
                for(j=1;j<=v;++j)
                        cin>>a[i][j];
        for(i=1;i<=f;++i)
                F[i][i-1]=-mNp;
        for(i=1;i<=f;++i)
                for(j=i;j<=v;++j)
                {
                        if(F[i-1][j-1]+a[i][j]>F[i][j-1])
                        {
                                F[i][j]=F[i-1][j-1]+a[i][j];
                                beg[i][j]=lst[i-1][j-1];
                                lst[i][j]=j;
                        }
                        else
                        {
                                F[i][j]=F[i][j-1];
                                beg[i][j]=beg[i][j-1];
                                lst[i][j]=lst[i][j-1];
                        }
                }
        cout << F[f][v]<<endl;
        ans(f-1,beg[f][v]);
        cout << lst[f][v];
        return 0;
}
