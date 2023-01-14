// Input:- The first line contains an integer 𝑛, the second line contains 𝑛 integers 𝑎1, . . . , 𝑎𝑛
// separated by spaces, the third line contains an integer 𝑚.

// Output:- Output max{𝑎𝑖, . . . , 𝑎𝑖+𝑚−1} for every 1 ≤ 𝑖 ≤ 𝑛 − 𝑚 + 1.

// Sample Input:
// 8
// 2 7 3 1 5 2 6 2
// 4
// Output:
// 7 7 5 6 6

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    if (nums.size() == 1)
        return nums;

    deque<int> q;
    for (int i = 0; i < k; i++)
    {
        while (!q.empty() && nums[q.back()] <= nums[i])
        {
             cout<< q.back() << " " << i<<" ";
            q.pop_back();
        }
        q.push_back(i);
    }

    cout << "que elemnts:";
    for (auto a : q)
        cout << a << " ";
    cout<<endl;

    vector<int> ans;
    for (int i = k; i < nums.size(); i++)
    {
        ans.push_back(nums[q.front()]);
        while (!q.empty() && q.front() <= (i - k))
        {
            cout << "front:" << q.front() << " diff:" << (i - k) << " " << endl;
            q.pop_front();
        }
        while (!q.empty() && nums[q.back()] <= nums[i])
        {
            cout << "back:" << q.back() << " num_back:" << nums[q.back()] << " nums:" << nums[i] << " " << endl;
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(nums[q.front()]);
    return ans;
}

int main()
{
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    vector<int> V = maxSlidingWindow(A, w);
    for (auto a : V)
        cout << a << " ";
    //max_sliding_window_naive(A, w);

    return 0;
}
