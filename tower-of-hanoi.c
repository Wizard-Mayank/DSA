#include <stdio.h>

void toh(int n, char src, char aux, char dest)
{
    if (n == 1)
    {
        printf("Move from %c to %c.\n", src, dest);
        return;
    }

    toh(n-1, src, dest, aux);
    printf("Move from %c to %c.\n", src, dest);
    toh(n-1, aux, src, dest);
    return;
}

void main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    toh(n, 'A', 'B', 'C');
}