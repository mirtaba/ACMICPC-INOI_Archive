/*
ID: ghoolha1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
bool IsLeapYear(int year)
{
  if(year % 100 == 0)
  {
    if(year % 400 == 0)
      return true;
    else
      return false;
  }
  else if(year % 4 == 0)
    return true;

  return false;
}
const int START_YEAR = 1900;
const int NO_OF_MONTHS = 12;
const int NO_OF_WEEKS = 7;
main()
{
  ofstream cout ("friday.out");
  ifstream cin ("friday.in");

  int n; //input
  int curr13thDay = 7 % NO_OF_WEEKS; // saturday = first 13th day of start_year (1990)
  int counterOf13ths[NO_OF_WEEKS] = {0}; // index 0 = saturday, index 1 = sunday...
  int noOfDaysOfEachMonth[NO_OF_MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};

  // increment the day where the 13th occured in january of start_year (1990), that is, saturday

  while(cin >> n)
  {
    //this for loop iterate through each month of start_year (1990)
    for(int year = START_YEAR; year < START_YEAR + n; year++)
    {
      for(int month = 0; month < NO_OF_MONTHS; month++)
      {
        counterOf13ths[curr13thDay] += 1;

        if(month == 1) // if computing for March 13
        {
          if( IsLeapYear(year))
            noOfDaysOfEachMonth[month] = 29;
          else
            noOfDaysOfEachMonth[month] = 28;
        }

        curr13thDay = (curr13thDay + noOfDaysOfEachMonth[month]) % NO_OF_WEEKS;
      }
    }


    // output
    for(int i = 0; i < NO_OF_WEEKS; i++)
    {
      if(i)
        cout << " ";
      cout << counterOf13ths[i];
    }
    cout << endl;
  }//end of while loop

}
