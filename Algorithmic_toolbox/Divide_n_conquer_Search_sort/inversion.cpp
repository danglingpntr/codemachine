#include <bits/stdc++.h>
using namespace std;
 
// Merge two sorted subarrays `arr[low … mid]` and `arr[mid+1 … high]`
int Merge(vector<int> &arr, vector<int> aux, int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;
    int inversionCount = 0;
    
    // while there are elements in the left and right runs
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        }
        else {
            aux[k++] = arr[j++];
            inversionCount += (mid - i + 1);    // NOTE
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
    cout<<"merge inversion:"<<inversionCount<<endl;
    return inversionCount;
}
 
// Sort array `arr[low…high]` using auxiliary array `aux`
int MergeSort(vector<int> &arr, vector<int> aux, int low, int high)
{
    // Base case
    if (high == low) {        // if run size == 1
        return 0;
    }
 
    // find midpoint
    int mid = (low + ((high - low) >> 1));
    int inversionCount = 0;
    cout<<"inversionCount:"<< inversionCount<<endl;
    // recursively split runs into two halves until run size == 1,
    // then merges them and return up the call chain
 
    // split/merge left half
    inversionCount += MergeSort(arr, aux, low, mid);
    cout<<"1STinversionCount:"<< inversionCount<<endl;
    // split/merge right half
    inversionCount += MergeSort(arr, aux, mid + 1, high);
    cout<<"2NDinversionCount:"<< inversionCount<<endl;
    // merge the two half runs
    inversionCount += Merge(arr, aux, low, mid, high);
 
    return inversionCount;
}
 
int main()
{
    int a;
    cin >>a;
    vector<int> arr(a);
    vector<int> aux(a);
    for (int i = 0; i < a; i++)
    {
        cin >> arr[i];
        aux[i] = arr[i];
    }
    // get the inversion count by performing merge sort on arr
    cout<< MergeSort(arr, aux, 0, a - 1);
    for(auto a: arr)
        cout<<a;
 
    return 0;
}