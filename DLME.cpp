#include<iostream>
#include<vector>
#include<utility>
#include<iterator>
#include<cmath>
using namespace std;

int main()
{
    //Input the two coordinate
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    vector<pair<int,int>>result;
    result.push_back(make_pair(x1,y1));
    
    if(x2-x1==0)
    {
        for(int i=y1+1;i<y2;i++)
           result.push_back(make_pair(x1,i));
    }

    else{
    double m = (y2-y1)/(x2-x1);//slope
    double b = y1 - (m*x1);//intercept

    //storing the coordinate that will be turned on
    for(int i=x1+1;i<x2;i++)
    {
        double temp = round((m*i) + b);
        result.push_back(make_pair(i,temp));
    }
    }
    result.push_back(make_pair(x2,y2));

    //printing the resulting coordinate
   for(int i=0;i<result.size();i++)
   {
       cout<<result[i].first<<"  "<<result[i].second<<endl;
   }
}