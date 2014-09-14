/*************************************************************************
	> File Name   : 1267c.cpp
	> Author      : Wang,Hongbo 
	> Mail        : wanghongbo@ict.ac.cn
	> Created Time: Wed Sep 10 09:35:54 2014
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int a[1001];
struct point
{
    int sum;
    int a1;
    int a2;
    point(int s,int t)
    {
        a1 = s;
        a2 = t;
        sum = a[s]+a[t];
    }
};
vector<point> pa;
vector<point> pb;
vector<point> pc;
int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N ; ++i)
        cin >> a[i];
    for(int i = 0; i< N;++i)
    {
        for(int j = i+1; j < N;++j)
        {
            point p(i,j);
            if(p.sum<0)
                 pa.push_back(p);
            else if(p.sum>0)
                 pb.push_back(p);
            else
            {
                if(pc.size()==0)
                    pc.push_back(p);
                else
                {
                    for(vector<point>:: iterator it = pc.begin();it != pc.end();++it)
                    {
                        if(i!=it->a1&&i!=it->a2&&j!=it->a1&&j!=it->a2)
                        {
                            cout << "Yes";
                            return 0;
                        }   

                    }
                    pc.push_back(p);
                }
            }
        }
    }

    vector<point>:: iterator ait,bit;
    for(ait = pa.begin();ait!=pa.end();++ait)
        for(bit = pb.begin();bit!=pb.end();++bit)
        {
            if(ait->sum+bit->sum==0&&ait->a1!=bit->a1&&ait->a1!=bit->a2&&ait->a2!=bit->a1&&ait->a2!=bit->a2)
            {
                cout << "Yes";
                return 0;
            }
        }
    cout << "No";
    return 0;
}
