//**************************************
// Name: Milking Cows
// Description:This is my solution to USACO's programming contest problem named "Milking Cows". Please go to the URL below to read the problem specification.
//jeremiahflaga.blogspot.com/2011/09/milking-cows-programming-problem-from.html</h3>

// By: Jeremiah (Jboy) Flaga
//
//This code is copyrighted and has// limited warranties.Please see http://www.Planet-Source-Code.com/vb/scripts/ShowCode.asp?txtCodeId=13658&lngWId=3//for details.//**************************************

/*
ID: jeremia4
PROG: milk2
LANG: C++
*/
//Milking cows - brute force
#include <iostream>
#include <bitset>
#include <fstream>
#define N 1000000
using namespace std;
main()
{
ifstream cin("milk2.in");
ofstream cout("milk2.out");
long n; // no of data
cin >> n;
bitset<N> a;
long begin, end,
 largest = 0, smallest = N, // largest anf smallest input data
 longestcontinuous = 0, longestidle = 0;
//storing data in bitset
for(int i = 0; i < n; i++)
{
cin >> begin >> end;
//
for(int j = begin + 1; j <= end; j++)
a.set(j);
if(begin < smallest) smallest = begin + 1;
if(end > largest) largest = end;
}
//determining longest continuous and longest idle
long toggler = 0, start = smallest;
for (long i = smallest; i <= largest + 1; ++i)
{
if(a[i] != toggler)
{
if(toggler == 1)
{
if(i - start > longestcontinuous)
longestcontinuous = i - start ;
toggler = 0;
start = i;
}
else // if toggler == 0
{
if(i - start > longestidle)
longestidle = i - start;
toggler = 1;
start = i;
}
}
}
cout << longestcontinuous << " " << longestidle << endl;
//system("pause");
}
