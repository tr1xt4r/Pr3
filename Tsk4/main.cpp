#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to generate random values between -50.0 and 50.0
double generateRandomValue() {
    return ((rand() % 10001) / 100.0) - 50.0;
}

// Function to print an array
void printArray(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", arr[i]);
    }
    printf("\n");
}

// Function to calculate the average of an array
double calculateAverage(double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Function to count elements greater than the average
int countElementsGreaterThanAverage(double arr[], int n, double average) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > average) {
            count++;
        }
    }
    return count;
}

// Function to calculate the sum of absolute values after the first negative element
double sumAbsoluteValuesAfterNegative(double arr[], int n) {
    int negative_found = 0;
    double sum_after_negative = 0;

    for (int i = 0; i < n; i++) {
        if (!negative_found && arr[i] < 0) {
            negative_found = 1;
        }

        if (negative_found) {
            sum_after_negative += fabs(arr[i]);
        }
    }
    return sum_after_negative;
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    double arr[n];
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i] = generateRandomValue();
    }

    printf("Array: ");
    printArray(arr, n);

    double average = calculateAverage(arr, n);
    int count = countElementsGreaterThanAverage(arr, n, average);
    double sum_after_negative = sumAbsoluteValuesAfterNegative(arr, n);

    printf("Number of elements greater than the average: %d\n", count);
    printf("Sum of absolute values after the first negative element: %.2lf\n", sum_after_negative);

    return 0;
}
