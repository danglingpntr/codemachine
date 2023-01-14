/* Given two strings text1 and text2, return the length of their longest common subsequence. 
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) 
deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3. 

Input: s1=shubham s2=hut
output = 2                                                 */
#include <bits/stdc++.h>
using namespace std;

int longestss(string& s1,string& s2,int m,int n)
{
   int t[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
        {
          if(i==0||j==0) t[i][j]=0;
            else if(s1[i-1]==s2[j-1]) 
                t[i][j]=1+t[i-1][j-1];
            else {
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
      }        
    }
    return t[m][n];
}

int longestCommonSubsequence(string s1, string s2) 
{
    int m=s1.size();
    int n=s2.size();
    return longestss(s1,s2,m,n);
}

int main()
{
    string input, target;
    cin >> input >> target;
    cout << longestCommonSubsequence(input, target);
    return 0;
}