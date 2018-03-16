/*
ID: ghoolha1
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

ofstream fout ("transform.out");
ifstream fin ("transform.in");

//#define cin fin
//#define cout fout

struct node
{
    int chart[3][3];
    bool flag=false;
    int parent=(-1);
}
