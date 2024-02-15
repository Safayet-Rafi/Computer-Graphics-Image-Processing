//Bresenham's Line Algorithm for m < 1
#include <iostream>
#include <utility>
#include<vector>
#include <cmath>
using namespace std;

int main()
{
    //taking input of the coordinate
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    //store the coordinate which will be turned on
    vector<pair<int,int>>result;
    result.push_back(make_pair(x1,y1));

    int dx = x2 - x1;
    int dy = y2 - y1;
    int d = 2 * dy - dx;//initial value of decision parameter

    while(x1<x2)
    {
        if(d<0)
        {
            d += 2 * dy;
            result.push_back(make_pair(++x1,y1));
        }
        else
        {
            d += (2 * dy - 2 * dx);
            result.push_back(make_pair(++x1,++y1));
        }
    }

    for(int i=0;i<result.size();i++)
    {
        cout<<result[i].first<<" "<<result[i].second<<endl;
    }
}