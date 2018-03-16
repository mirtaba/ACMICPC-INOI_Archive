#include <iostream>


using namespace std;

const int Maxn= 10*1000+25;

long long input[Maxn],n,k;
long long cont[Maxn],answer;

int main()
{
    cin >> k >> n;
    for (int i=0;i<n;i++)
    {
        cin >> input[i];
        cont[(input[i]-(input[i]%1000))/1000]++;
    }
    answer=2;
    for(int i=0;i<9;i++)
    {
        answer+=((cont[i]+k-1)/k);
    }
    cout << answer << endl;
}
