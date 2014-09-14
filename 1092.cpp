/*************************************************************************
	> File Name   : 1092.cpp
	> Author      : Wang,Hongbo
	> Mail        : wanghongbo@ict.ac.cn
	> Created Time: Mon 01 Sep 2014 10:00:20 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

char str[1001];
int record[1000][1000];

int deal(int begin , int end)
{
    if(begin == end||begin == end -1 && str[begin] == str[end])
        return 0;
    if(str[begin] == str[end])
    {
        if(!record[begin+1][end-1])
            record[begin+1][end-1] = deal(begin+1,end-1);
        return record[begin+1][end-1];
    }
    int a,b;
    if(!record[begin+1][end])
        record[begin+1][end] = deal(begin+1,end);
    a = record[begin+1][end]+1;
    if(!record[begin][end-1])
        record[begin][end-1] = deal(begin,end-1);
    b = record[begin][end-1]+1;
    return a<b?a:b;
}
int main()
{
    string str1;
    cin>>str1;
    for(int i = 0;i<str1.size();++i)
        str[i] = str1[i];
    cout<<deal(0,str1.size()-1)<<endl; 
}
