/*************************************************************************
	> File Name   : 1094.cpp
	> Author      : Wang,Hongbo
	> Mail        : wanghongbo@ict.ac.cn
	> Created Time: Mon 01 Sep 2014 02:21:08 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int num[10001];
int N,begin,end;

bool deal(int k,int i,int kind)
{
    if(i>=N)
        return false;
    if(kind == 1)
    {
        if(k == num[i])
        {
            end = i;
            return true;
        }
        return deal(k-num[i],i+1,1);
    }
    if(deal(k-num[i],i+1,1))
    {
        begin = i;
        return true;
    }
    else
        return deal(k,i+1,0);
}
int main()
{
    int k;
    cin>>N>>k;

    for(int i = 0; i<N ; ++i)
        cin>>num[i];

    if(deal(k,0,0))
        cout<<begin+1<<" "<<end+1<<endl;
    else
        cout<<"No Solution"<<endl;
}
