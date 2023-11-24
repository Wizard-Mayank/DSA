#include<stdio.h>

void selectionSort(int n)
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

    for(i=0; i<n-1; ++i)
    {
        for (j=i+1; j<n; ++j)
        {
            if (arr[i]>arr[j])
            {
                v=arr[i];
                arr[i]=arr[j];
                arr[j]=v;
            }
        }
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

    selectionSort(l);
}