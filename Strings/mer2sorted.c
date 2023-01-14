#include <stdio.h>
#include <string.h>

void merge(char a[], char b[], char sorted[]);

int main()
{
    char a[100], b[100],  sorted[200];
    int m=0, n=0, c=0;

    printf("Input number of elements in first array\n");
    scanf("%s", a);


    printf("Input number of elements in second array\n");
    scanf("%s", b);

    merge(a, b,sorted);

    printf("Sorted array:\n");


    printf("%s", sorted);

    return 0;
}

void merge(char a[], char b[], char sorted[])
{
    int i, j, k;
    i= j = k = 0;
    int m=strlen(a);
    int n=strlen(b);

    while ( i < m + n)
    {
        if (j < m && k < n)
        {

            if (a[j] < b[k])
            {
                sorted[i] = a[j];
                j++;
            }
            else
            {
                sorted[i] = b[k];
                k++;
            }
            i++;
        }

        else if (j == m)
        {
            while( i < m + n)
            {
                sorted[i] = b[k];
                k++;
                i++;
            }
        }

        else
        {
            while ( i < m + n)
            {
                sorted[i] = a[j];
                j++;
                i++;
            }
        }
    }
    sorted[i++]=0;
}
