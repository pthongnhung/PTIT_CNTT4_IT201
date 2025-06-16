// #include <stdio.h>
//  int findMax(int arr, int n)
//  {
//      int count [1001]={0};
//      for (int i=0;i<n;i++)
//      {
//          count[arr[i]]++;
//      }
//      int itemMax=count[0];
//      for (int i=0;i<1000;i++)
//      {
//          if (itemMax<count[i])
//          {
//              itemMax=count[i];
//          }
//      }
//      return itemMax;
//  }
// Đôj phức tạp thời gian O(n)
// Đôj phức tạp không gian O(1)