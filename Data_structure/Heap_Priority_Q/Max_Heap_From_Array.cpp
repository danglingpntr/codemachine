/*  Create MAX heap, sort operation will perform to create asending order sorting and vice versa*/
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    if (l < n && arr[l] > arr[largest]) // If left child is larger than root (> max heap && < for min heap)
        largest = l;

    if (r < n && arr[r] > arr[largest]) // If right child is larger than largest so far  (> max heap && < for min heap)
        largest = r;

    if (largest != i) // If largest is not root
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}

void buildHeap(int arr[], int n)
{
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = startIdx; i >= 0; i--)
        heapify(arr, n, i);

/*------------------------------------------CODE FOR SORTING ---------------*/
    //One by one extract an element from heap 
	for (int i = n - 1; i > 0; i--) 
    {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
/*--------------------------------------------------------------------------*/ 
} 

void printHeap(int arr[], int n)
{ 
    cout << "Array representation of Heap is:\n";

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver Code
int main()
{
    int arr[] = {1, 9, 5, 8, 6, 13, 10, 3, 4, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    buildHeap(arr, n);

    printHeap(arr, n);
    return 0;
}

// Binary Tree Representation
// of input array
//              1
//           /     \
//         9         5
//      /    \     /  \
//     8      6   13  10
//    / \    / \
//   3   4  15 17

// Final Heap:
//              17
//           /      \
//         15         13
//       /    \      /  \
//      9      6    5   10
//     / \    /  \
//    4   8  3    1