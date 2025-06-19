#include <stdio.h>

int countOccurences(int arr[],int n,int target)
{
    int count=0;
    for (int i=0;i<n;i++)
    {
        if (arr[i]==target)
        {
            count++;
        }
    }
    return count;

}
// DPTTG O(n)
// DPTKG O(1)
int main()
{
    int arr[5]={1,1,3,4,4,5};
    int x=countOccurences(arr,5,1);
    printf("%d",x);
    return 0;
}