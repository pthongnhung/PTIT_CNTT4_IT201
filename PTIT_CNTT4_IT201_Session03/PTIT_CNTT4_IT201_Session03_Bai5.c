#include<stdio.h>
#include<stdlib.h>
int sumMainDigonal(int **arr,int rows)
{
    int sum=0;
    for(int i=0;i<rows;i++)
    {
            sum+=arr[i][i];
    }
    return sum;
}
int sumAntiDiagonal(int **arr,int rows)
{
    int sum=0;
    for(int i=0;i<rows;i++)
    {
        sum+=arr[i][rows-1-i];
    }
    return sum;
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
    }else if (cols!=rows)
    {
        printf("Khong ton tai duong cheo chinh va duong cheo phu");
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
    printf("Tong duong cheo chinh: %d\n",sumMainDigonal(maxtrix,rows));
    printf("Tong duong cheo phu: %d",sumAntiDiagonal(maxtrix,rows));
    for (int i=0;i<rows;i++)
    {
        free(maxtrix[i]);
    }
    free(maxtrix);
    return 0;
}