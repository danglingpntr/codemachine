/* Task -> The goal in this problem is to find the minimum number of coins needed to change the input value
(an integer) into coins with denominations 1, 5, and 10.

Input Format -> The input consists of a single integer 𝑚.
Constraints. 1 ≤ 𝑚 ≤ 103.

Output Format -> Output the minimum number of coins with denominations 1, 5, 10 that changes 𝑚. */


#include <iostream>

int get_change(int m) {
  int n=0;
  int c10 = 10, c5=5, c1=1;
  while (m!=0)
  {
    if (m>=c10)
        m-=10;
    else if (m>=c5)
        m-=5;
    else if (m>=c1)
        m-=1;
    
    n++;
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
