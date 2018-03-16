#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int Maxn=300+25;

vector <int> answer;
vector <int> tmpcoin;
int coins [Maxn],X;
short N;
bool cando[100*100+25][Maxn];

bool candoit(int coinnum)
{
    tmpcoin.clear();
    for(int i=0;i<N;i++)
    {
        if(!(i==coinnum))
            tmpcoin.push_back(coins[i]);
    }
	memset(cando , 0 , sizeof cando);
	cando[0][0]=true;
	int tmp=0;
	for (int i=1;i<=tmpcoin.size();i++)
	{
		for(int j=0;j<=X;j++)
		{
			if ( cando[j][i-1] || ((j-tmpcoin[i-1])>=0 && cando[j-tmpcoin[i-1]][i-1]))
				{
                    cando[j][i]=true;
				}
		}
	}
	for (int i=1;i<=tmpcoin.size();i++)
        if (cando[X][i])
            tmp++;
	if (tmp==0)
        return true;
    else
        return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> X;
	for (int i=0;i<N;i++)
	{
		cin >> coins[i];
	}
	for (int i=0;i<N;i++)
	{
		if (candoit(i))
			answer.push_back(i);
	}
	cout << answer.size() << endl;
	for(int i=0;i< answer.size();i++)
	{
		cout <<' '<<coins[answer[i]] ;
	}
}
