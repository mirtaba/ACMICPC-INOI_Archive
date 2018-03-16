#include <iostream>
#include <vector>
using namespace std;

const int Del=29123;

// The mysterious function inside the blackbox!
int process(long long x)
{
    cerr << x << endl;
    int y = 0;
    if (x % 2) return -1;
    for (x = x / 2; x > 1; x = x / 2)
    {
        int b = (x + 1) % 2;
        cerr << "B is: " << b << endl;
        y *= 2;
        y += b;
        cerr << "Y is: " << y << endl;
    }
    return y;
}

long long a,Ans;
vector <int> ans;

int main()
{
    a=Del*Del;
    //a=3;
    while(a>0)
    {
        ans.push_back(((a%2)?0:1));
        a/=2;
    }
    /**/
    //reverse(ans.begin(),ans.end());
    Ans=1;
    for(int i=0;i<ans.size();i++)
    {
        Ans*=2;
        Ans+=ans[i];
    }
    Ans*=2;
    cout << Ans << endl;
    /**/
    return 0;
}

