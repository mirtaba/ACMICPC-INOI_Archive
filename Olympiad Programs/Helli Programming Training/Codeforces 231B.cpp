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
#include <cmath>

#define LL long long

using namespace std;

vector <int> vec;
LL tmp,l,N,d;
int test[10000*10000*10];

void doit(int n,int in)
{
    //cerr << "i'm here" << endl;
    if (n==0 && ((1<=in)&&(in<=l)))
    {
        //cerr << "i'm" << endl;
        for(int i=0;i<vec.size();i++)
        {
            cout << vec[i] << ' ';
        }
        cout << endl;
    }
    else
    {
        //cerr << "i'm there" << endl;
        for(int i=1;i<=l;i++)
        {
            vec.push_back(i);
            doit(n-1,i-in);
            vec.resize(N-n);
        }
    }
}
int main()
{
    cin >> N >> d >> l;
    doit(N,d);
}
