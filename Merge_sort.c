#include <stdio.h>

void merge(int p, int q, int r, int *arr)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int left[n1], right[n2];

    for (int i = 0; i < n1; ++i)
        left[i] = arr[p + i];
    for (int i = 0; i < n2; ++i)
        right[i] = arr[q + 1 + i];

    int i = 0, j = 0;
    int k=p;

    while(i<n1 && j<n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            ++i;
        }

        else
        {
            arr[k] = right[j];
            ++j;
        }

        ++k;
    }

    while(i<n1)
        arr[k++]=left[i++];
    while(j<n2)
        arr[k++]=right[j++];
}

void mergeSort(int low, int high, int *arr)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(low, mid, arr);
        mergeSort(mid + 1, high, arr);

        merge(low, mid, high, arr);
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

    mergeSort(0, n - 1, arr);

    printf("\n\nArray after sorting: ");
    show(arr, n);

    return 0;
}