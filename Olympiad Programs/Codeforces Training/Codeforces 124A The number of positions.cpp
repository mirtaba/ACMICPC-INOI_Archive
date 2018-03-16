#include <iostream>
using namespace std;
long long N,A,B,in[1000],ans;
int main()
{
    cin >> N >> A >> B;
    for(int i=1;i<=N;i++)
    {
        if(i>A && (N-i)<=B)
        {
            ans++;
        }
    }
    cout << ans << endl;
}
