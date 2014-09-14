#include <iostream>
using namespace std;


unsigned long long Ck(int m,int k)
{
    unsigned long long sum = 1;
    unsigned long long j =1,s = 1;
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

unsigned long long bitcount0(int k)
{
    if(k==1)
        return 1;
    return 9*bitcount(k-1)+bitcount0(k-1);
}

unsigned long long dp(unsigned long long n,int k,int kind)
{
    unsigned long long ten = 1,t = n;
    int bit = 0;
    if(!n)
    {
        if(k==0)
            return 1;
        return 0;
    }
    
    while(t)
    {
        ++bit;
        t /= 10;
    }
    if(bit == 1)
    {
        if(n>=k)
            return 1;
        return 0;
    }
    t = bit;
    while(t-->1)
    {
        ten *= 10;
    }
    unsigned long long  s = n/ten-1;
    n = n%ten;
    if(k==0)
    {
        unsigned long long m = 0;
        unsigned long long l = ten;
        l /= 10;
        for(int i = bit -1 ;i>1;--i)
        {
            if(n/l==0)
            {
                ++m;
                l /= 10;
            }
            else
                break;
        }
        if(kind == 0)
            return s*bitcount(bit-1)+dp(n,k,1)+bitcount0(bit-1)+m*(n+1);
        else
            return (s+1)*bitcount(bit-1)+dp(n,k,1)+power(10,bit-1)+m*(n+1);
    }
    if(s>k-1)
        return (s+1)*bitcount(bit-1)+dp(n,k,0)+power(10,bit-1);
    else if(s == k-1)
        return (s+1)*bitcount(bit-1)+dp(n,k,0)+n+1;
    else
        return (s+1)*bitcount(bit-1)+dp(n,k,0);
    
}

int main()
{
    unsigned long long a ,b;
    cin >> a >> b;
    for(int i = 0;i<=9;++i)
        cout << dp(b,i,0)-dp(a-1,i,0) << endl;
    return 0;
}