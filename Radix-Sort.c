#include <stdio.h>
#include <math.h>

double getMax(int *arr, int size)
{
    double max = -INFINITY;

    for (int i = 0; i < size; ++i)
        if (max < arr[i])
            max = arr[i];

    return max;
}

void countSort(int *nums, int size, int pos)
{
    int count[10] = {0};
    int output[size];

    for (int i = 0; i < size; ++i)
        ++count[(nums[i]/pos)%10];
    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];
    for (int i = size-1; i >= 0; --i)
        output[--count[(nums[i]/pos)%10]] = nums[i];
    for (int i = 0; i < size; ++i)
        nums[i] = output[i];
}

void radixSort(int *nums, int size)
{
    double max = getMax(nums, size);

    for (int pos = 1; max / pos > 0; pos *= 10)
        countSort(nums, size, pos);
}

void show(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}

int main()
{

    int size;

    printf("Enter size: ");
    scanf("%d", &size);

    int nums[size];

    printf("\nEnter array\n");

    for (int i = 0; i < size; ++i)
    {
        printf("--> ");
        scanf("%d", &nums[i]);
    }

    printf("\n\nArray before sorting: ");
    show(nums, size);

    radixSort(nums, size);

    printf("\n\nArray after sorting: ");
    show(nums, size);
    return 0;
}