#include <iostream>

using namespace std;

unsigned long long input,answer,count;

int main()
{
    cin >> input;
    for (int i=1;i<=input;i++)
    {
        count+=i;
        count=(count%3);
        if(count==0)
            answer++;
    }
    cout << answer << endl;
}
