#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

long long Fibo[100];;

int fibocal(int i)
{
    Fibo[0]=1;
    Fibo[1]=1;
    if (i>1)
    {
        for (int j=2;j<i;j++)
            Fibo[j]=(Fibo[j-1]+Fibo[j-2]);
    }
    return Fibo[i-1];
}

int main ()
{
    int N=0;
    cin >> N;
    cout << fibocal(N);
}
