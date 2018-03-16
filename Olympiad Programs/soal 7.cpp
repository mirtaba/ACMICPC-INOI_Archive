#include <iostream>

using namespace std;


int fib[10000000]={0};

int fibo(int i)
{
if(fib[i]!=0)
{
return fib[i];
}
if(i==0||i==1)
{

return 1;
}
else
{
fib[i]=fibo(i-1)+fibo(i-2);
return fib[i];
}
}

int r(int i)
{
if(i<3)
{
return i;
}
else
{
return fibo(i)+r(i-2);
}
}

int main()
{
fib[0]=1;
fib[1]=1;

int a,b,n;;
cin>>a>>b;

n=b-a;

cout << (r(n+1)*fibo(a))+(r(n)*fibo(a-1));

return 0;
}
