/* Task-> The goal of this code problem is to implement an algorithm for the fractional knapsack problem.

Input Format-> The first line of the input contains the number 𝑛 of items and the capacity 𝑊 of a knapsack.
The next 𝑛 lines define the values and weights of the items. The 𝑖-th line contains integers 𝑣𝑖 and 𝑤𝑖—the
value and the weight of 𝑖-th item, respectively.

Constraints-> 1 ≤ 𝑛 ≤ 103, 0 ≤ 𝑊 ≤ 2 · 106; 0 ≤ 𝑣𝑖 ≤ 2 · 106, 0 < 𝑤𝑖 ≤ 2 · 106 for all 1 ≤ 𝑖 ≤ 𝑛. All the
numbers are integers.

Output Format-> Output the maximal value of fractions of items that fit into the knapsack. The absolute
value of the difference between the answer of your program and the optimal value should be at most
10−3. To ensure this, output your answer with at least four digits after the decimal point (otherwise
your answer, while being computed correctly, can turn out to be wrong because of rounding issues). */

#include <bits/stdc++.h> 
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) 
{
  double value = 0.0;
  int minWei;
  int n = weights.size();
  map<double, vector<double>, greater <double>> origWeight;

  for (int i=0; i < n; i++)
  {
    origWeight[ ((double) values[i]/weights[i])].push_back(i);
  }

  for (auto &pair: origWeight)
  {
    auto sortedEle = pair.first;
    for (int d : pair.second)
    {
      if (capacity > weights[d])
        minWei = weights[d];
      else
        minWei = capacity;

      value = value + (minWei * sortedEle);
      capacity -= minWei;

      if (capacity == 0)
        break;
    }
  }

  return value;
}

int main() 
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) 
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
