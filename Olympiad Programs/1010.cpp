#include <iostream>
#include <algorithm>
const int maxn = 1000 * 100 + 100 ;
long long maxval[3] , val[maxn] ;
using namespace std;
int main()
{
    int n ;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> val[i];
    }
    for (int i = 1 ; i <= n - 1 ; i++)
    {
        if (maxval[2] < abs(val[i] - val[i + 1])  || i == 1 )
        {
            maxval[0] = i ;
            maxval[1] = i + 1;
            maxval[2] = abs(val[i] - val[i + 1]);
        }
    }
    cout << maxval[0] << " " << maxval[1] << endl;
}
