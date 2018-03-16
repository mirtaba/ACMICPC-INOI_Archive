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

bool nums[100000+2500]={false,false,true,true,false,true,false,true,false,false};
bool aval[100000+25000];
unsigned long long answer=0;

void count(int in)
{
    long long tor=in;
    {
        int temp=in%10;
        in = ((in-temp)/10)+temp;
        if (nums[in]==true)
            nums[tor]=true;

    }
}

int main()
{
    for(int i=2;i<=100000;i++)
    {
        if(aval[i]==false)
            {
                for(int j=2;j<=(100000/i);j++)
                    {
                        if(i*j<=100000)
                            aval[i*j]=true;
                    }
            }
    }
    for(int i=2;i<100000;i++)
    {
        if (aval[i]==false)
        {
            count(i);
            if((nums[i]==true))
            {
                answer+=i;
            }
        }
    }
    cerr << answer << endl;
    cout << (long long) answer%32057 << endl;
}
