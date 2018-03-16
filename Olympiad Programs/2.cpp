#include <iostream>
#include <set>


using namespace std;

const int Maxn= 10*1000+25;

int input[Maxn],n,k;
int cont[Maxn],answer;
set <int> check;

int main()
{
    cin >> k >> n;
    for (int i=0;i<n;i++)
    {
		int tempo=check.size();
        cin >> input[i];
        check.insert(input[i]);
        if(tempo<check.size())
        	cont[(input[i]-(input[i]%1000))/1000]++;
    }
    answer=2;
    
    for(int i=0;i<=9;i++)
    {
		//cout << cont [i] <<endl<<"<==========>"<<endl;
        answer+=((cont[i]+k-1)/k);
    }
    cout << answer << endl;
    //system("pause");
}
