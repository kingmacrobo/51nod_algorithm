/*************************************************************************
	> File Name: 1049.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue Sep  9 11:00:30 2014
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    int N;
    int a;
    long long max = 0;
    long long current = 0;
    cin >> N;
    for(int i = 0; i < N ; ++i)
    {
        cin >> a;
        if(a+current < 0)
            current = 0;
        else
            max = max>(current += a)?max:current;
    }

    cout << max;
    return 0;
}
