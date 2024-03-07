#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

typedef struct {
    int data;
    int numSwaps;
    int totalSwaps;
} element;

element* bubbleSort(int* arr);
element* selectionSort(int* arr);
void printArr(element* arr);

int main(void) {
    int arrOne[SIZE] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 };
    int arrTwo[SIZE] = { 90, 80, 70, 60, 50, 40, 30, 20, 10 };

    element* bubbleArrOne = bubbleSort(arrOne);
    element* bubbleArrTwo = bubbleSort(arrTwo);
    element* selectionArrOne = selectionSort(arrOne);
    element* selectionArrTwo = selectionSort(arrTwo);

    printf("array1 bubble sort:\n");
    printArr(bubbleArrOne);
    printf("array2 bubble sort:\n");
    printArr(bubbleArrTwo);
    printf("array1 selection sort:\n");
    printArr(selectionArrOne);
    printf("array2 selection sort:\n");
    printArr(selectionArrTwo);

    free(bubbleArrOne);
    free(bubbleArrTwo);
    free(selectionArrOne);
    free(selectionArrTwo);
}

void printArr(element* arr) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: %d\n", arr[i].data, arr[i].numSwaps);
    }
    printf("%d\n\n", arr[0].totalSwaps);
}

element* selectionSort(int* arr) {
    element* swaps = malloc(sizeof(element) * SIZE);
    if (swaps == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    for (int i = 0; i < SIZE; i++) {
        swaps[i].data = arr[i];
        swaps[i].numSwaps = 0;
        swaps[i].totalSwaps = 0;
    }

    for (int i = 0; i < SIZE - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (swaps[j].data < swaps[minIndex].data) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = swaps[i].data;
            swaps[i].data = swaps[minIndex].data;
            swaps[minIndex].data = temp;

            int temp2 = swaps[i].numSwaps;
            swaps[i].numSwaps = swaps[minIndex].numSwaps;
            swaps[minIndex].numSwaps = temp2;

            swaps[i].numSwaps++;
            swaps[minIndex].numSwaps++;
            swaps[0].totalSwaps++;
        }
    }
    return swaps;
}

element* bubbleSort(int* arr) {
    element* swaps = malloc(sizeof(element) * SIZE);
    if (swaps == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    for (int i = 0; i < SIZE; i++) {
        swaps[i].data = arr[i];
        swaps[i].numSwaps = 0;
        swaps[i].totalSwaps = 0;
    }

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (swaps[j].data > swaps[j + 1].data) {
                int temp = swaps[j].data;
                swaps[j].data = swaps[j + 1].data;
                swaps[j + 1].data = temp;
                
                int temp2 = swaps[j].numSwaps;
                swaps[j].numSwaps = swaps[j + 1].numSwaps;
                swaps[j + 1].numSwaps = temp2;

                swaps[j].numSwaps++;
                swaps[j + 1].numSwaps++;
                swaps[0].totalSwaps++;
            }
        }
    }
    return swaps;
}