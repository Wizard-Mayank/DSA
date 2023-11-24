#include<stdio.h>

void bsort(int n)
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

    for (i=0; i<n; ++i)
    {
        for (j=0; j<(n-i); ++j)
        {
            if (arr[j]>arr[j+1])
            {
                v=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=v;
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

    bsort(l);
}