/*************************************************************************
> File Name   : 1117.cpp
> Author      : Wang,Hongbo
> Mail        : wanghongbo@ict.ac.cn
> Created Time: Wed 27 Aug 2014 05:00:22 PM CST
************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int stick[50001];

void smallheapdown(int a[],int i,int n)
{
	int j,temp;

	temp = a[i];
	j = 2*i+1;

	while(j<n)
	{
		if(j+1<n&&a[j]>a[j+1])
			++j;
		if(a[j]>=temp)
			break;
		a[i] = a[j];
		i = j;
		j = 2*i+1;
	}
	a[i] = temp;
}

void smallheapsort(int a[],int n)
{
	for(int i = n/2-1;i>=0;--i)
	{
		smallheapdown(a,i,n);
	}
}

int main()
{
	int N,k,e,s,total;
	vector<int> num;
	cin>>N;
	for(int i = 0; i< N; ++i)
		cin>>stick[i];

	total = 0;
	k = N-1;
	smallheapsort(stick,N);
	do
	{
		e = stick[0];
		stick[0] = stick[k];
		smallheapdown(stick,0,k);
		s = stick[0];
		e += s;
		total += e;
		stick[0] = e;
		smallheapdown(stick,0,k--);
	}while(k);
	cout<<total;
	return 0;
}

