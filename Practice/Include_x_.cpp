#include<stdio.h>
#include<string.h>

int fun (char* in,char* out )
{
	int i,l;
	l = strlen (in);
//	strcat (out,"\x");
	for (i=0;i<l;i=i+2)
	{
		//sprintf(out,"%s","\\x");
		if (i!=0)
		strcat (out,"\\x");
		strncat(out, &in[i],2 );
	}

}

main()
{
	char arr[2000],out[2000]="\\x";
	strcpy(arr,"5F2A0207645F34010182027C008408A000000677010101950500800488009A032006199C01009F02060000000100009F03060000000000009F090200209F100807020103A02002019F1A0207649F1E0839393935353536319F2608B621BCEE1D78FEF79F2701809F3303E0F8C89F34030203009F3501229F360205509F370401DA074D9F410400000003");
	fun (arr,out);
	printf (" =====  %s",out);
}
