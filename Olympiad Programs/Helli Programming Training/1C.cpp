#include <iostream>

using namespace std;

unsigned long long input,answer,count;

int main()
{
    cin >> input;
    answer=2*(input/3);
    input=(input%3);
    answer=(input==2) ? answer+1 : answer;
    cout << answer << endl;
}
