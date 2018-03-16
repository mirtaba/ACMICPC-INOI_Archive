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

using namespace std;

long long in;
bool nums[(12*11*10*9*8*7*6*5*4)][12];
bool check(int s[12])
{
	bool num[12]={0,0,0,0,0,0,0,0,0,0,0,0};
	for (int i=0;i<12;i++)
	{
		if(num[int(s[i])]==true)
		return false;
		else
		num[int(s[i])]=true;
	}
	return true;
}
bool doublecheck (int s[12])
{
	if (s[0]>s[1])
	{
		for (int i=1;i<6;i++)
			if(s[2*i]<s[(2*i)+1]) 
				return false;
		for (int i=0;i<6;i++)
			if (s[(2*i)+1]>s[(2*i)+2])
				return false;
	}
	else
	{
		for (int i=1;i<6;i++)
			if(s[2*i]>s[(2*i)+1]) 
				return false;
		for (int i=0;i<6;i++)
			if (s[(2*i)+1]<s[(2*i)+2])
				return false;
	}
	return true;
		
}




int main()
{
    /**/
    long long count=0,answer=0,K=0;
    int s[12]={1,2,3,4,5,6,7,8,9,10,11,12};
    /*
	if (check(s)==true)
    cout << "OK";
    if (doublecheck(s)==true)
    cout << "Very OK";
    */
    
    /**
    for (int r=1;r<=12;r++)
    {
        s[0]=r;
        for (int o=1;o<=12;o++)
        {
		if(nums[K][o]==false)
		{
        s[1]=o;
        for (int q=1;q<=12;q++)
        {
			if(nums[K][q]==false)
			{
            s[2]=q;
            for (int y=1;y<=12;y++)
            {
				if(nums[K][y]==false)
				{
                s[3]=y;
                for (int p=1;p<=12;p++)
                {
					if(nums[K][p]==false)
					{
                    s[4]=p;
                    for (int t=1;t<=12;t++)
                    {
						if(nums[K][t]==false)
						{
                        s[5]=t;
                        for (int j =1;j<=12;j++)
                        {
							if(nums[K][j]==false)
							{
                            s[6]=j;
                            for (int i=1;i<=12;i++)
                            {
								if(nums[K][i]==false)
								{
                                s[7]=i;
                                for (int w=1;w<=12;w++)
                                {
									if(nums[K][w]==false)
									{
									s[8]=w;
									for (int a=1;a<=12;a++)
									{
										if(nums[K][a]==false)
										{
										s[9]=a;
										for (int z=1;z<=12;z++)
										{
											if(nums[K][z]==false)
											{
											s[10]=z;
											for (int u=1;u<=12;u++)
											{
												if(nums[K][u]==false)
												{
												s[11]=u;
												if (doublecheck(s)==true)
													count++;
												cout << count << endl;
												if (K=2)
												{
													for (int i=0;i<12;i++)
													{
														nums[K-2][i]=false;
													}
													K=(-1);
												}
												K++;
											}}
										}}
									}}
								}}	
                                
                            }}
                        }}
                    }}
                }}
            }}
        }
		}
		}
    }
}
    /**/
    for (int i=0;i<(12*11*10*9*8*7*6*5*4*3*2LL);i++)
    {
	next_permutation(s,s+12);
    	if(doublecheck(s)==true) 
    		count++;
    		cout << count << endl;
	}
    cout << count << endl;
    cout << (count%30211LL);
    cin >> in;
}

