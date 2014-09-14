/*************************************************************************
	> File Name   : 1138.cpp
	> Author      : Wang,Hongbo
	> Mail        : wanghongbo@ict.ac.cn
	> Created Time: Wed 27 Aug 2014 09:16:56 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    unsigned int N;
    unsigned int m,k;
    vector<unsigned int> result;
    cin>>N;
    for(m=2;m<=(2*sqrt(2*N)-1)/2+1;++m)
    {
        if(m%2)
        {
            if(N%m==0)
            {
                k = N/m-m/2;
                if(k>=1&&k<=N/2)
                {
                    if(result.size()==0)
                        result.push_back(k);
                    else
                        for(vector<unsigned int >:: iterator it = result.begin();it!=result.end();++it)
                        {
                            if(k>*it)
                            {
                                if(it+1 == result.end())
                                    result.push_back(k);
                            }
							else
							{
								result.insert(it,k);
								break;
							}
                        }
                }
            }
        }
        else
        {
            if(N%m == m/2)
            {
                
                k = N/m+1-m/2;
                if(k>=1&&k<=N/2)
                {
                    if(result.size()==0)
                        result.push_back(k);
                    else
                        for(vector<unsigned int >:: iterator it = result.begin();it!=result.end();++it)
                        {
                           if(k>*it)
                            {
                                if(it+1 == result.end())
                                    result.push_back(k);
                            }
							else
							{
								result.insert(it,k);
								break;
						   }
                        }
                }
            }

        }
    }
	if(result.size()==0)
		cout<<"No Solution";
    for(vector<unsigned int>::iterator it = result.begin();it!=result.end();++it)
		cout<<*it<<endl;

    return 0;    
}