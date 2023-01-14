#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {return a[1] < b[1];}
class Solution {
public:  
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto a, auto b) { return (a[1] < b[1]);});
        // for(auto &s:points)
        // {
        //     cout<<"[";
        //     for(auto &c:s)
        //         cout<<c<<",";
        //     cout<<"]";
        // }
        //cout <<endl<<points.size()<<endl;
        int ans = 0, arrow = 0;
        for (int i = 0; i < points.size(); i ++) 
        {
            if (ans == 0 || points[i][0] > arrow) 
            {
                ans ++;
                arrow = points[i][1];
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> matrix = {{10,16},{2,8},{1,6},{7,18}};
    cout<<s.findMinArrowShots(matrix);
    return 0;
}