#include <iostream>

using namespace std;

int main()
{
    long long n , m , a ;
    cin >> n >> m >> a;
    long long l , h ;
    h = (n / a );
    if ( (n % a) != 0)
        h++;
    l = (m / a );
    if ( (m % a) != 0)
        l++;
    cout << l*h << endl;
    return 0;
}
