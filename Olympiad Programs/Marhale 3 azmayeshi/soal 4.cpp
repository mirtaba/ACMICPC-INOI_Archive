#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <cmath>

long long in;
int numbs[(8*100*100*100)+50];


using namespace std;

int sub(string num,int rank,int place)
{
    long long ans[8]={0,0,0,0,0,0,0,0},Max=0,j=0;
    for (int i=(place+1);i<8;i++)
    {
        if (num[i]>num[place])
        {
           ans[i]=(sub(num,rank+1,i)) ; 
           j++;                       
        }    
    }
    if (j==0)
       return (rank);
    for (int i=0;i<8;i++)
    {
        Max = (ans[i]>Max)? ans[i] : Max ;
    }
    return (Max);
}

int bigsub(string s)
{
    int MAX=0;
    for (int i=0;i<8;i++)
         MAX=(MAX < sub(s,1,i)) ? sub(s,1,i) : MAX;  
    return MAX;
}

int main()
{
    /**/
    float temp;
    long long count=0,answer=0;
    long long we=0;
    string s;
    /**/
    for (int r=2;r<=8;r++)
    {
        s[0]=r;
        s[1]=r;
        for (int q=0;q<=9;q++)
        {
            s[2]=q;
            for (int y=0;y<=9;y++)
            {
                s[3]=y;
                for (int p=0;p<=9;p++)
                {
                    s[4]=p;
                    for (int t=0;t<=9;t++)
                    {
                        s[5]=t;
                        for (int j =0;j<=9;j++)
                        {
                            s[6]=j;
                            for (int i=0;i<=9;i++)
                            {
                                s[7]=i;
                                numbs[we]=bigsub(s);
                                we++;
                            }
                        }
                    }
                }
            }
        }
    }
    /**/
    for (int i=0;i<(8*100*100*100)+50;i++)
      if((numbs[i]==4)||(numbs[i]==7)) 
      count++; 
      /**/
    cout<<count<<endl;
	answer=((count*77474747LL)/(7LL*10*10*10*10*10*10));
    cout << answer << endl;
    answer=answer%30211;
    answer*=answer;
    answer=answer%30211;
    cout << answer;
    cin >> in;   
    
    
}

