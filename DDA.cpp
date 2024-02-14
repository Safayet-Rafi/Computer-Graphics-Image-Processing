#include <iostream>
#include <map>
#include <utility>
#include <cmath>
using namespace std;

int main()
{
    // Input the two coordinate
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double dx = x2 - x1;
    double dy = y2 - y1;
    vector<pair<int, int>> result;
    result.push_back(make_pair(x1, y1));

    // when m==0
    if (dx == 0)
    {
        for (int i = y1 + 1; i < y2; i++)
            result.push_back(make_pair(x1, i));
    }
    else
    {
        double m = dy / dx;
        if (m < 1)
        {
            for (int i = x1 + 1; i < x2; i++)
            {
                y1 +=  m;
                result.push_back(make_pair(++x1, round(y1)));
            }
        }
        else if (m > 1)
        {
            for (int i = y1 + 1; i < y2; i++)
            {
                x1 +=  (1/m);
                result.push_back(make_pair(round(x1), ++y1));
            }
        }
        else
        {
            for (int i = x1 + 1; i < x2; i++)
            {
                result.push_back(make_pair(++x1,++y1));
            }
        }
    }
    result.push_back(make_pair(x2,y2));
    // printing the resulting coordinate
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i].first<<"  "<<result[i].second<<endl;
    }
}