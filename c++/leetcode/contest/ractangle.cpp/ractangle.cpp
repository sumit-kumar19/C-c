
#include <bits/stdc++.h>
using namespace std;

int minRectangles(vector<vector<int>> &points, int w)
{
    sort(points.begin(), points.end());
    int last_x = INT_MIN;
    int rectangles = 0;

    for (int i = 0; i < points.size(); ++i)
    {
        int x = point[i][0];
        if (x > last_x + w)
        {

            last_x = x;
            rectangles++;
        }
        cout << "Value of last_x in iteration with point [" << point[0] << ", " << point[1] << "]: " << last_x << endl;
    }

    return rectangles;
}