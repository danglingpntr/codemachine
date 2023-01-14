#include <bits/stdc++.h>
using namespace std;
 
// Merge two sorted subarrays `arr[low … mid]` and `arr[mid+1 … high]`
void Merge(int arr[], int aux[], int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;
 
    while (i <= mid && j <= high)
    {
        if (arr[i] >= arr[j]) {
            aux[k++] = arr[i++];
        }
        else {
            aux[k++] = arr[j++];
        }
    }
 
    // copy remaining elements
    while (i <= mid) {
        aux[k++] = arr[i++];
    }
 
    /* no need to copy the second half (since the remaining items 
    are already in their correct position in the temporary array) */
    // copy back to the original array to reflect sorted order
    for (int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
 
}
 
// Sort array `arr[low…high]` using auxiliary array `aux`
void MergeSort(int arr[], int aux[], int low, int high)
{
    // Base case
    if (high == low)
        return ;

    int mid = (low + ((high - low) >> 1));

    MergeSort(arr, aux, low, mid);
    MergeSort(arr, aux, mid + 1, high);

    Merge(arr, aux, low, mid, high);
}
 
int main()
{
    int arr[] = { 1, 9, 6, 4, 5 };
    int N = sizeof(arr)/sizeof(arr[0]);
 
    int aux[N];
    for (int i = 0; i < N; i++) {
        aux[i] = arr[i];
    }
    MergeSort(arr, aux, 0, N - 1);
    for (int i = 0; i < N; i++) {
        cout<<arr[i]<<" ";
    }
 
    return 0;
}