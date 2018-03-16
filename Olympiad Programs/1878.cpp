#include <iostream>
#include <algorithm>
using namespace std;
int square[4][4] , color[4];
int maxc , rot , maxr;
int main()
{
    for (int i = 0 ; i < 4 ; i++)
        for (int j = 0 ; j < 4 ; j++)
            cin >> square[i][j];

    for (int i = 0 ; i < 2 ; i++)
        for (int j = 0 ; j < 2 ; j++)
            color[square[i][j] - 1]++ ;

    maxc = max(max(color[0] , color[1]) , max(color[2] , color[3]));

    for (int i = 0 ; i < 4 ;i++)
    {
        if (maxc == color[i])
            maxr = i;
    }
    for (int i = 0 ; i < 2 ; i++)
        for (int j = 0 ; j < 2 ; j++)
            if (square[i][j] != maxr + 1)
            {
                if (abs(maxr - square[i][j] + 1) == 3)
                    rot += 1;
                else
                    rot += abs(maxr - square[i][j] + 1);
            }
    cout << rot << endl;
}
