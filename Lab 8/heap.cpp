#include <iostream>
#include <ctime>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
	// build heapify
	int left = (2 * root) + 1; // index of the left child of given root
	int right = (2 * root) + 2; // index of the right child of given root
	int largest = root;
	int temp; // temporary variable for swapping

	if (left < n && arr[root] < arr[left]) // getting the index of maximum between root and the left child
	{
		largest = left;
	}
	if (right < n && arr[largest] < arr[right]) // getting the index of maximum between root and the right child
	{
		largest = right;
	}
	
	if(root != largest){ // heapfy the given tree
		temp = arr[largest];
		arr[largest] = arr[root];
		arr[root] = temp;
		
		heapify(arr, n, largest);
	}
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
	int temp; // temporary variable for swapping

	for(int root = (n-2)/2; root >= 0; root--){ // heapfying all parent elements from the last parent
		heapify(arr, n, root);
	}

	for(int i = n-1; i > 0; i--){ // extracting maximum element and maintaining sorted in the end of the array
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapSort(arr,n-1);
	}
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
	for (int i=0; i<n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}
  
// main program
int main()
{
	int size;
    cout << "Enter Array size: ";
    cin >> size;

    int heap_arr[size];
	
	srand (time(NULL));
    int num;

    for(int i = 0; i < size; i++){
        heap_arr[i] = rand() %200;
	}

	cout<<"Input array"<<endl;
	displayArray(heap_arr,size);

	heapSort(heap_arr, size);

	cout << "Sorted array"<<endl;
	displayArray(heap_arr, size);
}