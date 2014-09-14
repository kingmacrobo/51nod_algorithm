/*************************************************************************
	> File Name   : 1133.cpp
	> Author      : Wang,Hongbo
	> Mail        : wanghongbo@ict.ac.cn
	> Created Time: Wed 27 Aug 2014 02:15:26 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
struct Point
{
    int s;
    int e;
    Point(int s,int e):s(s),e(e){}; 
};

int N;
vector<Point> points;
int record[10000];

/*
 * Dynamic Programming Method
 * recursion formula:
 * f(k) = max{f(k+1),f(k+m)+1}
 */
int dp(int num)
{
    int a,b,i;
    if(num==N-1)
	{
		record[num] = 1;
		return 1;
	}
	if(!record[num+1])
		record[num+1] = dp(num+1);
	a = record[num+1];
    i = num;
    while(++i<N)
    {
		if(points[i].s>=points[num].e)
			break;
    }
    if(i==N)
        b = 1;
    else
	{
		if(!record[i])
			record[i] = dp(i); 		
		b = record[i]+1;
	}
    
    return a>b?a:b;
}


int main()
{
    int s,e;

    cin>>N;
    for(int i = 0; i < N ; ++i)
    {
        cin>>s>>e;
        Point point(s,e);
        if(points.size()==0)
            points.push_back(point);
        else
            for(vector<Point>::iterator it = points.begin();it != points.end(); ++it)
            {
                if(it == points.end()-1&&point.s>(*it).s)
				{
                    points.push_back(point);
					break;
				}
                else if(point.s<=(*it).s)
                {
                    points.insert(it,point);
                    break;
                }
            }
    }
    cout<<dp(0)<<endl;
    return 0;
}
