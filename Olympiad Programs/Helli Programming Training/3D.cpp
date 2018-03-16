#include <iostream>
#include <algorithm>

using namespace std;

int N,input[110][110];

int main()
{
    cin >>N;
    int maxe=0;
    for (int i=0;i<N;i++)
    {
        cin >> input[i][0];
        for (int j=1;j<(2*(input[i][0]-1));j++)
        {
            cin >> input[i][j];
            if (maxe<input[i][j])
                maxe=input[i][j];

        }
    }
    cout << maxe << endl;
    //system("pause");
}
