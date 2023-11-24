#include<stdio.h>

void insertionSort(int n)
{
    int i, j, arr[n], v;

    printf("\nENTER ARRAY: \n");

    for (i=0; i<n; ++i)
    {
        printf("Enter: ");
        scanf("%d", &arr[i]);
    }

    printf("\nEntered array: ");
    
    for (i=0; i<n; ++i)
        printf("%d ", arr[i]);

    printf("\n");

    for(int i=1; i<n; ++i)
    {
        int j=i-1;
        int key = arr[i];

        while (key<=arr[j] && j>=0)
        {
            arr[j+1] = arr[j];
            --j;
        }

        arr[j+1] = key;
    }

    printf("\nArray after sorting: ");
    
    for (i=0; i<n; ++i)
        printf("%d ", arr[i]);
}

void main()
{
    int l;

    printf("Enter length of array: ");
    scanf("%d", &l);

    insertionSort(l);
}