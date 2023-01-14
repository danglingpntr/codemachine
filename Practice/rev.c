#include<stdio.h>
#include<string.h>
void vdStrRev(char* mystrg,char* sztemp);

int main(void)
{
    char mystrg[60];
    char sztemp[60];
    unsigned long num;
    int leng, g;

	memset(mystrg,0x00,sizeof(mystrg)); 
	memset(sztemp,0x00,sizeof(sztemp));
    printf("Program in C for reversing a given string \n ");
    printf("Please insert the string you want to reverse: ");

    strncpy(mystrg,"2345672",8 );
	vdStrRev(mystrg,sztemp);
	num=atol(sztemp);
    printf("Strings: %s %s %lu",mystrg,sztemp,num);
    
    return 0;
}
void vdStrRev(char* mystrg,char* sztemp)
{
    int leng, g;
    
    leng = strlen(mystrg);

    for(g = leng - 1; g >= 0; g--)
    {
        strncat(sztemp,&mystrg[g],1);
    }
    return ;
}
