/*************************************************************************
 > File Name   : 1010.cpp
 > Author      : Wang,Hongbo
 > Mail        : wanghongbo@ict.ac.cn
 > Created Time: Wed Sep 10 09:54:53 2014
 ************************************************************************/

#include<iostream>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define MAX 1000000000000000000
#define maxcounts 60*60*60
int maxnum;

unsigned long long a[maxcounts];

unsigned long long find(unsigned long long n)
{
    int begin = 1,end = maxnum;
    unsigned long long temp = 0;
    while(begin<=end)
    {
        if(n == a[(begin+end)/2])
            return a[(begin+end)/2];
        else if(n>a[(begin+end)/2])
        {
            begin = (begin+end)/2+1;
        }
        else
        {
            temp = a[(begin+end)/2];
            end = (begin+end)/2-1;
        }
    }
    return temp;
}

int main()
{
    int T;
    unsigned long long n;
    int s = 0, t = 0 ,r = 0;
    a[0] = 1;
    for(int i = 1; i<=maxcounts;++i)
    {
        a[i] = min(2*a[s],min(3*a[t],5*a[r]));
        maxnum++;
        if(a[i]>=MAX)
            break;
        if(a[i] == 2*a[s])
            ++s;
        if (a[i] == 3*a[t])
            ++t;
        if(a[i] == 5*a[r])
            ++r;
    }
    
    cin >> T;
    
    while(T--)
    {
        cin >> n;
        cout << find(n) << endl;
    }
    return 0;
}
