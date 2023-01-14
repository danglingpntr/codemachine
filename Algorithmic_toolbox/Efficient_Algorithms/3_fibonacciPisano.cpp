/* Task: Given two integers 𝑛 and 𝑚, output 𝐹𝑛 mod 𝑚 (that is, the remainder of 𝐹𝑛 when divided by 𝑚).
Input Format: The input consists of two integers 𝑛 and 𝑚 given on the same line (separated by a space).
Constraints: 1 ≤ 𝑛 ≤ 1014, 2 ≤ 𝑚 ≤ 103.
Output Format: Output 𝐹𝑛 mod 𝑚. 
𝐹𝑛= last number of fibonacci series of n number*/

#include <iostream>
using namespace std;

long pisano(long m)
{
	long prev = 0;
	long curr = 1;
	
	for(int i = 0; i < m * m; i++)
	{
		long temp = 0;
		temp = curr;
		curr = (prev + curr) % m;
		prev = temp;
		cout<<curr<<" "<<temp<<endl;
		
		if (prev == 0 && curr == 1){
			cout<<i+1<<endl;
			return i+1;  }
	}
	return m;
}

long fibonacciModulo(long n, long m)
{
	// Getting the period 
	long pisanoPeriod = pisano(m);
	n = n % pisanoPeriod;
	
	long prev = 0;
	long curr = 1;
	
	if (n == 0) 
		return 0;
	else if (n == 1)
		return 1;
	
	for(int i = 0; i < n - 1; i++)
	{
		long temp = 0;
		temp = curr;
		curr = (prev + curr) % m;
		prev = temp;
	}
	return curr % m;
}
 
int main() 
{ 
    long n,m;
    cin >> n>>m;
	cout<<fibonacciModulo(n, m);
}