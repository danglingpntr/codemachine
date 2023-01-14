/*
This problem is about implementing an algorithm for the knapsack without repetitions problem.
Task.
----
In this problem, you are given a set of bars of gold and your goal is to take as much gold as possible
into your bag. There is just one copy of each bar and for each bar you can either take it or not (hence
you cannot take a fraction of a bar).
*/
#include <bits/stdc++.h>
using namespace std;

int optimal_weight(int W, const vector<int> &w) 
{
  const int w_size = w.size();
  vector<vector<int>> weights(w_size+1);
  for (int i = 0; i <= w_size; i++)
  {
      vector<int> v(W+1);
      weights[i]=v;
  }

  for (int i = 0; i <= w_size; i++) {
    for (int j = 0; j <= W; j++) {      
        if (i==0 || j==0) 
          weights[i][j] = 0;
        else if (w[i - 1] <= j) 
          weights[i][j] = std::max(w[i - 1] + weights[i - 1][j - w[i - 1]],  weights[i - 1][j]);
        else
          weights[i][j] = weights[i - 1][j];
    }
  }

  int result = weights[w_size][W];
  return result;
}

int main() 
{
	int max_wgt = 0;
	std::cin >> max_wgt;

	int num_bars = 0;
	std::cin >> num_bars;

	vector<int> wgt(num_bars);
    for (int i=0;i<num_bars;i++)
        cin>>wgt[i];
	
	std::cout << optimal_weight(max_wgt, wgt) << std::endl;
}