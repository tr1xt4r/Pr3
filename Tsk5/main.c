#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_COORDINATE 10.0
#define MAX_MASS 10.0

typedef struct {
    double x, y, z;
    double mass;
} Point;

// Function prototypes
double calculateDistance(Point p1, Point p2);
void initializePoints(Point* points, int n);
void printPoints(Point* points, int n);
int findMinMassIndex(Point* points, int n);
int findNearestPoint(Point* points, int n, int excludeIndex);

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a valid number of points.\n");
        return 1;
    }

    Point* points = malloc(n * sizeof(Point));
    if (points == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    initializePoints(points, n);

    while (n > 1) {
        printf("------------------------------------------------\n");
        printPoints(points, n);

        int minIndex = findMinMassIndex(points, n);
        int nearestIndex = findNearestPoint(points, n, minIndex);

        points[nearestIndex].mass += points[minIndex].mass;
        printf("Point %d transfers its mass to point %d\n", minIndex, nearestIndex);
        points[minIndex] = points[n - 1];
        n--;
    }

    printf("------------------------------------------------\n");
    printf("The remaining point has coordinates (X = %.2f, Y = %.2f, Z = %.2f) and weight %.2f\n",
           points[0].x, points[0].y, points[0].z, points[0].mass);

    free(points);

    return 0;
}

// Function to calculate the distance between two points
double calculateDistance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

// Function to initialize an array of points with random values
void initializePoints(Point* points, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        points[i].x = (double)rand() / RAND_MAX * MAX_COORDINATE;
        points[i].y = (double)rand() / RAND_MAX * MAX_COORDINATE;
        points[i].z = (double)rand() / RAND_MAX * MAX_COORDINATE;
        points[i].mass = (double)rand() / RAND_MAX * MAX_MASS;
    }
}

// Function to print the state of points
void printPoints(Point* points, int n) {
    printf("Current state of points:\n");
    for (int i = 0; i < n; i++) {
        printf("Point %d: (X = %.2f, Y = %.2f, Z = %.2f) Weight = %.2f\n",
               i, points[i].x, points[i].y, points[i].z, points[i].mass);
    }
}

// Function to find the index of the point with the minimum mass
int findMinMassIndex(Point* points, int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].mass < points[minIndex].mass) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to find the index of the nearest point to a given point, excluding a specific index
int findNearestPoint(Point* points, int n, int excludeIndex) {
    double minDistance = -1.0;
    int nearestIndex = -1;
    for (int i = 0; i < n; i++) {
        if (i != excludeIndex) {
            double dist = calculateDistance(points[excludeIndex], points[i]);
            if (minDistance < 0 || dist < minDistance) {
                minDistance = dist;
                nearestIndex = i;
            }
        }
    }
    return nearestIndex;
}
