#include<iostream>
using namespace std;

int Binarysearch(int*a,int c,int d,int key)
{   if(d<=c)
    return c;
    if(a[(c+d)/2]<key)
    { c = (c+d)/2 + 1;
      return Binarysearch(a,c,d,key);
    }
    else{ d = d-(c+d)/2;
          return Binarysearch(a,c,d,key);
    }
}

int main()
{   cout<<"Size: ";
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    int end[n];// Storing the end elements of the sequences formed till now.

    end[0] = a[0];
    int len = 1;

    for(int i=1;i<n;i++)
    {
      if(a[i]<end[0])
      { end[0] = a[i];
        continue;
      }
      else if(a[i]>=end[len-1])
           { end[len++] = a[i];
              continue;
           }
           else{
                 // Binary searh in end[] for smallest element greater than a[i]
                 int c = 0;
                 int d = len-1;
                 int j =  Binarysearch(end,c,d,a[i]);
                 end[j] = a[i];

                }

      }

      cout<<"Size of Longest Sequence:- "<<len<<endl;

      return 0;
}
