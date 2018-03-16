#include <iostream>

using namespace std;

unsigned  int d[46],N,K,check=1;

int main()
{
    cin >> N >> K;
    d[1]=1;
    d[0]=1;
    for (int i=2;i<=(N+1);i++)
    {
        d[i]=(d[i-1]+d[i-2]);
    }
    if (K>d[N+1])
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i=N;i>0;i--)
    {
        if (check ==1)
        {
            if((d[i-1]+d[i-2])<K)
            {
                K-=(d[i-1]+d[i-2]);
                cout << 1;
                check=2;//started with 1
                continue;
            }
            else
            {
                cout<< 0;
                check=1;//started with 0
                continue;
            }

        }
        if (check ==2)
        {
            cout << 0;
            check=1;
            continue;
        }
    }
    cout << endl;
    return 0;
}
