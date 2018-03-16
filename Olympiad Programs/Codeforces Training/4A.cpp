#include <iostream>
int w,W;main()
{
    std::cin>>W;
    std::cerr << W;
    w=W%2;
    if(w || W==2)
    std::cout<<"NO";
        else
    std::cout<<"YES";
}
