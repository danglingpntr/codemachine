#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool Matchc(char open, char close)
{
    if (open == '[' && close == ']')
        return true;
    if (open == '{' && close == '}')
        return true;
    if (open == '(' && close == ')')
        return true;
    return false;
}

int isValid(string text)
{
    std::stack<char> brkt_stk;
    int position = 0,a;
    for (position = 0 ; position < text.length(); ++position)
    {
        if (brkt_stk.empty())
		    	a=position;
    
        char next = text[position];

        if (next == '(' || next == '[' || next == '{')
        {
            // Process opening bracket
            brkt_stk.push(next);
        }

        if (next == ')' || next == ']' || next == '}')
        {
            // Process closing bracket
            if (brkt_stk.empty())
            {
                brkt_stk.push(next);
                break;
            }
            char openBracket = brkt_stk.top();
            if (Matchc(openBracket,next))
            {
                brkt_stk.pop();
            }
            else
            {
                brkt_stk.push(next);
                break;
            }
        }
    }
    
    if (brkt_stk.empty())
        return 0;
    else
	{
		if((position>=text.size())&&!brkt_stk.empty())
			return a+1;
		else
			return position+1;
	}
}

int main()
{
    string s;
    cin>>s;
    int res=isValid(s);
    if(res)
        cout << res << endl;
    else
        cout << "Success";

    return 0;
}