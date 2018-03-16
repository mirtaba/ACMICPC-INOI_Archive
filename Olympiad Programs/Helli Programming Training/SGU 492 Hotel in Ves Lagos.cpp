#include <iostream>

using namespace std;

unsigned long d[25][15],N,numtestcase,arr[25];

void preprocess()
{
    d[0][0]=1;
    for (int i=1;i<=19;i++)
    {
        for (int j=0;j<10;j++)
        {
            for (int t=0;t<10;t++)
            {
                if (j==1 && t==3)
                    continue;
                d[i][j]+=d[i-1][t];
            }
        }
    }
}

void doit(int n)
{
    n++;
    for (int i=0;i<19;i++)
    {
        for (int j=0;j<10;j++)
        {
            if (i && arr[i-1]==1 && j==3)
                continue;
            if ( n-d[19-i][j] > 0)
                n-=d[19-i][j];
            else
            {
                arr[i]=j;
                break;
            }
        }
    }
    int i;
    for (i=0;i<19 && !arr[i];i++);
        for (;i<19;i++)
            cout<<arr[i];
    cout<<endl;
}

int main()
{
    preprocess();
    cin >> numtestcase;
    for (int v=0;v<numtestcase;v++)
    {
        cin >> N;
        doit(N);
    }
    return 0;
}
