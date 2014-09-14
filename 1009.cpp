#include <iostream>
using namespace std;

unsigned long long Ck(int m,int k)
{
    unsigned long long sum = 1;
    int j =1,s = 1;
    for(int i = m-1;i>=0;--i,++j)
    {
        sum *= k-i;
        s *= j;
    }
    return sum/s;
}
unsigned long long power(int a , int b)
{
    unsigned long long sum =1;
    while(b--)
    {
        sum *= a;
    }
    return sum;
}
unsigned long long bitcount(int k)
{
    unsigned long long sum = 0;
    if(k==1)
        return 1;
    for(int i = 1;i<=k-1;++i)
        sum += i*Ck(i,k-1)*power(9,k-1-i);
    sum *= 10;
    for(int i = 1;i<=k-1;++i)
        sum += Ck(i,k-1)*power(9,k-1-i);
    sum += power(9,k-1);
    return sum;
}

unsigned long long dp(int n)
{
    int ten = 1,t = n,bit = 0;
    if(!n)
        return 0;
    while(t)
    {
        ++bit;
        t /= 10;
    }
    if(bit == 1)
        return 1;
    t = bit;
    while(t-->1)
    {
        ten *= 10;
    }
    int s = n/ten - 1;
    if(s>0)
        return (s+1)*bitcount(bit-1)+dp(n%ten)+power(10,bit-1);
    else
        return bitcount(bit-1)+dp(n%ten)+n%ten+1;
}

int main()
{
    int n;
    cin >> n;
    cout << dp(n) << endl;
    return 0;
}