#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

const int max_n = 1000 * 1000 + 10 ;

int n;
string input[max_n];
vector <long long> charfind;


bool kindfind(string in)
{
    bool Kind = false;
		if(in[0] == 'R'&&in[1] >= '1'&&in[1] <= '9')
		{
			for(int i=2;i<in.length();i++)
			{
				if(in[i]=='C')
				{
					Kind = true;
					break;
				}
			}
		}
}
void answer(string str,bool kind)
{
    if(kind)
    {
    long long c_place = -1  , r_place = -1 ;
    r_place = str.find('R');
    c_place = str.find('C');
    if(r_place == -1u )
        r_place = -1;
    if(c_place == -1u )
        c_place = -1;

        long long sum = 0 , sum2 = 0;
        for ( long long i  = r_place ; i < c_place ; i++ )
        {
            if (( str[i] > 47 ) && ( str[i] < 58 ))
                sum = ( sum * 10 ) + ( str[i] - '0' );
        }
        for ( long long i = c_place ; i < str.size() ; i++ )
        {
            if (( str[i] > 47 ) && ( str[i] < 58 ))
                sum2 = ( sum2 * 10 ) + ( str[i] - '0' );
        }
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
    charfind.clear();
    }
    else
    {
        int i, c = -1, p = 1;
        for(i = 0; str[i] > '9'; i++, c += p, p *= 26);
            for(int k = 0; k < i; k++)
            {
                p /= 26;
                c += (str[k] - 'A') * p;
            }
        c++;
        cout << 'R' << str.substr(i) << 'C' << c << endl;
    }
}

int main()
{
	cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> input[i];
    }
    for (int i=0;i<n;i++)
    {
        answer(input[i],kindfind(input[i]));
    }

	return 0;
}
