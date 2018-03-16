#include <iostream>
#include <vector>

using namespace std;

bool a[1000*1000*1000];
vector <unsigned long long> nums;

unsigned long long sumnum(int x)
{
    long long ans=0;
    while(x>0)
    {
        ans+=(x%10);
        x/=10;
    }
    return ans;
}

void doit(unsigned long long in )
{
    cerr << in << endl;
    if (!a[in] && (unsigned long long)in < (1000*1000*100))
    {
        a[in]=true;
        doit(in+sumnum(in));
    }
}

int main()
{
    for(unsigned long long i=1;i<=(1000*1000*10+500);i++)
    {
        cerr << i << " 1";
        if (!a[i])
        {
            cerr << " 2";
            nums.push_back(i);
            cerr << " 3";
            doit(i+sumnum(i));
            cerr << " 4"<< endl;
        }
    }
}
