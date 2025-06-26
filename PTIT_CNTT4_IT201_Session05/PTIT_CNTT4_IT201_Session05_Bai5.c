#include <ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isPalindromeRecursive(char *str,int left,int right){
    while(left<right && !isalpha(str[left])){
        left++;
    }
    while(left<right && !isalpha(str[right])){
        right --;
    }
    if (left>=right)
    {
        return 1;
    }
    if (tolower(str[left]) != tolower(str[right]))
    {
        return 0;
    }
    return isPalindromeRecursive(str,left+1,right-1);
}
int main()
{
    char str[1000];
    printf("Nhap chuoi ki tu: ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    if (isPalindromeRecursive(str,0,strlen(str)-1))
    {
        printf("Palindrome valid");
    }else
    {
        printf("Palindrome invalid");
    }
    return 0;
}