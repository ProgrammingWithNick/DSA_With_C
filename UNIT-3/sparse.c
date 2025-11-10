#include <stdio.h>

void main()
{
    int a[10][10], i, j, rows, cols, count = 0;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &a[i][j]);
            if(a[i][j] == 0)
                count++;
        }
    }

    if(count > (rows * cols) / 2)
        printf("Matrix is Sparse.\n");
    else
        printf("Matrix is Not Sparse.\n");

}
