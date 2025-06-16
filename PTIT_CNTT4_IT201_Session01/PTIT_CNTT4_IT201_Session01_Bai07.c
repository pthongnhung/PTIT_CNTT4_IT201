// #include <stdio.h>
//  cach 1: sap xep theo 2 vi tri lien ke
// bool hasDuplicateBruteForce(int ar,int n)
//  {
//   for (int i=0;i<n;i++)
//   {
//    for (int j=i+1;j<n-1;j++)
//    {
//     if (arr[i]==arr[j])
//     {
//      return true;
//     }
//    }
//   }
//   return false;
//  }
// Độ phức tạp thời gian O(n2)
// Độ phức tạp không gian 0(1)
//
// Cach 2: tao 2 mang
// bool hasDuplicateCounting(int arr, int n)
//  {
//   int count[1001]={0};
//   for (int i=0;i<n;i++)
//   {
//    if (count[arr[i]]>0)
//    {
//     return true;
//    }
//    count[arr[i]]++;
//   }
//   return false;
//  }
// Độ phức tạp thời gian: O(n)
// Độ phức tạp không gian: O(1)