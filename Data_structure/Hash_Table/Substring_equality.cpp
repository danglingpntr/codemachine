/* Input:  (1ststart_index, 2ndstart_index, length)
trololo
4
0 0 7
2 4 3
3 5 1
1 3 2
Output:
Yes
Yes
Yes
No
0 0 7 → trololo = trololo
2 4 3 → trololo = trololo
3 5 1 → trololo = trololo
1 3 2 → trololo ̸= trololo */


#include <iostream>
using namespace std;

class Solver 
{
	string s;
public:	
	Solver(string s) : s(s) {}
	bool ask(int a, int b, int l) {
		return s.substr(a, l) == s.substr(b, l);
	}
};

int main() 
{
	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) 
	{
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}