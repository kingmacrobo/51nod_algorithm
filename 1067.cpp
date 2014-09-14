/*************************************************************************
	> File Name   : 1067.cpp
	> Author      : Wang,Hongbo
	> Mail        : wanghongbo@ict.ac.cn
	> Created Time: Tue 02 Sep 2014 10:16:09 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int T,N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        if(N%7 == 2 || N%7 == 0)
            cout<<"B"<<endl;
        else
            cout<<"A"<<endl;
    }

}
