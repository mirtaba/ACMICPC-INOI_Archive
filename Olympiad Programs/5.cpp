#include <iostream>

using namespace std;

int main()
{
    int n=0,k=0,c[100000]={0};
    cin >>n >>k;
    k-=1;
    for(int i=0;i<n;i++)
    {
        char j;
        cin >>j;
        if(j=='<')
        {
            c[i]=-1;
        }
        else
        {
            c[i]=1;
        }
    }

    int m=1;

    for(int i=k;;)
    {
          int l=i;
        i+=c[i];
          c[l]=-c[l];
        if(i<0||i>=n)
        {
            cout << m;
            return 0;
        }
        m++;
    }
     cout<< m;
    return 0;


}
