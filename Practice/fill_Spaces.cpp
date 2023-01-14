#include <bits/stdc++.h>
using namespace std;

void myStr(char inp[],int len)
{
	char tmp[len*2]={0};
	int i=0;
	int j=0;
	while(inp[i]!='\0')
	{
		if (inp[i]==' '){
			tmp[j]='%'; 
			tmp[++j]='2';
			tmp[++j]='0'; 
		}
		else
			tmp[j]=inp[i];
		i++;
		j++; 
	}
	tmp[j]='\0';
	cout << tmp<<endl;
	inp[3]='R';
}

int main()
{
	char inp[]="I am happy";
	myStr(inp,6);
	char *p;
	p=inp;
	cout<<p;
	return 0;
}