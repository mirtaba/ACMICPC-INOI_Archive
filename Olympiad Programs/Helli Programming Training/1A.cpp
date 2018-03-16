#include <iostream>
unsigned long long in,out;
unsigned long long  gcd(int a,int b) {return (b?gcd(b,a%b):a);}
int main(){std::cin >> in;for(int i=1;i<=in;i++){out = (gcd(i,in)==1 ? out+1:out);}std::cout<<out<<std::endl;}
