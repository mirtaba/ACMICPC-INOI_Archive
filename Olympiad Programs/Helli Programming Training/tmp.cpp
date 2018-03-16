#include<stdio.h>

#include<string.h>

#include<stdlib.h>

#include<queue>

#include<algorithm>

#include<vector>

using namespace std;



struct node{

   int val,num;

}s[5010];

int ans[5010];



int tag[12][11]={{2,10,10,10,10,10,10,10,10,10,9},

           {15,99,98,98,98,98,98,98,98,98,97},

           {28,980,978,978,978,978,978,978,978,978,977},

           {41,9781,9778,9778,9778,9778,9778,9778,9778,9778,9777},

           {54,97782,97778,97778,97778,97778,97778,97778,97778,97778,97777},

        {67,977783,977778,977778,977778,977778,977778,977778,977778,977778,977777},

           {2,9,10,10,10,10,10,10,10,10,9},

           {15,97,98,98,98,98,98,98,98,98,97},

           {28,977,978,978,978,978,978,978,978,978,977},

           {41,9777,9778,9778,9778,9778,9778,9778,9778,9778,9777},

           {54,97777,97778,97778,97778,97778,97778,97778,97778,97778,97777},

        {67,977777,977778,977778,977778,977778,977778,977778,977778,977778,977777}

};

int cmp(node a,node b)

{

   return a.val<b.val;

}



int solve(int n, int t, int f)

{

   if (t == 0) {

      if ((n + f) % tag[t][2]== 0)

        return 0;

      else

        return -1;

   }

   if (t == 6) {

      if (f == 0)

        f= 1;

      if ((n + f) % tag[t][2]== 0)

        return 0;

      else

        return -1;

   }

   if (t <= 5&& (n - t) != 0 && (n - t) % tag[t][2] == 0) {

      return t;

   }

   if (t > 5 &&(n + (f == 0 ? (t - 6) : f) + 6 - t) % tag[t][2] == 0)

      return t - 6;

   if (t <= 5&& n < tag[t][1])

      return solve(n, t - 1, f);

   else if (t > 5 &&(n + f - t + 6) < tag[t][2])

      return solve(n, t - 1, f);

   else {

      if (t <= 5)

        return solve((n - t) %tag[t][2], t + 5, t);

      else

        return solve((n + (f == 0 ?(t - 6) : f) + 6 - t) % tag[t][2],t - 1, t - 6);

   }

}



int main() {

   int n, k, c[6];



   scanf("%d%d", &n, &k);

   for (int i = 0; i < k;i++) {

      scanf("%d", &s[i].val);

      s[i].num = i;

   }

   sort(s,s + k, cmp);

   int index = 0;

   c[1]= 1;

   while (s[index].val == 1) {

      ans[s[index].num] = c[1];

      index++;

   }

   int cnt = 0;

   for (int i = 2; i <= 5;i++) {

      c[i]= c[i - 1] + 2;

      while (s[index].val == i) {

        ans[s[index].num] = c[i];

        index++;

      }

   }

   for (int i = 1; i <= 5;i++)

      if (c[i] <= n)

        cnt++;

   int pre = 9, now;

   for (int i = 6;; i++) {

      int t = solve(i - 5, 5,0);

      if (cnt == 14)

        now= pre + 2;

      else if (t == -1)

        now= pre + 11;

      else

        now= pre + tag[t][0];

      if (now > n)

        break;

      while (i == s[index].val) {

        ans[s[index].num] = now;

        index++;

      }

      cnt++;

      pre= now;

   }

   printf("%d\n", cnt);

   for (int i = 0; i < k;i++) {

      if (i == k - 1)

        printf("%d\n", ans[i]);

      else

        printf("%d ", ans[i]);

   }

}
