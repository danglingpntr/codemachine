// Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <bits/stdc++.h>
using namespace std;
int subs(char *str, long int k);
string wordReverse(string str);
int wordReverse1();

 int main(int argc, char *a[])
{
	string s="Hi hello";
	//substing_program();
	cout<<wordReverse(s);
	wordReverse1();
	return 0;
} 


void substing_program()
{
	char str[100001];
	long int k;
	int cnt;
	cout<<"enter straing:";
	cin >> str;
	cout<<"enter K(no of consonants):";
	cin >> k;
	cnt = subs(str, k);
	cout << cnt;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
