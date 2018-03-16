#include <iostream>

using namespace std;

int a[10000],k,f;

int main()
{
    a[1]=1;
    k=2;
    f=1;
    while(k<=1375)
    {
        a[k]=a[k-1];
        f=1;
        while(f)
        {
            a[k]++;
            f=0;
            for(int i=(k-1);i>=1;i--)
            {
                for(int j=(i-1);j>=0;j--)
                {
                    if( (a[k]-a[i])==(a[i]-a[j]) )
                    {
                        f=1;
                    }
                }
            }
        }
        k++;
        cout << k-1 << ' ' << a[k-1] << endl;
    }
}
