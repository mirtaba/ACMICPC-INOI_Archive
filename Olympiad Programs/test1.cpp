#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int s[10];

int main()
{
    int i=0;
    while (i<10)
    {
        cin >> s[i];
        i++;
    }
    sort(s[0],s[9]);
    i=0;
    while (i<10)
    {
        cout << s[i] << endl;
        i++;
    }
}
