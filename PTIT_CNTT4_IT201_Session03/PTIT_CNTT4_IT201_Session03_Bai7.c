#include<stdio.h>
#include<stdlib.h>
int total(int **arr,int k,int cols,int rows)
{
    int sum=0;
    if (k<0 || k>rows)
    {
        printf("So hang khong hop le");
        return 0;
    }
    for (int i=0;i<cols;i++)
    {
       sum+=arr[k][i];
    }
    return sum;
}
int main()
{
    int rows;
    int cols;
    printf("Nhap vao so hang: ");
    scanf("%d",&rows);
    printf("Nhap vao so co cot: ");
    scanf("%d",&cols);
    if (rows<0 || cols<0)
    {
        printf("Khong hop le");
        return 0;
    }else
    {
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
        int k;
        printf("Moi nhap vao  hang can tinh tong: ");
        scanf("%d",&k);
        printf("Tong cua hang %d la: %d",k,total(maxtrix,k,cols,rows));
        for (int i=0;i<rows;i++)
        {
            free(maxtrix[i]);
        }
        free(maxtrix);
        return 0;
    }
}