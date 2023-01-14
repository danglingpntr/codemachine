#include <iostream>
using namespace std;
 
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i+1;
    return -1;
}
 
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 50;
    int n = sizeof(arr) / sizeof(arr[0]);
   
    int result = search(arr, n, x);
    (result == -1) ? cout << "-1" : cout << result;
    return 0;
}