/* Given two strings s and t of lengths m and n respectively,return the 
minimum window substring of s such that every character in t (including duplicates) is included in the window. 
If there is no such substring, return the empty string "".

A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t. */
#include <bits/stdc++.h>
using namespace std;

string minWindow(string A, string B)
{
    int f = 0, s = 0;
    vector<int> um(128, 0);   //initialize 128 blocks with 0
    int counter = 0;
    for (char c : B)
    {
        counter += (um[c]++ == 0);
    }
    int ans_i = -1, l = -1;
    while (f < A.size())
    {
        if (counter)
        {
            if (s == A.size())
            {
                break;
            }
            if (--um[A[s]] == 0)
                counter--;
            s++;
            continue;
        }
        if ((l == -1) || (l > (s - f)))
        {
            l = s - f;
            ans_i = f;
        }
        if (um[A[f]]++ == 0)
            counter++;
        f++;
    }
    string ans;
    if (ans_i == -1)
        return ans;
    ans = A.substr(ans_i, l);
    return ans;
}

int main()
{
    string source, target;
    cin >> source >> target;
    cout << minWindow(source, target);
    return 0;
}