#include <bits/stdc++.h>
using namespace std;

 int minPoints(vector<double> pts)
{
    vector<vector<double>> grpPts;
    int n=pts.size();
    int j=0, i=0;
    while (i < (n-1))
    {
        vector<double> row;
        grpPts.push_back(row);
        while(pts[i+1] - pts[i] <= 1 && i<(n-1))
        {
            grpPts[j].push_back(pts[i]);
            grpPts[j].push_back(pts[i+1]);
            i++;
        }
        j++;  i++;
    }
    
    return grpPts.size();
    
} 

int main() 
{
    unsigned int n;
    std::cin >> n;
    vector<double> numbers(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> numbers[i] ;
    }

    cout<<minPoints(numbers);
    
    return 0;
}