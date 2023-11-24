#include<stdio.h>

int linearSearch(int *arr, int key, int n)
{
    int index = -1;

    for (int i=0; i<n; ++i)
        if (arr[i]==key)
            index = i;

    return index;
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

    int index = linearSearch(arr, key, size);

    if (index==-1)
        printf("\nKey not found!");
    else
        printf("\nFound at %d index.", index);

return 0;
}