/*************************************************************************
> File Name   : 1057.cpp
> Author      : Wang,Hongbo
> Mail        : wanghongbo@ict.ac.cn
> Created Time: Tue 02 Sep 2014 10:37:50 AM CST
************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


int main()
{
	unsigned long long N,P,t;
	cin>>N>>P;
	t = N%P;
	--N;
	while(N>1)
	{
		if(t%P == 0||N%P == 0)
		{
			cout<<0;
			return 0;
		}
		t *= N%P;
		t = t%P;
		--N;
	}
	cout<<t<<endl;
	return 0;
}
