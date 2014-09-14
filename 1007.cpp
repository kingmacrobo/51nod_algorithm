/*************************************************************************
	> File Name   : 1007.cpp
	> Author      : Wang,Hongbo
	> Mail        : wanghongbo@ict.ac.cn
	> Created Time: Wed 03 Sep 2014 09:49:21 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int a[101];
int sum;
int record[2][101][5001]; 
int N;

int deal(int k, int t)
{
	int q = 0,p = 0;
	if(k==N-1)
	{
		if(a[k]<t)
			return a[k];
		else
			return 0;
	}	
	if(a[k]<t)
	{
		if(!record[0][k+1][t-a[k]])
			record[0][k+1][t-a[k]] = deal(k+1,t-a[k])+a[k];
		q = record[0][k+1][t-a[k]];
	}
	if(!record[1][k+1][t])
		record[1][k+1][t] = deal(k+1,t);
	p = record[1][k+1][t];
	return p>q?p:q;
}

int main()
{
    cin >> N;
    for(int i = 0 ; i < N ; ++i)
	{
        cin >> a[i];
		sum += a[i];
	}
	int t = deal(0,sum/2+1);
    cout << sum - 2*t;
}
