#include<stdio.h>
#include<stdlib.h>
int maxNum(int **arr,int rows,int cols)
{
    int max=arr[0][0];
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            if (max<arr[i][j])
            {
                max=arr[i][j];
            }
        }
    }
    return max;
}
int minNum(int **arr,int rows,int cols)
{
    int min=arr[0][0];
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            if (min>arr[i][j])
            {
                min=arr[i][j];
            }
        }
    }
    return min;
}
int main()
{
    int rows;
    int cols;
    printf("Nhap so hang: ");
    scanf("%d",&rows);
    printf("Nhap so cot: ");
    scanf("%d",&cols);
    if (rows<0 || rows>1000)
    {
        printf("So hang khong hop le");
        return 0;
    }else if (cols<0 || cols>1000)
    {
        printf("So cot khong hop le");
        return 0;
    }else if (rows==0 &&cols==0)
    {
        printf("so hang va so cot khong hop le");
        return 0;
    }
    int **maxtrix=(int**)malloc(rows*sizeof(int*));
    for (int i=0;i<rows;i++)
    {
        maxtrix[i]=(int*)malloc(cols*sizeof(int));
    }
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            printf("maxtrix[%d][%d]= ",i,j);
            scanf("%d",&maxtrix[i][j]);
        }
    }
    printf("Max=%d\t",maxNum(maxtrix,rows,cols));
    printf("Min=%d",minNum(maxtrix,rows,cols));
    for (int i=0;i<rows;i++)
    {
        free(maxtrix[i]);
    }
    free(maxtrix);
    return 0;
}