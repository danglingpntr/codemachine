
#include <bits/stdc++.h>
using namespace std;

int subs(char *str, long int k)
{
    int cnt,res=0,i=0,j=0,bal;

	while(1)
    {

            if(!(str[j]=='a'||str[j]=='e'||str[j]=='i'||str[j]=='o'||str[j]=='u'))
                cnt++;

            j++;
            if(cnt==k)
            break;

            if(str[j]=='\0')
            	return -1;	

  	}

	res=--j;
	bal=0;
	i=0;

	while(1)
	{
		i++;
		j++;
		if(str[j]=='\0')
			break;

		if(str[i-1]=='a'||str[i-1]=='e'||str[i-1]=='i'||str[i-1]=='o'||str[i-1]=='u')
		{
			if(!(str[j]=='a'||str[j]=='e'||str[j]=='i'||str[j]=='o'||str[j]=='u'))
				bal++;

		}
		else
		{
			if(str[j]=='a'||str[j]=='e'||str[j]=='i'||str[j]=='o'||str[j]=='u')
			{
				if(bal==0)
				{
					while(1)
					{

						if(str[j]=='a'||str[j]=='e'||str[j]=='i'||str[j]=='o'||str[j]=='u')
						{
							j++;
							res++;
						}
						else
							break;
					}
					if(str[j]=='\0')
					break;


				}
				else
				{
					bal--;
				}

			}

		}

	}
	return res+1;
}
