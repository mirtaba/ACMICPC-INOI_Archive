#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#define max(a,b) a>b?a:b

using namespace std;

  int dp[105][105];
  int main()
{

      int F, V, i, j, max;
    //while(cin >> F >> V)
    cin >> F >> V;
     {
         for(i = 1; i <= F; i++)
             for(j = 1; j <= V; j++)
                 cin >> dp[i][j];
         for(i = 2; i <= F; i++)
             for(j = i; j <= V + i - F; j++)
             {
                 max = -1000;
                 for(int k = i-1; k < j; k++)
                     max = max > dp[i-1][k] ? max : dp[i-1][k];
                 dp[i][j] += max;
             }
         for(i = 1; i <= F; i++)
         {
             for(j = 1; j <= V; j++)
                 cout << dp[i][j] << " ";
             cout << endl;
         }
         max = -1000;
         for(j = F; j <= V; j++)
             max = max > dp[F][j] ? max : dp[F][j];
         cout << max << endl;
     }
     return 0;
 }
