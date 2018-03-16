#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>

using namespace std;

int nums[100000+2500];
bool aval[100000+25000];
long long answer=0;

int count(int in)
{
    while(in>=10)
    {
        int temp=in%10;
        in = ((in-temp)/10)+temp;
    }
    return(in);
}

int main()
{
    for(int i=2;i<=100000;i++)
    {
        if(aval[i]==false)
            {
                cout << i << endl;
                for(int j=2;j<=50000;j++)
                {
					int t=(i*j);
                    if(t<=100000)
                        aval[t]=true;
				}
            }
    }
    if (aval[2]== false)
    cout << "yes bale" << endl;
    if (aval[4]== false)
    cout << "yes ballllla" << endl;
    for(int i=2;i<=100000;i++)
    {
        if (aval[i]==false)
        {
            nums[i]=count(i);
//          cout << nums[i] << endl;
            if((nums[i]==2)||(nums[i]==3)||(nums[i]==5)||(nums[i]==7))
            {
                answer+=i;
            }
        }
    }
    cerr << answer << endl;
    //cout << (long long) answer%32057 << endl;
}
