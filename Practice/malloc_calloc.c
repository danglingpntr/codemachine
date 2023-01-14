#include<stdio.h> 
#include<stdlib.h>
int main()
{
int count=2;
int* ptr = (int*)malloc(sizeof(int));
printf("ptr=%p \n",ptr);
int* tmp = (int*)realloc(ptr, 2);
printf("tmp=%p \n",tmp);
printf("tmp=%d  ptr= %d\n",tmp[0],ptr[0]);
*tmp=99;
printf("tmp=%d  ptr= %d\n",*tmp,*ptr);
return 0;
}