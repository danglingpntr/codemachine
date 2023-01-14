/* Task-> Compose the largest number out of a set of integers.

Input Format-> The first line of the input contains an integer 𝑛. The second line contains integers
𝑎1, 𝑎2, . . . , 𝑎𝑛.

Constraints-> 1 ≤ 𝑛 ≤ 100; 1 ≤ 𝑎𝑖 ≤ 103 for all 1 ≤ 𝑖 ≤ 𝑛.

Output Format-> Output the largest number that can be composed out of 𝑎1, 𝑎2, . . . , 𝑎𝑛. */

#include <bits/stdc++.h>
using namespace std;

void maximise(vector<string> v) 
{
  std::sort(v.begin(), v.end(),
      [](const std::string &lhs, const std::string &rhs) {
        // reverse the order of comparison to sort in descending order,
        // otherwise we'll get the "big" numbers at the end of the vector
        return rhs+lhs < lhs+rhs;
      });

  for (size_t i = 0; i < v.size(); ++i) {
    std::cout << v[i];
  }
}

int main() 
{
    unsigned int n;
    std::cin >> n;
    vector<string> numbers(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> numbers[i] ;
    }

    maximise(numbers);
    
    return 0;
}