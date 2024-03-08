#include <stdio.h>

typedef struct element {

	int data;
	int num_swaps;

} element;


element* copyArray(int arr[], int n) {

	element* swaps = (element*)malloc(sizeof(element) * n);

	for (int i = 0; i < n; i++) {

		swaps[i].data = arr[i];
		swaps[i].num_swaps = 0;

	}

	return swaps;

}


void swap(element* left, element* right) {

	element temp = *left;
	*left = *right;
	*right = temp;

	left->num_swaps++;
	right->num_swaps++;

}


void bubbleSort(element arr[], int n) {

	for (int i = 0; i < n - 1; i++) {

		for (int j = 0; j < n - i - 1; j++) {

			if (arr[j].data > arr[j + 1].data) {

				swap(&arr[j], &arr[j + 1]);

			}

		}

	}

}


void selectSort(element arr[], int n) {

	int min;

	for (int i = 0; i < n - 1; i++) {

		min = i;

		for (int j = i + 1; j < n; j++) {

			if (arr[j].data < arr[min].data) {

				min = j;

			}

		}
		if (min != i){
            swap(&arr[min], &arr[i]);
        }

	}

}

void numOfSwaps(element newArray[], int n) {

	int total_swaps = 0;

	for (int i = 0; i < n; i++) {

		printf("%d : %d\n", newArray[i].data, newArray[i].num_swaps);
		total_swaps += newArray[i].num_swaps;

	}

	printf("Total number of swaps: %d\n", (total_swaps / 2));

}


int main(void) {

	int arr1[] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 };

	int size1 = 9;

	int arr2[] = { 90, 80, 70, 60, 50, 40, 30, 20, 10 };

	int size2 = 9;

	element* nArray1 = copyArray(arr1, size1);

	element* nArray2 = copyArray(arr2, size2);


	bubbleSort(nArray1, size1);
	printf("array 1 bubble sort:\n");
	numOfSwaps(nArray1, size1);

    puts(" ");

	bubbleSort(nArray2, size2);
	printf("array 2 bubble sort:\n");
	numOfSwaps(nArray2, size2);


	free(nArray1);
	free(nArray2);


	nArray1 = copyArray(arr1, size1);

	nArray2 = copyArray(arr2, size2);

    puts(" ");

	selectSort(nArray1, size1);
	printf("array 1 selection sort:\n");
	numOfSwaps(nArray1, size1);

    puts(" ");
    
	selectSort(nArray2, size2);
	printf("array 2 selection sort:\n");
	numOfSwaps(nArray2, size2);


	free(nArray1);
	free(nArray2);


	return 0;

}