#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (vector<int> &arr, int low, int high)
{
    srand(time(0));                              // Use current time as seed for random generator
    int k = low + (rand() % (high-low + 1));     //1. To generate a random pivot
    swap(&arr[high],&arr[k]);                    //2. swap with element of higher index

    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }

    swap(&arr[i + 1], &arr[high]);

    /* cout<<"After Partition:";
    for (int a=0 ; a< arr.size() ;a++)
        cout <<" "<<arr[a] ;
    cout<<"\n"; */
    return (i + 1);
}
 
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
        //cout << "pi:" << pi << " low:" << low << " high: "<< high<<endl;
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        //cout <<"1recur->" << " low:" << low << " high: "<< high<<endl;
        quickSort(arr, pi + 1, high);
        //cout <<"2recur->" << " low:" << low << " high: "<< high<<endl;
    }
}
 
// Driver Code
int main()
{
    int a;
    cin >>a;
    vector<int> arr(a);
    for (int x = 0; x < a; x++)
    {
        cin >> arr[x];
    }
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    for (auto i : arr)
        cout<<i<<" ";
    return 0;
}