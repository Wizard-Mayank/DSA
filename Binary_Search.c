#include<stdio.h>

int binarySearch(int *arr, int key, int size)
{
    int lb=0, ub=size-1;

    while(lb<=ub)
    {
        int mid = (lb+ub)/2;

        if (key==arr[mid])
            return mid;
        else if (key<arr[mid])
            ub=mid-1;
        else
            lb=mid+1;
    }

    return -1;
}

int main()
{
    int size;

    printf("Enter size: ");
    scanf("%d", &size);

    int arr[size];

    printf("\nEnter array...\n");

    for (int i=0; i<size; ++i)
    {
        printf("-> ");
        scanf("%d", &arr[i]);
    }
    
    int key;

    printf("\nEnter key to be searched: ");
    scanf("%d", &key);

    int index = binarySearch(arr, key, size);

    if (index==-1)
        printf("\nKey not found!");
    else
        printf("\nFound at %d index.", index);

return 0;
}