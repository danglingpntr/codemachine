/* Task-> The goal of this code problem is to implement an algorithm for the fractional knapsack problem.

Input Format-> The first line of the input contains the number π of items and the capacity π of a knapsack.
The next π lines define the values and weights of the items. The π-th line contains integers π£π and π€πβthe
value and the weight of π-th item, respectively.

Constraints-> 1 β€ π β€ 103, 0 β€ π β€ 2 Β· 106; 0 β€ π£π β€ 2 Β· 106, 0 < π€π β€ 2 Β· 106 for all 1 β€ π β€ π. All the
numbers are integers.

Output Format-> Output the maximal value of fractions of items that fit into the knapsack. The absolute
value of the difference between the answer of your program and the optimal value should be at most
10β3. To ensure this, output your answer with at least four digits after the decimal point (otherwise
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
