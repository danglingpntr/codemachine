/* Task-> Find the maximum value of an arithmetic expression by specifying the order of applying its arithmetic
operations using additional parentheses.

Input Format-> The only line of the input contains a string 𝑠 of length 2𝑛 + 1 for some 𝑛, with symbols
𝑠0, 𝑠1, . . . , 𝑠2𝑛. Each symbol at an even position of 𝑠 is a digit (that is, an integer from 0 to 9) while
each symbol at an odd position is one of three operations from {+,-,*}.

Constraints-> 0 ≤ 𝑛 ≤ 14 (hence the string contains at most 29 symbols).

Output Format-> Output the maximum possible value */
#include <bits/stdc++.h>
using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  int length = exp.size();
  int numOfnum = (length + 1) / 2;
  long long minArray[numOfnum][numOfnum];
  long long maxArray[numOfnum][numOfnum];
  memset(minArray,0,sizeof(minArray)); // initialize to 0
  memset(maxArray,0,sizeof(maxArray));
  for (int i = 0; i < numOfnum; i++)
  {
	  //The values on the main diagonal is just the number themselves
	  minArray[i][i] = std::stoll(exp.substr(2*i,1));
	  maxArray[i][i] = std::stoll(exp.substr(2*i,1));
  }

  for (int s = 0; s < numOfnum - 1; s++)
  {
	  for (int i = 0; i < numOfnum - s - 1; i++)
	  {
		  int j = i + s + 1;
		  long long minVal = LLONG_MAX;
	      long long maxVal = LLONG_MIN;
	      // find the minimum and maximum values for the expression
	      // between the ith number and jth number
		  for (int k = i; k < j; k++ )
	      {
			  long long a = eval(minArray[i][k],minArray[k + 1][j],exp[2 * k + 1]);
			  long long b = eval(minArray[i][k],maxArray[k + 1][j],exp[2 * k + 1]);
			  long long c = eval(maxArray[i][k],minArray[k + 1][j],exp[2 * k + 1]);
			  long long d = eval(maxArray[i][k],maxArray[k + 1][j],exp[2 * k + 1]);
			  minVal = min(minVal,min(a,min(b,min(c,d))));
			  maxVal = max(maxVal,max(a,max(b,max(c,d))));
	      }
		  minArray[i][j] = minVal;
		  maxArray[i][j] = maxVal;
	  }
  }

  return maxArray[0][numOfnum - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}