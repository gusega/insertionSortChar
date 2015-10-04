#include<stdio.h>
#include<conio.h>
#include<stddef.h>

struct item {
	int value;
};

int swap(char *a, char *b) {
	int c = *a;
	*a = *b;
	*b = c;
	return 0;
}
int insertion_sort(char *input, int n) {
	int i, j;
    for (i = 1; i < n; i++) {
        // on the first step considering first element of the array to be already trivially sorted
        // single element array
		j=i;
		printArrayS(input, n, i-1); //print array and marks already sorted part of said array
        while ((j>0) && (input[j] < input[j-1])) {
			swap(&input[j], &input[j-1]);
			j = j - 1;
		}
	}
	printArrayS(input, n, i - 1);//finally print fully sorted array
	return 0;
}


int printArrayS(char *array, int size, int n) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%c", array[i]);
		if (i == n) {
            printf("|");
		}
	}
	printf("\n");
	return 0;
}


int printArray(char *array, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%c", array[i]);
	}
	printf("\n");
	return 0;
}
int main() {
	char input[] = "insertionsort";
	size_t size = sizeof input;
	/**size of array in bytes**/
//	size_t singleElementSize = sizeof(char);
	size_t singleElementSize = sizeof(input[0]);
	/** size of the single array element **/
	size_t numberOfElementsInAnArray = size/singleElementSize;
	printf("input: \n");
	printArray(input, numberOfElementsInAnArray);
	printf("\n\n");
	insertion_sort(input, numberOfElementsInAnArray -1);
	// - 1 as we don't need to sort last string termination \0 character
	//printArray(input, numberOfElementsInAnArray);
    getch();
	return 0;
}
