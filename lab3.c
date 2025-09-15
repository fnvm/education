#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define S 10

void bubbleSort(int arr[]) {
    for (int i = 0; i < S - 1; i++) {
        for (int j = 0; j < S - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int arr[S];
    srand(time(NULL));

    for (int i = 0; i < S; i++) {
        arr[i] = rand() % 100;
    }

    bubbleSort(arr);

    printf("Исходный массив: ");
    for (int i = 0; i < S; i++) {
        	printf("%d ", arr[i]);
        }
    printf("\n");

    int sum = arr[0] + arr[S - 1];
    arr[S - 1] = sum;

    printf("Массив с заменой: ");
    for (int i = 0; i < S; i++) {
    	printf("%d ", arr[i]);
    }

    return 0;
}
