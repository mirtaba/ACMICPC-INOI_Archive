#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int x,a,k;

int main()
{
    cin >> x;
    a=0;
    int d=(x/2);
    while (x>0)
    {
        k=(x%2);
        if (k==0)
            a++;
        x=(x/2);
    }
    cout << a <<endl;
}
