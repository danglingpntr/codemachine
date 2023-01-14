/* Task-> The goal in this code problem is to check whether an input sequence contains a majority element.

Input Format-> The first line contains an integer 𝑛, the next one contains a sequence of 𝑛 non-negative
integers 𝑎0, 𝑎1, . . . , 𝑎𝑛−1.

Constraints-> 1 ≤ 𝑛 ≤ 105; 0 ≤ 𝑎𝑖 ≤ 109 for all 0 ≤ 𝑖 < 𝑛.

Output Format-> Output 1 if the sequence contains an element that appears strictly more than 𝑛/2 times,
and 0 otherwise. */

#include <bits/stdc++.h>
using namespace std;
 
/* Function to find the candidate for Majority */
int findCandidate(vector<int> a, int size)
{
    int maj_index = 0, count = 1;
    for (int i = 1; i < size; i++) 
    {
        if (a[maj_index] == a[i])
            count++;
        else
            count--;
        if (count == 0) 
        {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}
 
/* Function to check if the candidate
   occurs more than n/2 times */
bool isMajority(vector<int> a, int size, int cand)
{
    int count = 0;
    for (int i = 0; i < size; i++)
        if (a[i] == cand)
            count++;
 
    if (count > size / 2)
        return 1;
    else
        return 0;
}
 
/* Driver code */
int main()
{
    int a;
    cin >>a;
    vector<int> arr(a);
    for (int x = 0; x < a; x++)
    {
        cin >> arr[x];
    }
    int size = arr.size();
    // Function calling
    /* Find the candidate for Majority*/
    int cand = findCandidate(arr, size);
    /* Print the candidate if it is Majority*/
    cout<< isMajority(arr, size, cand);
 
    return 0;
}