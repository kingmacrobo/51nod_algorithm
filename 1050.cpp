/*************************************************************************
	> File Name: 1050.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue Sep  9 09:59:13 2014
 ************************************************************************/

#include<iostream>
using namespace std;
int a[50001];
int main()
{
    int N;
    long long max = 0,min = 0,sum = 0;;
    long long current = 0;
    int count = 0;
    cin >> N;
    for(int i = 0; i < N ; ++i)
    {
        cin >> a[i];
        sum += a[i];
        if(a[i]+current < 0)
            current = 0;
        else
            max = max>(current += a[i])?max:current;
    }
    
    for(int i = 0; i < N ; ++i)
    {
        if(a[i]+current > 0)
            current = 0;
        else
            min = min<(current += a[i])?min:current;
    }

    min = sum - min;
    max = max > min ? max:min;
    cout << max;
    return 0;
}

