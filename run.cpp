#include <iostream>
#include <cstring>
using namespace std;

void findPlindrome(char buff[])
{
	bool flag=true;
	int len= strlen(buff);
	
	for(int i=0;i<len;i++)
	{
        if (buff[i]!=buff[len-i-1])
		{	
			flag=false;
			break;
		}
	}
	if (flag)
		cout<<"Plaindrome";
	else
		cout<<"not plaindrome";
}

int main()
{
    char s[]="heleh";
    findPlindrome(s);
    int len= sizeof(s)/sizeof(char);
    return 0;
}