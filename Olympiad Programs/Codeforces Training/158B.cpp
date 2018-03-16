#include <iostream>
int t,N,in[5];main() {std::cin>>N;while(std::cin>>t) ++in[t];in[1]=std::max(in[1]-in[3],0);std::cout<< in[4]+in[3]+((in[1]+2*in[2]+3)/4);}
