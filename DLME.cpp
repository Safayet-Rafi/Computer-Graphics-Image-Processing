#include<iostream>
#include<map>
#include<iterator>
#include<cmath>
using namespace std;

int main()
{
    //Input the two coordinate
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    
    if(x2-x1==0)
    {
        cout<<"It's a vertical line"<<endl;
        return 0;
    }
    double m = (y2-y1)/(x2-x1);//slope
    double b = y1 - (m*x1);//intercept

    map<int,int>result;
    result.insert({x1,y1});
    result.insert({x2,y2});
    //storing the coordinate that will be turned on
    for(int i=x1+1;i<x2;i++)
    {
        double temp = round((m*i) + b);
        result.insert({ i, temp }); 
    }
    //printing the resulting coordinate
    for (auto itr = result.begin(); itr != result.end(); ++itr) { 
        cout << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
}