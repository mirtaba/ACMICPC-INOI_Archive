#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <cmath>
#define bigvar vector <int>

const int Base=10;

using namespace std;

long long a,b;
bigvar A,B,AB,BA,Answer;

void print (bigvar ans)
{
	if (!ans.size())
		cout << 0;
	for (int i = ans.size() - 1 ; i >= 0 ; i--)
		cout << ans[i];
	cout << endl;
}

bigvar bbmultiply (bigvar a, int b , int c)//a adad asli va b ragami ast ke dar a zarb mishavad va c martabe(chandomin ragham az samte rast) addad b ast.
{
	bigvar ans;
	for (int i = 1 ; i <= c ; i++)
        ans.push_back(0);
	int carry = 0;
	for (int i = 0 ; i < a.size() ; i++)
	{
		ans.push_back((a[i] * b + carry) % Base);
		carry = (a[i] * b + carry) / Base;
	}
	while (carry)
	{
		ans.push_back (carry % Base);
		carry /= Base;
	}
	while (ans.size() && ans[ans.size() - 1] == 0)
		ans.pop_back ();
	return ans;
}

bigvar bplus(bigvar a , bigvar b)
{
	bigvar ans;
	a.resize(max(a.size() , b.size()) , 0);
	b.resize(max(a.size() , b.size()) , 0);
	int carry = 0;
	for (int i = 0 ; i < max (a.size() , b.size()) ; i++)
	{
		ans.push_back((a[i] + b[i] + carry) % Base);
		carry = (a[i] + b[i] + carry) / Base;
	}
	while (carry)
	{
		ans.push_back(carry % Base);
		carry /= Base;
	}
	while (ans.size() && ans[ans.size() - 1] == 0)
		ans.pop_back();
	return ans;
}

bigvar bminus (bigvar a , bigvar b)
{
	bigvar ans = a;
	b.resize (a.size() , 0);
	int carry = 0;
	for (int i = 0 ; i < a.size() ; i++)
	{
		ans[i] = (a[i] - b[i] + Base - carry) % Base;
		if (carry && a[i] <= b[i])
            carry = 1;
		else    if (!carry && a[i] < b[i])
            carry = 1;
        else
            carry = 0;
	}
	while (ans.size() && ans[ans.size() - 1] == 0)
		ans.pop_back();
	return ans;
}

bigvar bmultiply(bigvar a , bigvar b)
{
    bigvar ans;
    for (int i = 0 ; i < a.size() ; i++)
        ans = bplus(ans , bbmultiply(b , a[i] , i));
    return ans;
}

bool bcompare(bigvar a , bigvar b)
{
    if (a.size() > b.size())
        return 1;
    else
    if (a.size() < b.size())
        return 0;
    int i = a.size() - 1;
    while(a[i] == b[i])
        i--;
    if (a[i] > b[i])
        return 1;
    else
        return 0;
}

bigvar numtobigvar(int input)
{
    bigvar ans;
    while(input > 0)
    {
        ans.push_back(input % Base);
        input /= Base;
    }
    return ans;
}

int main()
{
    cin >> a >> b;
    A=numtobigvar(a);
    B=numtobigvar(b);
    AB=A;
    BA=B;
    for (int i=2;i<=b;i++)
    {
        AB=bmultiply(AB,A);
    }
    for (int i=2;i<=a;i++)
    {
        BA=bmultiply(BA,B);
    }
    if(bcompare(AB,BA))
    {
        Answer=bminus(AB,BA);
        print(Answer);
        return 0;
    }
    else
    {
        if (AB==BA)
        {
            cout << 0 << endl;
            return 0;
        }
        Answer=bminus(BA,AB);
        cout << '-';
        print(Answer);
        return 0;
    }
}
