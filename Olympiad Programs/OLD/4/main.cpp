#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <vector>
const int max_n = 1000 * 1000 + 10 ;

using namespace std;

string value[max_n];

vector <long long> charfind;

void answer ( long long x )
{
    long long c_place = -1  , r_place = -1 ;

    r_place = value[x].find('R');

    c_place = value[x].find('C');

    if(r_place == -1u )
        r_place = -1;

    if(c_place == -1u )
        c_place = -1;

    if ((( c_place > -1 ) && ( r_place > -1 )) && ((value[x][r_place+1] < 58 ) && ( value[x][r_place+1] >47 )))
    {
        long long sum = 0 , sum2 = 0;
        for ( long long i  = r_place ; i < c_place ; i++ )
        {
            if (( value[x][i] > 47 ) && ( value[x][i] < 58 ))
                sum = ( sum * 10 ) + ( value[x][i] - '0' );
        }
        for ( long long i = c_place ; i < value[x].size() ; i++ )
        {
            if (( value[x][i] > 47 ) && ( value[x][i] < 58 ))
                sum2 = ( sum2 * 10 ) + ( value[x][i] - '0' );
        }
        //cout << sum <<"  "<<sum2<<endl;
        string answer_me ;
        bool flag = true;
        while(flag == true)
        {
            if ( sum2 < 26)
            {
                flag = false;
            }
            //cerr<< "im here" << endl;
            charfind.push_back(sum2%26);
            sum2 /= 26;
        }
        reverse(charfind.begin(),charfind.end());
        for (long long i=0;i<charfind.size();i++)
            {
                answer_me+=char(64+charfind[i]);
            }
    cout << answer_me <<sum<< endl;
    answer_me="";
    }
    else
    {
        long long sum = 0 , sum2 = 0;
        for ( long long i = 1 ; i < value[x].size() ; i++ )
        {
            if (( value[x][i] > 47 ) && ( value[x][i] < 58 ))
                sum = ( sum * 10 ) + ( value[x][i] - '0' );
        }
        for ( long long i = 0 ; i < value[x].size() ; i++ )
        {
            if (( value[x][i] > 64 ) && ( value[x][i] < 91 ))
                sum2 = ( sum2 * 26 ) + ( value[x][i] - 'A' + 1 );
        }
        cout << "R" << sum << "C"<<sum2<<endl;
    }
    charfind.clear();
}


int main()
{
    long long n;
    cin >> n ;
    for ( long long i = 0 ; i < n ; i++ )
    {
        cin >> value[i];
    }
    for ( long long i = 0 ; i < n ; i++ )
    {
        answer ( i );
    }
    return 0;
}
