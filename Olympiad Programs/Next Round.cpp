#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXi=10*10+20;

int N;
int K,k;
int a[MAXi];

int main()
{
    cin >> N >> k;

    for (int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    sort(a,a+N);
    K=a[N-k];
    int count=0;
    for(int i=0;i<N;i++)
    {
        if (a[i]>=K && a[i]>0)
         count++ ;
    }
    cout << count << endl;

}
