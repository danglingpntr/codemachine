#include <bits/stdc++.h>
using namespace std;

void replaceUnderSc(string str)
{
    int n = str.size();
    std::string newStr;
    cout<< &str[3];
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            newStr.push_back('_');
            newStr.push_back(str[i]);
        }
        else if (str[i]=='_')
        {
            newStr.push_back(toupper(str[++i]));
        }
        else
        {
            newStr.push_back(str[i]);
        }
    }
    cout<<"newStr:"<<newStr;
}

int main()
{
    string str;
    cout<<"Enter string:";
    cin>>str;
    replaceUnderSc(str);
    cout<<str;
    return 0;
}