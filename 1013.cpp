/*************************************************************************
> File Name   : 1013.cpp
> Author      : Wang,Hongbo
> Mail        : wanghongbo@ict.ac.cn
> Created Time: Thu 04 Sep 2014 11:24:27 AM CST
************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000007
unsigned long long t;

unsigned int deal(unsigned int n)
{
	if(n==1)
		return 3;
	t = deal(n/2);
    return ((1+2*(n%2))*t*t)%MOD;
}

int main()
{
	unsigned int N;
	cin >> N ;
	N = deal(N+1);
	N = (N+MOD-1)%MOD;
	if(N%2)
		cout<<(N+MOD)/2;
	else
		cout<<N/2;
	return 0;
}
