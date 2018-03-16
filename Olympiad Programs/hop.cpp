#include <iostream>
using namespace std;

int main()
{
int n=2,k=9,hop=0;
cin >> n >> k;
for(int i=1;i<=k;i+=n+1)
{
if(i%5==0)
{
hop++;
}
}

cout << hop;
}
