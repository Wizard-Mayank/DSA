#include <stdio.h>
#include <math.h>

int countSort(int *arr, int size, int range)
{
    int count[range + 1], output[size];

    for (int i = 0; i < range + 1; ++i)
        count[i] = 0;

    for (int i = 0; i < size; ++i)
        count[arr[i]]++;

    for (int i = 1; i < range + 1; ++i)
        count[i] += count[i - 1];

    for (int i = 0; i < size; ++i)
    {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    for (int i = 0; i < size; ++i)
        arr[i] = output[i];
}

void show(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}

int main()
{
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    double max = -INFINITY;

    printf("\nEnter array:\n");

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);

        if (arr[i] > max)
            max = arr[i];
    }

    printf("\nArray before sorting: ");
    show(arr, n);

    countSort(arr, n, max);

    printf("\n\nArray after sorting: ");
    show(arr, n);

    return 0;
}