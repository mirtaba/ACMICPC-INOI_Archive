#include <iostream>
#include <algorithm>
using namespace std;
const int max_n = 13 ;
int mounth_num [ max_n ];

int main()
{
    int k;
    cin >> k;
    for ( int i = 0 ; i < 12 ; i++ )
        cin >> mounth_num[i];
    sort ( mounth_num , mounth_num + 12 , greater <int>() );
    int sum = 0;
    int num = 0;
    while ( (sum < k) && ( num < 12 ) )
    {
        sum+= mounth_num[num];
        num++;
        //cout <<" sum : "<< sum << endl;
    }
    if ( sum >= k )
        cout << num << endl;
    else
        cout << -1;
    return 0;
}
