#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

long long answer=1,in;

int main()
{
    for (int i=0;i<474747;i++)
    {
        answer*=(747474);
        //cout <<"the original answer is: " << i << ' ' << answer << endl;
        answer=(answer%((1000*1000*1000)+7));    
        //cout <<"the shrinked answer is: "<< answer << endl;
    }
    cout <<"the last answer is: "<<answer<<endl;
    cout << ((answer*747)%30211);
    cin >> in;
}
