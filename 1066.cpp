/*************************************************************************
	> File Name   : 1066.cpp
	> Author      : Wang,Hongbo
	> Mail        : wanghongbo@ict.ac.cn
	> Created Time: Mon 01 Sep 2014 04:40:25 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
char record[2][10000000];
char deal(int role,int n)
{
    if(role == 0)
    {
        if(n==1||n==3||n==4)
            return 1;
        if(n-1>0)
        {
            if(record[1][n-1]==3)
            {
                record[1][n-1] = deal(1,n-1);
            }
            if(record[1][n-1]==1)
                return 1;
        }
        if(n-3>0)
        {
            if(record[1][n-3]==3)
            {
                record[1][n-3] = deal(1,n-3);
            }
            if(record[1][n-3]==1)
                return 1;
        }
        if(n-4>0)
        {
            if(record[1][n-4]==3)
            {
                record[1][n-4] = deal(1,n-4);
            }
            if(record[1][n-4]==1)
                return 1;
        }
        else 
            return 0;
    }
    else
    {
        if(n==1||n==3||n==4)
            return false;
        if(n-1>0)
        {
            if(record[0][n-1]==3)
                record[0][n-1] = deal(0,n-1);
            if(record[0][n-1]==1)
            {
                 if(n-3>0)
                 {
                     if(record[0][n-3]==3)
                        record[0][n-3] = deal(0,n-3);
                     if(record[0][n-3]==1)
                     {
                        if(n-4>0&&deal(0,n-4))
                        {
                            if(record[0][n-4]==3)
                                record[0][n-4] = deal(0,n-4);
                            if(record[0][n-4])
                                return 1;
                            else
                                return 0;
                        }
                        else
                            return 0;
                     }
                     else
                        return 0;
                }
                else
                    return 0;
            }
            else
                return 0;
        }
        else
            return 0;
    }
}

int main()
{
    int T,N;
    cin>>T;
	memset(record,3,2*1000000);
    while(T--)
    {
        cin>>N;
        if(deal(0,N))
            cout<<"A"<<endl;
        else
            cout<<"B"<<endl;
    }
    return 0;
}
