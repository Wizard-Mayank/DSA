#include <stdio.h>

int partition(int low, int high, int *arr)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (arr[i] < pivot)
            ++i;

        while (arr[j] > pivot)
            --j;

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;

    return j;
}

void quickSort(int low, int high, int *arr)
{
    int pivotIndex;

    if (low < high)
    {
        pivotIndex = partition(low, high, arr);

        quickSort(low, pivotIndex - 1, arr);
        quickSort(pivotIndex + 1, high, arr);
    }
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

    printf("\nEnter array:\n");

    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    printf("\nArray before sorting: ");
    show(arr, n);

    quickSort(0, n - 1, arr);

    printf("\n\nArray after sorting: ");
    show(arr, n);

    return 0;
}