#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void freq(int arr2[],int len)
{
   int count=0,count_digit=0;
   int *digit_num;
   digit_num=malloc(len*sizeof(int));
   for(int i=0;i<len;i++)
   {
       count=0;
       int l=arr2[i];
       while(l>0)
       {
           l/=10;
           count++;
       }
//array to get largest num of digits in array .
       digit_num[i]=count;
       if(count>count_digit)
        count_digit=count+1;
   }


   int new_element;
   //handling numbers to get equel digits.
   for(int i=0;i<len;i++)
   {
    new_element=arr2[i];
    int count_new=digit_num[i];
    while(count_new<count_digit)
    {
        new_element=new_element*pow(10,digit_num[i])+arr2[i];
        count_new=0;
        int new_element_1=new_element;
        while(new_element_1>0)
        {
            new_element_1/=10;
            count_new++;
        }
    }
    while(count_new>count_digit)
    {
        new_element/=10;
        count_new--;
    }
    arr2[i]=new_element;
   }

}


/*##########################################################################################################*/

// Merge sort in C

#include <stdio.h>

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}




/*##########################################################################################################*/
// main function
int main() {

     int i,size,element;
    scanf("%d",&size);
     int arr[size],arr2[size];


    for(i=0;i<size;i++){

       scanf("%d",&element);
       arr[i]=element;
       arr2[i]=element;
    }

    freq(arr2,size);


   int arr3[size];
   for(int g=0;g<size;g++)
   {
      arr3[g]=arr2[g];
   }
  quickSort(arr3, 0, size - 1);

  for(int i=size-1;i>=0;i--)
  {
      element=arr3[i];
      for(int j=0;j<size;j++)
      {
          if(arr2[j]==element)
          {
              printf("%d",arr[j]);
              break;
          }
      }
  }

  int size = sizeof(arr2) / sizeof(arr2[0]);
  mergeSort(arr2, 0, size - 1);

  printf("Sorted array: \n");
  printArray(arr2, size);




  return 0;
}
