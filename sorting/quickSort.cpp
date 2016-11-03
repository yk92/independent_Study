#include <iostream>

void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	// partition
	while( i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if ( i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	// recursion
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

int main() {

	int intArray[] = {90, 72, 36, 101, 109, 1, 7, 18, 3, 15, 110};

	std::cout << "\n\nGetting ready to sort array using quick sort alg...\n" 
			  << "Unsorted array: \n\n";

	for (int i = 0 ; i < 10 ; i++){
		std::cout << intArray[i] << " ";
	}

	std::cout << "\nSorted array:\n\n";

	int l = intArray[0];
	int r = intArray[10];
	quickSort(intArray, 0, 10);

	for (int i = 0; i < 10; i++){
		std::cout << intArray[i] << " ";
	}
	std::cout << "\n\n";
}