#include <bits/stdc++.h>
using namespace std;

string wordReverse(string str)
{
	int i = str.length() - 1;
	int start, end = i + 1;
	string result = "";

	while (i >= 0)
	{
		if (str[i] == ' ')
		{
			start = i + 1;
			while (start != end)
				result += str[start++];

			result += ' ';
			end = i;
		}
		i--;
	}
	start = 0;
	while (start != end)
		result += str[start++];

	return result;
}


int wordReverse1() {

	char str[100]="", text[100]="";
	int i = 0, j = 0;
	cout<<"Enter Text:";
	cin.get(str, 100);

	//Character reversing starts    
	while (str[i] != '\0')
		i++;

	while (i > 0) 
	{
		text[j] = str[--i];
		++j;
	}
	text[j] = '\0';         //Character reversing ends
	
	printf("Reversed Text:");
	for (i = 0; text[i] != '\0'; i++) 
	{
		if (text[i + 1] == ' ' || text[i + 1] == '\0')
			for (j = i; j >= 0 && text[j] != ' '; j--)
				cout << text[j];

			cout<<" ";
		}
	}
	return 0;
}

int main()
{
	wordReverse1();
	cout<<'\n'<<wordReverse("i am happy");
	return 0;
}