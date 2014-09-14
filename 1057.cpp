/*************************************************************************
> File Name   : 1057.cpp
> Author      : Wang,Hongbo
> Mail        : wanghongbo@ict.ac.cn
> Created Time: Tue 02 Sep 2014 10:37:50 AM CST
************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

#define RADIX 10000;
unsigned int num1[40000];
unsigned int num2[5];
unsigned int result[40000];

int main()
{
	int N,size1 = 0,size2,k,t;
	int carry,local;
	unsigned int *pnum1 = num1;
	unsigned int *pnum2 = num2;
	unsigned int *pnum3 = result;
	unsigned int *temp;
	cin >> N;
	if(N==1)
	{
		cout<<N;
		return 0;
	}
	k = 2;
	for(int i = 1 ; k != 0 ;++i)
	{
		num1[i] = k%RADIX;
		k /= RADIX;
		++size1;    
	}
	t=3;
	while(t<=N)
	{
		k = t;
		size2 = 0;
		for(int i = 1 ; k != 0 ;++i)
		{
			*(pnum2+i) = k%RADIX;
			k /= RADIX;
			++size2;    
		}
		carry = 0;
		for(int i = 1; i<= size1+size2;++i)
		{
			local = 0;
			for(int j = 1;j<=size2;++j)
			{
				if(i+1-j>0&&i+1-j<=size1)
				{
					local += (*(pnum1+i+1-j))*(*(pnum2+j));
				}
			}
			local += carry;
			*(pnum3+i) = local%RADIX;
			carry = local/RADIX;
		}
		if(local == 0)
			size1 = size1+size2-1;
		else
			size1 = size1+size2;
		temp = pnum1;
		pnum1 = pnum3;
		pnum3 = temp;
		++t;
	}
	unsigned int s;
	cout<<*(pnum1+size1);
	for(int i = size1-1; i>=1; --i)
	{
		s = *(pnum1+i);
		if(s/1000 == 0)
			cout<<0;
		if(s/100 == 0)
			cout<<0;
		if(s/10 == 0)
			cout<<0;
		if(s == 0)
		{
			cout<<0;
			continue;
		}
		cout<<s;
	}
	return 0;
}
