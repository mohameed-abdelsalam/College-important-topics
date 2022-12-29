// Shell Sort in C programming

#include <stdio.h>

// Shell sort
void shellSort(int array[], int n)
{
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int interval = n / 2; interval > 0; interval /= 2)
  {
    for (int i = interval; i < n; i += 1)
    {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
       {
          array[j] = array[j - interval];
       }
      array[j] = temp;
    }
  }
}

// Driver code
int main() {
    int n,k;
    scanf("%d" , &n);
    scanf("%d",&k);

    int arr[n] ;
    for(int i = 0; i < n ; i++)
       {
        scanf("%d" , &arr[i]);
       }

  shellSort(arr, n);
  printf("%d",arr[n-k]);
}
