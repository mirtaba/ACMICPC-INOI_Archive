#include <iostream>

using namespace std;

int L;
int prices[10];
int dyn[1004];

int a(int curSum)
{
    if (dyn[curSum] != 0) //Dynamic
    {
        return dyn[curSum];
    }
    //Recursive
    if (curSum == L)
    {
        return 0;
    }
    else
    {
        int r = L - curSum;
        if (r > 10)
        {
            r = 10;
        }
        int maxPrice = a(curSum + 1) + prices[0];
        for (int i = 2; i <= r; i++)
        {
            int bb = a(curSum + i) + prices[i-1];
            if (bb > maxPrice)
            {
                maxPrice = bb;
            }
        }
        dyn[curSum] = maxPrice;
        return maxPrice;
    }
}

int main()
{
    cin >> L;
    for (int i = 0; i < 10; i++)
    {
        cin >> prices[i];
    }
    cout << a(0);
}
