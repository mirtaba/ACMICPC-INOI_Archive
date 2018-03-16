#define bigvar vector <int>

void print (bigvar ans)
{
	if (!ans.size())
		cout << 0;
	for (int i = ans.size() - 1 ; i >= 0 ; i--)
		cout << ans[i];
	cout << endl;
}

bigvar bmultiply (bigvar a, int b , int c)
{
	bigvar ans;
	for (int i = 1 ; i <= c ; i++)
        ans.push_back(0);
	int carry = 0;
	for (int i = 0 ; i < a.size() ; i++)
	{
		ans.push_back((a[i] * b + carry) % 10);
		carry = (a[i] * b + carry) / 10;
	}
	while (carry)
	{
		ans.push_back (carry % 10);
		carry /= 10;
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
		ans.push_back((a[i] + b[i] + carry) % 10);
		carry = (a[i] + b[i] + carry) / 10;
	}
	while (carry)
	{
		ans.push_back(carry % 10);
		carry /= 10;
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
		ans[i] = (a[i] - b[i] + 10 - carry) % 10;
		if (carry && a[i] <= b[i])
            carry = 1;
		else    if (!carry && a[i] < b[i])
            carry = 1;
        else    carry = 0;
	}
	while (ans.size() && ans[ans.size() - 1] == 0)
		ans.pop_back();
	return ans;
}

bigvar bbmultiply(bigvar a , bigvar b)
{
    bigvar ans;
    for (int i = 0 ; i < a.size() ; i++)
        ans = bplus(ans , bmultiply(b , a[i] , i));
    return ans;
}

bool bcompare(bigvar a , bigvar b)
{
    if (a.size() > b.size())
        return 1;
    else if (a.size() < b.size())
        return 0;
    int i = a.size() - 1;
    while(a[i] == b[i])
        i--;
    if (a[i] > b[i])
        return 1;
    else    return 0;
}

bigvar numtobigvar(int input)
{
    bigvar ans;
    while(input > 0)
    {
        ans.push_back(input % 10);
        input /= 10;
    }
    return ans;
}
