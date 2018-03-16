#include <iostream>
#include <algorithm>

using namespace std;

const long long Maxn=1E7+25;

unsigned long  N;
unsigned long  B[Maxn];
unsigned long  C[Maxn];
unsigned long  D[Maxn];
unsigned long  A[Maxn];

int main()
{
    cin >> N;
    A[1]=1;
    B[1]=1;
    C[1]=1;
    D[1]=0;
    A[2]=B[1]+C[1];
    B[2]=A[1]+C[1];
    C[2]=A[1]+B[1];
    D[2]=A[1]+B[1]+C[1];
    for(int i=3;i<=N;i++)
    {
        A[i]=(B[i-1]+D[i-1]+C[i-1])%(1000000000+7);
        B[i]=(A[i-1]+D[i-1]+C[i-1])%(1000000000+7);
        C[i]=(B[i-1]+D[i-1]+A[i-1])%(1000000000+7);
        D[i]=(B[i-1]+A[i-1]+C[i-1])%(1000000000+7);
    }
    cout << (unsigned long long)(D[N]%(1000000000+7)) << endl;
}
